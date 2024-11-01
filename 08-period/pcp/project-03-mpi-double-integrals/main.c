#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define LOWER_BOUND 0
#define UPPER_BOUND 1.5

#define NUM_OF_TESTS_RUNS 2
#define INTERVALS_LENGTH 3
#define THREADS_LENGTH 4

const int THREADS_TESTS[] = { 8, 4, 2, 1 };
const long INTERVALS_TESTS[] = {
  (long)1e4, // 10^3
  (long)1e5, // 10^4
  (long)1e6  // 10^5
};

double f(const double x, const double y) {
  // f(x, y) = sin(x² + y²)
  return sin(x * x + y * y);
}

double double_trapz(const long points[2]) {
  const long X_INTERVALS = points[0] - 1;
  const long Y_INTERVALS = points[1] - 1;

  const double HX = (UPPER_BOUND - LOWER_BOUND) / X_INTERVALS;
  const double HX_HALF = HX / 2.0;
  const double HY = (UPPER_BOUND - LOWER_BOUND) / Y_INTERVALS;
  const double HY_HALF = HY / 2.0;

  double global_result = 0.0;

  #pragma omp parallel reduction(+:global_result)
  {
    int num_threads = omp_get_num_threads();
    int thread_id = omp_get_thread_num();

    long outer_start = points[0] * thread_id / num_threads;
    long outer_end = points[0] * (thread_id + 1) / num_threads;

    double x, inner_result, fxy;
    double local_result = 0.0;

    for (long i = outer_start; i < outer_end; i++) {
      x = LOWER_BOUND + i * HX;
      inner_result = 0.0;

      for (long j = 0; j < points[1]; j++) {
        fxy = f(x, LOWER_BOUND + j * HY);
        inner_result += (j == 0 || j == Y_INTERVALS) ? fxy : 2 * fxy;
      }

      inner_result *= HY_HALF;
      local_result += (i == 0 || i == X_INTERVALS) ? inner_result : 2 * inner_result;
    }

    #pragma omp atomic
    global_result += local_result * HX_HALF;
  }

  return global_result;
}

int main() {
  int i, j, k, t, num_of_threads = 0;
  long points[2] = { 0, 0 };
  double start, end, suit_time = 0.0, total_time = 0.0;

  for (t = 0; t < NUM_OF_TESTS_RUNS; t++) {
    printf("---- Test %d results ----\n", (t + 1));
    suit_time = 0.0;

    for (k = 0; k < THREADS_LENGTH; k++) {
      num_of_threads = THREADS_TESTS[k];
      omp_set_num_threads(num_of_threads);

      printf("    ---- %d Threads results ----\n", num_of_threads);

      /*
        For reproductibility of the tests in the report,
          uncomment the line below:
          
        for (i = 0; i < 1; i++) { // Refers only to first interval of the outer integral
       */
      for (i = 0; i < INTERVALS_LENGTH; i++) {
        for (j = 0; j < INTERVALS_LENGTH; j++) {
          points[0] = INTERVALS_TESTS[i] + 1;
          points[1] = INTERVALS_TESTS[j] + 1;

          start = omp_get_wtime();
          double result = double_trapz(points);
          end = omp_get_wtime();

          double time = end - start;
          suit_time += time;
          total_time += time;

          printf("        ---- Intervals (%ld, %ld) results ----\n", points[0] - 1, points[1] - 1);
          printf("            - Result: %.16lf\n", result);
          printf("            - Time elapsed: %.16lf seconds\n", time);
          printf("\n\n");
        }
      }
    }

    printf("==== Test %d total time elapsed: %.16lf seconds\n\n", (t + 1), suit_time);
  }

  printf("\n---- Total suits time elapsed: %.16lf seconds", total_time);
  printf("\n    - Average time elapsed: %.16lf seconds\n", total_time / NUM_OF_TESTS_RUNS);

  return 0;
}
