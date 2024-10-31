#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_SIMULTANEOUS_CONNECTIONS 5
#define MAX_BUFFER_SIZE 256
#define PORT_MANAGER 8080
#define SERVER_HOSTNAME "127.0.0.1"

void throw_error(const char *msg) {
  perror(msg);
  exit(1);
}

void clear_buffer(void *buffer, size_t bytes) {
  memset(buffer, 0, bytes);
}

void read_cli_str(char *buffer, const size_t buffer_size) {
  fgets(buffer, buffer_size - 1, stdin);
  buffer[strcspn(buffer, "\n")] = '\0';
}

int main(int argc, char *argv[]) {
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    throw_error("Error opening socket");
  }

  struct hostent *server = gethostbyname(SERVER_HOSTNAME);
  if (server == NULL) {
    throw_error("Error on gethostbyname");
  }

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  memcpy((void *)&server_address.sin_addr.s_addr, (void *)server->h_addr_list[0], server->h_length);
  server_address.sin_port = htons(PORT_MANAGER);

  int connect_status = connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
  if (connect_status < 0) {
    throw_error("Error on connecting to server");
  }

  printf("INFO: Connected to server!\n");

  int read_status, write_status;
  char buffer[MAX_BUFFER_SIZE];

  printf("--- Starting conversation ---\n");
  while (1) {
    clear_buffer((void *)buffer, sizeof(buffer));

    printf("You: ");
    read_cli_str(buffer, sizeof(buffer));

    write_status = write(socket_fd, buffer, strlen(buffer));
    if (write_status < 0) {
      throw_error("Error writing to socket");
    }

    if (strcmp(buffer, "exit") == 0) {
      break;
    }

    clear_buffer((void *)buffer, sizeof(buffer));
    read_status = read(socket_fd, buffer, sizeof(buffer) - 1);
    if (read_status < 0) {
      throw_error("Error reading from socket");
    }

    printf("Server: %s\n", buffer);
  }

  printf("--- Ending conversation ---\n");

  printf("EXIT: Closing socket...\n");
  close(socket_fd);

  return 0;
}
