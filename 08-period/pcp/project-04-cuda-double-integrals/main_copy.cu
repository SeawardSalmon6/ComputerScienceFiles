#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cuda_runtime.h>

#define LOGGER_FILENAME "log.csv"

#define LOWER_BOUND 0
#define UPPER_BOUND 1.5

#define ROOT_PROCESS 0
#define THREADS_PER_BLOCK 512

#define BLOCKS 10
// #define BLOCKS 100
// #define BLOCKS 1000

#define TEST_NUM 1
const long X_POINTS = (long)1e3; // 10^3
const long Y_POINTS = (long)1e3; // 10^3

// #define TEST_NUM 2
// const long X_POINTS = (long)1e3; // 10^3
// const long Y_POINTS = (long)1e4; // 10^4

// #define TEST_NUM 3
// const long X_POINTS = (long)1e3; // 10^3
// const long Y_POINTS = (long)1e5; // 10^5

/* ==================================== */

// #define TEST_NUM 4
// const long X_POINTS = (long)1e4; // 10^4
// const long Y_POINTS = (long)1e3; // 10^3

// #define TEST_NUM 5
// const long X_POINTS = (long)1e4; // 10^4
// const long Y_POINTS = (long)1e4; // 10^4

// #define TEST_NUM 6
// const long X_POINTS = (long)1e4; // 10^4
// const long Y_POINTS = (long)1e5; // 10^5

/* ==================================== */

// #define TEST_NUM 7
// const long X_POINTS = (long)1e5; // 10^5
// const long Y_POINTS = (long)1e3; // 10^3

// #define TEST_NUM 8
// const long X_POINTS = (long)1e5; // 10^5
// const long Y_POINTS = (long)1e4; // 10^4

// #define TEST_NUM 9
// const long X_POINTS = (long)1e5; // 10^5
// const long Y_POINTS = (long)1e5; // 10^5

__device__ double f(const double x, const double y) {
  // f(x, y) = sin(x² + y²)
  return sin(x * x + y * y);
}

__global__ void double_trapz(double *global_result) {
  const long X_INTERVALS = X_POINTS - 1;
  const long Y_INTERVALS = Y_POINTS - 1;

  const double HX = (UPPER_BOUND - LOWER_BOUND) / X_INTERVALS;
  const double HX_HALF = HX / 2.0;
  const double HY = (UPPER_BOUND - LOWER_BOUND) / Y_INTERVALS;
  const double HY_HALF = HY / 2.0;

  const long idx = blockIdx.x * blockDim.x + threadIdx.x;
  long intervals_per_thread = (X_INTERVALS * Y_INTERVALS) / (BLOCKS * THREADS_PER_BLOCK);
  long outer_start = idx * intervals_per_thread;
  long outer_end = (idx + 1) * intervals_per_thread;

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

  *global_result += local_result * HX_HALF;
}

int main(int argc, char *argv[]) {
  double result, time;
  cudaEvent_t start, stop;

  cudaEventCreate(&start);
  cudaEventCreate(&stop);
  cudaEventRecord(start, 0);

  double_trapz<<<BLOCKS, THREADS_PER_BLOCK>>>(&result);
  
  cudaEventRecord(stop, 0);
  cudaEventSynchronize(stop);
  cudaEventElapsedTime(&time, start, stop);

  FILE *logger_fp = fopen(LOGGER_FILENAME, "a+");

  fprintf(logger_fp, "\"%d\";", TEST_NUM);    // Test ID
  fprintf(logger_fp, "\"%d\";", BLOCKS);      // Blocks length
  fprintf(logger_fp, "\"%ld\";", X_POINTS);   // X points
  fprintf(logger_fp, "\"%ld\";", Y_POINTS);   // Y points
  fprintf(logger_fp, "\"%.16lf\";", result);  // Result
  fprintf(logger_fp, "\"%.16lf\";\n", time);  // Time elapsed

  fclose(logger_fp);

  return 0;
}
