#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

const double LOWER_BOUNDS[2] = { 0, 0 };
const double UPPER_BOUNDS[2] = { 1.5, 1.5 };

const int NUM_OF_TESTS_RUNS = 10;
const int POINTS_LENGTH = 1;
const int THREADS_LENGTH = 4;
const int THREADS_TESTS[THREADS_LENGTH] = { 1, 2, 4, 8 };
const long POINTS_TESTS[POINTS_LENGTH] = {
  (long)10e3,
  (long)10e4,
  (long)10e5
};

double f(const double x, const double y) {
  // f(x, y) = sin(x² + y²)
  return sin(x * x + y * y);
}

double double_trapz(long points[POINTS_LENGTH]) {
  const double HX = (UPPER_BOUNDS[0] - LOWER_BOUNDS[0]) / (points[0] - 1);
  const double HY = (UPPER_BOUNDS[1] - LOWER_BOUNDS[1]) / (points[1] - 1);

  double global_result = 0.0;

  #pragma omp parallel reduction(+:global_result)
  {
    int num_threads = omp_get_num_threads();
    int thread_id = omp_get_thread_num();

    long outer_start = points[0] * thread_id / num_threads;
    long outer_end = points[0] * (thread_id + 1) / num_threads;

    double local_result = 0.0;

    for (long i = outer_start; i < outer_end; i++) {
      double x = LOWER_BOUNDS[0] + i * HX;
      double inner_result = 0.0;

      for (long j = 0; j < points[1]; j++) {
        double y = LOWER_BOUNDS[1] + j * HY;
        double fxy = f(x, y);
        inner_result += (j == 0 || j == points[1] - 1) ? fxy : 2 * fxy;
      }

      inner_result *= HY / 2.0;
      local_result += (i == 0 || i == points[0] - 1) ? inner_result : 2 * inner_result;
    }

    global_result += local_result * HX / 2.0;
  }

  return global_result;
}

int main() {
  int num_of_threads = 0;
  long points[2] = { 0, 0 };
  double start, end;

  for (int t = 0; t < NUM_OF_TESTS_RUNS; t++) {
    for (int k = 0; k < THREADS_LENGTH; k++) {
      num_of_threads = THREADS_TESTS[k];
      omp_set_num_threads(num_of_threads);

      for (int i = 0; i < POINTS_LENGTH; i++) {
        for (int j = 0; j < POINTS_LENGTH; j++) {

          points[0] = POINTS_TESTS[i] + 1;
          points[1] = POINTS_TESTS[j] + 1;

          start = omp_get_wtime();
          double result = double_trapz(points);
          end = omp_get_wtime();

          printf("---- Test %d: Threads (%d), Points (%d, %d) results ----\n", (t + 1), (k + 1), (i + 1), (j + 1));
          printf("- Result: %.8lf\n", result);
          printf("- Time elapsed: %.8lf seconds with\n", end - start);
          printf("  => Number of threads: %d\n", num_of_threads);
          printf("  => X intervals: %ld\n", points[0] - 1);
          printf("  => Y intervals: %ld\n", points[1] - 1);
          printf("\n\n");
        }
      }
    }
  }

  return 0;
}
