#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <mpi.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "factory.h"

const int WORKERS_INDEXES[WORKERS_INDEXES_LENGTH] = { MANAGER_PORT, WORKER1_PORT, WORKER2_PORT, WORKER3_PORT, WORKER4_PORT, WORKER5_PORT, WORKER6_PORT, WORKER7_PORT, WORKER8_PORT };

void throw_error(const char *msg) {
  perror(msg);
  exit(1);
}

void clear_buffer(void *buffer, const size_t buffer_size) {
  memset(buffer, 0, buffer_size);
}

int get_steps_length(const int processes_length) {
  return log2(processes_length);
}

char *get_timestamp() {
  char *timestamp = (char *)malloc(sizeof(char) * MAX_BUFFER_SIZE);

  struct timeval timestamp_tv;
  gettimeofday(&timestamp_tv, NULL);

  snprintf(timestamp, MAX_BUFFER_SIZE - 1, "%ld.%06ld", timestamp_tv.tv_sec, timestamp_tv.tv_usec);

  return timestamp;
}

void report_info(const char *msg, const int worker_id) {
  char *timestamp = get_timestamp();
  printf("[%s](%d) INFO: %s\n", timestamp, worker_id, msg);
  free(timestamp);
  timestamp = NULL;
}

void report_connection(const int worker_id, const int pair_id, const int pair_port) {
  char *timestamp = get_timestamp();
  printf("[%s](%d) INFO: Connected to %d through port %d\n", timestamp, worker_id, pair_id, pair_port);
  free(timestamp);
  timestamp = NULL;
}

void report_connection_closed(const int worker_id, const int pair_id, const int pair_port) {
  char *timestamp = get_timestamp();
  printf("[%s](%d) CLOSING: Closing connection to %d through port %d\n", timestamp, worker_id, pair_id, pair_port);
  free(timestamp);
  timestamp = NULL;
}

void report_connection_accepted(const int worker_id, const int pair_port) {
  char *timestamp = get_timestamp();
  printf("[%s](%d) INFO: Connected to someone in port %d\n", timestamp, worker_id, pair_port);
  free(timestamp);
  timestamp = NULL;
}

void report_readiness(const int worker_id, const int port) {
  MPI_Barrier(MPI_COMM_WORLD);

  char *timestamp = get_timestamp();
  printf("[%s](%d) INFO: Worker %d is ready at port %d\n", timestamp, worker_id, worker_id, port);
  free(timestamp);
  timestamp = NULL;
}

void report_production(const int worker_id, const int produced, const int port) {
  char *timestamp = get_timestamp();
  printf("[%s](%d) PRODUCED: Worker %d produced %d at port %d\n", timestamp, worker_id, worker_id, produced, port);
  free(timestamp);
  timestamp = NULL;
}

void report_consumption(const int consumer_id, const int consumed, const int producer_id, const int producer_port) {
  char *timestamp = get_timestamp();
  printf("[%s](%d) CONSUMED: Worker %d consumed %d from %d (port %d)\n", timestamp, consumer_id, consumer_id, consumed, producer_id, producer_port);
  free(timestamp);
  timestamp = NULL;
}

int get_socket(const Boolean reusable) {
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    throw_error("Error when creating socket");
  }

  if (reusable) {
    int opt = TRUE;

    int reusable_address_status = setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (reusable_address_status < 0) {
      throw_error("Error on setting reusable address option to socket");
    }
  }

  return socket_fd;
}

sockaddr_in_t *get_address_for_port(const int port) {
  sockaddr_in_t *socket_address = (sockaddr_in_t *)malloc(sizeof(sockaddr_in_t));
  if (!socket_address) {
    throw_error("Error when allocating memory for socket address");
  }

  clear_buffer(socket_address, sizeof(*socket_address));
  socket_address->sin_family = AF_INET;
  socket_address->sin_addr.s_addr = inet_addr(COMMON_HOSTNAME);
  socket_address->sin_port = htons(port);

  if (DEBUG) {
    printf("Getting address for port %d (%d)\n", port, ntohs(socket_address->sin_port));
  }

  return socket_address;
}

void bind_socket(const int socket_fd, sockaddr_in_t *socket_address) {
  if (DEBUG) {
    printf("Trying to bind to port %d\n", ntohs(socket_address->sin_port));
  }

  int bind_status = bind(socket_fd, (struct sockaddr *)socket_address, sizeof(*socket_address));
  if (bind_status < 0) {
    free(socket_address);
    close_socket(socket_fd);
    throw_error("Error when binding socket");
  }
}

