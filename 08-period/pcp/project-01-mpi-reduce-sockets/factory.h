#ifndef FACTORY_H
#define FACTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Constants

/*
  If 0, will print some extra validations for debugging purposes
    and workers will use his own ID as values.

  If 1, will hide these extra validations
    and workers will use random production values.
*/
#define DEBUG 0

#define MAX_SIMULTANEOUS_CONNECTIONS 5
#define MAX_BUFFER_SIZE 256
#define COMMON_HOSTNAME "127.0.0.1"
#define MANAGER_ID 0
#define WORKER_MANAGER_ID 1

/* 8 Workers + 1 Manager */
#define WORKERS_INDEXES_LENGTH 9

typedef enum Boolean {
  FALSE = 0,
  TRUE = 1,
} Boolean;

typedef enum AccumulatingOperations {
  ADD,
  SUB,
  MULT,
  DIV,
} AccumulatingOperations;

typedef enum WorkersPorts {
  MANAGER_PORT = 8080,
  WORKER1_PORT = 8081,
  WORKER2_PORT = 8082,
  WORKER3_PORT = 8083,
  WORKER4_PORT = 8084,
  WORKER5_PORT = 8085,
  WORKER6_PORT = 8086,
  WORKER7_PORT = 8087,
  WORKER8_PORT = 8088
} WorkersPorts;

extern const int WORKERS_INDEXES[WORKERS_INDEXES_LENGTH];

typedef struct sockaddr_in sockaddr_in_t;

// Function prototypes
void throw_error(const char *msg);
void clear_buffer(void *buffer, const size_t buffer_size);
int get_steps_length(const int processes_length);
char *get_timestamp();

void report_info(const char *msg, const int worker_id);
void report_connection(const int worker_id, const int pair_id, const int pair_port);
void report_connection_closed(const int worker_id, const int pair_id, const int pair_port);
void report_connection_accepted(const int worker_id, const int pair_port);
void report_readiness(const int worker_id, const int port);
void report_production(const int worker_id, const int produced, const int port);
void report_consumption(const int consumer_id, const int consumed, const int producer_id, const int producer_port);

int get_socket(const Boolean reusable);
void close_socket(const int socket_fd);
sockaddr_in_t *get_address_for_port(const int port);
void bind_socket(const int socket_fd, sockaddr_in_t *socket_address);
void listen_socket(const int socket_fd);
int accept_socket(const int socket_fd, sockaddr_in_t *client_address);
int process_should_send_to_manager(const int worker_id, const int step);
int get_manager_id(const int worker_id, const int step);
int get_worker_id_by_port(const int port);
void wait_for_exit_signal(const int socket_fd);
void send_exit_signal(const int socket_fd);
int connect_to_port(const int socket_fd, const int connection_port);
char *retrieve_worker_address_from_port(const int port);

int accumulate(const int current, const int value, const AccumulatingOperations op);
void send_value_to_port_and_exit(int produced, const int socket_fd, const int sender_id, const int destination_id, const int destination_port);
void build_only_producer_worker(const int producer_id, const int producer_port, const int destination_id, const int destination_port);
void build_receiver_sender_worker(const int worker_id, const int worker_port, const int processes_length, const AccumulatingOperations op);
void build_manager_socket(const int worker_id, const int worker_port);

#endif
