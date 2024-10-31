#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_SIMULTANEOUS_CONNECTIONS 5
#define MAX_BUFFER_SIZE 256
#define PORT_MANAGER 8080

void throw_error(const char *msg) {
  perror(msg);
  exit(1);
}

void clear_buffer(void *buffer, size_t bytes) {
  memset(buffer, 0, bytes);
}

void read_cli_str(char *buffer, size_t buffer_size) {
  fgets(buffer, buffer_size - 1, stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
}

int main(int argc, char *argv[]) {
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    throw_error("Error opening socket");
  }

  struct sockaddr_in server_address, client_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT_MANAGER);

  int bind_status = bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
  if (bind_status < 0) {
    throw_error("Error on binding");
  }

  int listen_status = listen(socket_fd, MAX_SIMULTANEOUS_CONNECTIONS);
  if (listen_status < 0) {
    throw_error("Error on listening");
  }

  printf("INIT: Listening on port %d! Waiting for connection...\n", PORT_MANAGER);

  socklen_t client_length = sizeof(client_address);

  int new_socket_fd = accept(socket_fd, (struct sockaddr *)&client_address, &client_length);
  if (new_socket_fd < 0) {
    throw_error("Error on accepting the connection");
  }

  printf("INFO: Connection accepted!\n");

  int read_status, write_status;
  char buffer[MAX_BUFFER_SIZE];

  printf("--- Starting conversation ---\n");
  while (1) {
    clear_buffer((void *)buffer, sizeof(buffer));

    read_status = read(new_socket_fd, buffer, sizeof(buffer) - 1);
    if (read_status < 0) {
      throw_error("Error reading from socket");
    }

    printf("Client: %s\n", buffer);

    if (strcmp(buffer, "exit") == 0) {
      break;
    }

    clear_buffer((void *)buffer, sizeof(buffer));

    printf("Server: ");
    read_cli_str(buffer, sizeof(buffer));

    write_status = write(new_socket_fd, buffer, strlen(buffer));
    if (write_status < 0) {
      throw_error("Error writing to socket");
    }
  }

  printf("--- Ending conversation ---\n");

  printf("INFO: Closing connection...\n");
  close(new_socket_fd);

  printf("EXIT: Closing socket...\n");
  close(socket_fd);

  return 0;
}