void listen_socket(const int socket_fd) {
  int listen_status = listen(socket_fd, MAX_SIMULTANEOUS_CONNECTIONS);
  if (listen_status < 0) {
    close_socket(socket_fd);
    throw_error("Error when listening on socket");
  }
}

int accept_socket(const int socket_fd, sockaddr_in_t *client_address) {
  socklen_t client_length = sizeof(*client_address);
  int new_socket_fd = accept(socket_fd, (struct sockaddr *)client_address, &client_length);
  if (new_socket_fd < 0) {
    close_socket(socket_fd);
    throw_error("Error when accepting connection");
  }

  if (DEBUG) {
    printf("Accepting connection from %d\n", ntohs(client_address->sin_port));
  }

  return new_socket_fd;
}

char *retrieve_worker_address_from_port(const int port) {
  struct hostent *worker = gethostbyname(COMMON_HOSTNAME);
  if (worker == NULL) {
    throw_error("Error when retrieving worker");
  }

  return worker->h_addr_list[0];
}

int connect_to_port(const int socket_fd, const int connection_port) {
  sockaddr_in_t *target_address = get_address_for_port(connection_port);

  int connect_status = connect(socket_fd, (struct sockaddr *)target_address, sizeof(*target_address));
  if (connect_status < 0) {
    close_socket(socket_fd);

    if (DEBUG) {
      printf("Trying to connect to port %d", connection_port);
    }

    throw_error("Error when connecting to server");
  }

  free(target_address);
  target_address = NULL;
}

void send_exit_signal(const int socket_fd) {
  int write_status = write(socket_fd, "exit", 4);
  if (write_status < 0) {
    close_socket(socket_fd);
    throw_error("Error when writing to socket");
  }
}

void wait_for_exit_signal(const int socket_fd) {
  char buffer[MAX_BUFFER_SIZE];
  while (TRUE) {
    clear_buffer(buffer, sizeof(buffer));

    int read_status = read(socket_fd, buffer, sizeof(buffer) - 1);
    if (read_status < 0) {
      close_socket(socket_fd);
      throw_error("Error when reading from socket");
    }

    if (strcmp(buffer, "exit") == 0) {
      break;
    }
  }
}

int get_worker_id_by_port(const int port) {
  int i;
  for (i = 1; i < WORKERS_INDEXES_LENGTH; i++) {
    if (WORKERS_INDEXES[i] == port) {
      return i;
    }
  }
  return -1;
}

int get_manager_id(const int worker_id, const int step) {
  int pace = pow(2, step);
  int maybe_manager_id = worker_id - pace;
  return maybe_manager_id > MANAGER_ID ? maybe_manager_id : MANAGER_ID;
}

int process_should_send_to_manager(const int worker_id, const int step) {
  if (step == 0) {
    return FALSE;
  }

  return (worker_id / (int)pow(2, step)) % 2 == 1;
}

int accumulate(const int current, const int value, const AccumulatingOperations op) {
  switch (op) {
    case ADD: {
      return current + value;
    }

    case SUB: {
      return current - value;
    }

    case MULT: {
      return current * value;
    }

    case DIV: {
      if (value == 0) {
        throw_error("Error on accumulating (can't divide by zero)");
      }

      return current / value;
    }

    default: {
      return current;
    }
  }
}

void close_socket(const int socket_fd) {
  int close_status = close(socket_fd);
  int shutdown_status = 0;

  if (close_status < 0) {
    shutdown_status = shutdown(socket_fd, SHUT_RDWR);
    if (shutdown_status < 0) {
      throw_error("Error when shutting down socket");
    }

    close_status = close(socket_fd);
    if (close_status < 0) {
      throw_error("Error when closing socket");
    }
  }
}

void send_value_to_port_and_exit(int produced, const int socket_fd, const int sender_id, const int destination_id, const int destination_port) {
  if (DEBUG) {
    printf("%d is trying to send %d to worker %d at port %d\n", sender_id, produced, destination_id, destination_port);
  }

  connect_to_port(socket_fd, destination_port);
  report_connection(sender_id, destination_id, destination_port);

  int write_status = write(socket_fd, &produced, sizeof(produced));
  if (write_status < 0) {
    close_socket(socket_fd);
    throw_error("Error when writing to socket");
  }

  wait_for_exit_signal(socket_fd);

  close_socket(socket_fd);
  report_info("Received exit signal, closing connection...", sender_id);
}

