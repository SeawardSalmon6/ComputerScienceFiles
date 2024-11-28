#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

#define LOGGER_FILENAME "log.csv"

#define LOWER_BOUND 0
#define UPPER_BOUND 1.5

#define ROOT_PROCESS 0

#define TEST_NUM 1
const long X_POINTS = (long)1e4; // 10^3
const long Y_POINTS = (long)1e4; // 10^3

// #define TEST_NUM 2
// const long X_POINTS = (long)1e4; // 10^3
// const long Y_POINTS = (long)1e5; // 10^4

// #define TEST_NUM 3
// const long X_POINTS = (long)1e4; // 10^3
// const long Y_POINTS = (long)1e6; // 10^5

/* ==================================== */

// #define TEST_NUM 4
// const long X_POINTS = (long)1e5; // 10^4
// const long Y_POINTS = (long)1e4; // 10^3

// #define TEST_NUM 5
// const long X_POINTS = (long)1e5; // 10^4
// const long Y_POINTS = (long)1e5; // 10^4

// #define TEST_NUM 6
// const long X_POINTS = (long)1e5; // 10^4
// const long Y_POINTS = (long)1e6; // 10^5

/* ==================================== */

// #define TEST_NUM 7
// const long X_POINTS = (long)1e6; // 10^5
// const long Y_POINTS = (long)1e4; // 10^3

// #define TEST_NUM 8
// const long X_POINTS = (long)1e6; // 10^5
// const long Y_POINTS = (long)1e5; // 10^4

// #define TEST_NUM 9
// const long X_POINTS = (long)1e6; // 10^5
// const long Y_POINTS = (long)1e6; // 10^5

double f(const double x, const double y) {
  // f(x, y) = sin(x² + y²)
  return sin(x * x + y * y);
}

double double_trapz(const int my_rank, const int world_size) {
  const long X_INTERVALS = X_POINTS - 1;
  const long Y_INTERVALS = Y_POINTS - 1;

  const double HX = (UPPER_BOUND - LOWER_BOUND) / X_INTERVALS;
  const double HX_HALF = HX / 2.0;
  const double HY = (UPPER_BOUND - LOWER_BOUND) / Y_INTERVALS;
  const double HY_HALF = HY / 2.0;

  long outer_start = X_POINTS * my_rank / world_size;
  long outer_end = X_POINTS * (my_rank + 1) / world_size;

  double x, inner_result, fxy;
  double local_result = 0.0;

  for (long i = outer_start; i < outer_end; i++) {
    x = LOWER_BOUND + i * HX;
    inner_result = 0.0;

    for (long j = 0; j < Y_POINTS; j++) {
      fxy = f(x, LOWER_BOUND + j * HY);
      inner_result += (j == 0 || j == Y_INTERVALS) ? fxy : 2 * fxy;
    }

    inner_result *= HY_HALF;
    local_result += (i == 0 || i == X_INTERVALS) ? inner_result : 2 * inner_result;
  }

  local_result *= HX_HALF;

  double global_result = 0.0;
  MPI_Reduce(&local_result, &global_result, 1, MPI_DOUBLE, MPI_SUM, ROOT_PROCESS, MPI_COMM_WORLD);
  return global_result;
}

int main(int argc, char *argv[]) {
  int my_rank, world_size;
  double end, start;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  MPI_Barrier(MPI_COMM_WORLD);
  start = MPI_Wtime();

  double result = double_trapz(my_rank, world_size);

  MPI_Barrier(MPI_COMM_WORLD);
  end = MPI_Wtime();

  MPI_Finalize();

  if (my_rank == ROOT_PROCESS) {
    FILE *logger_fp = fopen(LOGGER_FILENAME, "a+");

    fprintf(logger_fp, "\"%d\";", TEST_NUM);          // Test ID
    fprintf(logger_fp, "\"%d\";", world_size);        // Processes length
    fprintf(logger_fp, "\"%ld\";", X_POINTS);         // X points
    fprintf(logger_fp, "\"%ld\";", Y_POINTS);         // Y points
    fprintf(logger_fp, "\"%.16lf\";", result);        // Result
    fprintf(logger_fp, "\"%.16lf\";\n", end - start); // Time elapsed

    fclose(logger_fp);
  }

  return 0;
}
