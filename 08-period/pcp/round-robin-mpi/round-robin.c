#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MANAGER_ID = 0;

void round_robin(int process_id, int processes_count) {
  srand(time(NULL) + process_id);

  MPI_Status status;
  int next = (process_id + 1) % processes_count;
  int prev = (process_id - 1 + processes_count) % processes_count;
  long int rand_mine = rand() / (RAND_MAX / 100);
  long int rand_theirs;

  printf("(%d)-t1: got %ld\n", process_id, rand_mine);

  if (process_id % 2 == 0) {
    printf("(%d)-t2.1: sending %ld to %d\n", process_id, rand_mine, next);

    MPI_Send((void *)&rand_mine, 1, MPI_LONG, next, 0, MPI_COMM_WORLD);
    MPI_Recv((void *)&rand_theirs, 1, MPI_LONG, prev, 0, MPI_COMM_WORLD, &status);

    printf("(%d)-t2.2: receiving from %d\n", process_id, prev);
  } else {
    printf("(%d)-t2.2: receiving from %d\n", process_id, prev);

    MPI_Recv((void *)&rand_theirs, 1, MPI_LONG, prev, 0, MPI_COMM_WORLD, &status);
    MPI_Send((void *)&rand_mine, 1, MPI_LONG, next, 0, MPI_COMM_WORLD);

    printf("(%d)-t2.1: sending %ld to %d\n", process_id, rand_mine, next);
  }

  printf("(%d)-t3: I had %ld and got %ld from %d\n", process_id, rand_mine, rand_theirs, prev);
}

int main(int argc, char **argv) {
  int PROCESS_RANK, PROCESSES_COUNT;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &PROCESSES_COUNT);
  MPI_Comm_rank(MPI_COMM_WORLD, &PROCESS_RANK);

  if (PROCESS_RANK == MANAGER_ID) {
    printf("(%d)-t0: Hello, I'm the manager of %d processes!\n", PROCESS_RANK, PROCESSES_COUNT);
  } else {
    printf("(%d)-t0: Hello!\n", PROCESS_RANK);
  }

  round_robin(PROCESS_RANK, PROCESSES_COUNT);
  printf("(%d)-t4: Goodbye!\n", PROCESS_RANK);

  MPI_Finalize();
  return 0;
}