void build_only_producer_worker(const int worker_id, const int worker_port, const int destination_id, const int destination_port) {
  int socket_fd = get_socket(FALSE);
  sockaddr_in_t *socket_address = get_address_for_port(worker_port);
  bind_socket(socket_fd, socket_address);

  report_readiness(worker_id, worker_port);

  srand(time(NULL) + worker_id);

  int produced = DEBUG ? worker_id : rand() % 1000;
  report_production(worker_id, produced, worker_port);

  send_value_to_port_and_exit(
    produced,
    socket_fd,
    worker_id,
    destination_id,
    destination_port
  );
}

void build_receiver_sender_worker(const int worker_id, const int worker_port, const int processes_length, const AccumulatingOperations op) {
  int listening_socket_fd = get_socket(TRUE);
  sockaddr_in_t *socket_address = get_address_for_port(worker_port);
  bind_socket(listening_socket_fd, socket_address);
  listen_socket(listening_socket_fd);

  report_readiness(worker_id, worker_port);

  srand(time(NULL) + worker_id);
  int consumed;
  int produced = DEBUG ? worker_id : rand() % 1000;
  int step = 0;
  int max_steps = get_steps_length(processes_length);

  report_production(worker_id, produced, worker_port);

  int accepted_socket_fd, read_status, client_id, client_port, should_send_to_manager = FALSE;
  sockaddr_in_t client_address;

  while (TRUE) {
    should_send_to_manager = (worker_id == WORKER_MANAGER_ID ? max_steps : max_steps - 1) == step ? TRUE : process_should_send_to_manager(worker_id, step);
    if (should_send_to_manager) {
      break;
    }

    clear_buffer(&client_address, sizeof(client_address));
    accepted_socket_fd = accept_socket(listening_socket_fd, &client_address);

    client_port = ntohs(client_address.sin_port);
    client_id = get_worker_id_by_port(client_port);

    if (client_id < 0) {
      close_socket(listening_socket_fd);
      close_socket(accepted_socket_fd);
      throw_error("Error on getting client_id");
    }

    report_connection_accepted(worker_id, client_port);

    read_status = read(accepted_socket_fd, &consumed, sizeof(consumed));
    if (read_status < 0) {
      close_socket(listening_socket_fd);
      close_socket(accepted_socket_fd);
      throw_error("Error when reading from socket");
    }

    report_consumption(worker_id, consumed, client_id, client_port);

    send_exit_signal(accepted_socket_fd);
    close_socket(accepted_socket_fd);
    report_connection_closed(worker_id, client_id, client_port);

    produced = accumulate(produced, consumed, op);
    step++;
  }

  report_info("All values received, sending to manager and closing listener socket...", worker_id);
  close_socket(listening_socket_fd);

  int my_manager_id = get_manager_id(worker_id, step);
  int my_manager_port = WORKERS_INDEXES[my_manager_id];

  int sending_socket_fd = get_socket(TRUE);
  bind_socket(sending_socket_fd, socket_address);

  send_value_to_port_and_exit(
    produced,
    sending_socket_fd,
    worker_id,
    my_manager_id,
    my_manager_port
  );
}

void build_manager_socket(const int worker_id, const int worker_port) {
  int socket_fd = get_socket(FALSE);
  sockaddr_in_t *socket_address = get_address_for_port(worker_port);
  bind_socket(socket_fd, socket_address);
  listen_socket(socket_fd);

  report_readiness(worker_id, worker_port);

  int accepted_socket_fd, read_status, client_id, client_port, consumed;
  sockaddr_in_t client_address;

  accepted_socket_fd = accept_socket(socket_fd, &client_address);

  client_port = ntohs(client_address.sin_port);
  client_id = get_worker_id_by_port(client_port);

  if (client_id < 0) {
    close_socket(socket_fd);
    close_socket(accepted_socket_fd);
    throw_error("Error on getting client_id");
  }

  report_connection_accepted(worker_id, client_port);

  read_status = read(accepted_socket_fd, &consumed, sizeof(consumed));
  if (read_status < 0) {
    close_socket(socket_fd);
    close_socket(accepted_socket_fd);
    throw_error("Error when reading from socket");
  }

  report_consumption(worker_id, consumed, client_id, client_port);

  send_exit_signal(accepted_socket_fd);
  close_socket(accepted_socket_fd);
  report_connection_closed(worker_id, client_id, client_port);

  report_info("All values received. Closing listener socket...", worker_id);
  close_socket(socket_fd);

  char *timestamp = get_timestamp();
  printf("[%s](%d) ANNOUNCEMENT: Manager consumed accumulated value %d from workers sent by %d (at port %d)\n",
    timestamp,
    worker_id,
    consumed,
    client_id,
    client_port
  );

  free(timestamp);
  timestamp = NULL;
}
