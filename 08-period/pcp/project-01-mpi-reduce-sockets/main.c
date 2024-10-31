#include <stdio.h>
#include <mpi.h>

#include "factory.h"

int main(int argc, char **argv) {
  int PROCESS_RANK, PROCESSES_LENGTH;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &PROCESSES_LENGTH);
  MPI_Comm_rank(MPI_COMM_WORLD, &PROCESS_RANK);

  if (PROCESS_RANK == MANAGER_ID) { // Manager has its own function
    build_manager_socket(
      MANAGER_ID,
      MANAGER_PORT
    );
  } else if (PROCESS_RANK % 2 == 1) { // Odd workers are receivers and senders
    build_receiver_sender_worker(
      PROCESS_RANK,
      WORKERS_INDEXES[PROCESS_RANK],
      PROCESSES_LENGTH,
      ADD // If you want to change the operation, you can change this constant with some of the values from AccumulatingOperations enum
    );
  } else { // Even workers are only producers
    build_only_producer_worker(
      PROCESS_RANK,
      WORKERS_INDEXES[PROCESS_RANK],
      PROCESS_RANK - 1,
      WORKERS_INDEXES[PROCESS_RANK - 1]
    );
  }

  MPI_Finalize();
  return 0;
}
