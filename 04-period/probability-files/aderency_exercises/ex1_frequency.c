#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N_INTERVALS 10

const double QUI_QUADRADO_TABLE[] = {0, 3.841, 5.991, 7.815, 9.488, 11.070, 12.592, 14.067, 15.507, 16.919, 18.307, 19.675, 21.026, 22.362, 23.685, 24.996, 26.296, 27.587, 28.869, 30.144, 31.410, 32.671, 33.924, 35.172, 36.415, 37.652, 38.885, 40.113, 41.337, 42.557, 43.773, 49.802, 55.758, 61.656, 67.505, 73.311, 79.082, 90.531, 101.879, 113.145, 124.342, 135.480, 146.567};

double
qui_quadrado(const double observed, const int sample_size)
{
  const double expected = (double)sample_size / N_INTERVALS;
  return pow(expected - observed, 2) / expected;
}

int main()
{
  int i, r, num, intervals_sum[N_INTERVALS] = {0};
  double *numbers, r_num, sum;

  srand(time(NULL));
  printf("\n--> Insira a quantidade de números a serem gerados: ");
  r = scanf(" %d", &num);

  if (!r)
  {
    printf("\n!--> Insira um valor válido!\n\n");
    return 1;
  }

  numbers = (double *)malloc(num * sizeof(double));
  for (i = 0; i < num; i++)
  {
    r_num = (double)rand() / RAND_MAX;
    printf("\n(%02d) %.8lf", i + 1, r_num);

    numbers[i] = r_num;
    intervals_sum[(int)(r_num * 10)]++;
  }

  printf("\n\n");

  for (i = 0; i < N_INTERVALS; i++)
    printf("\nIntervalo %.1f <= x < %.1f:\t%d", i / 10.0, (i + 1) / 10.0, intervals_sum[i]);
  printf("\n\n");

  sum = 0;
  for (i = 0; i < N_INTERVALS; i++)
    sum += qui_quadrado(intervals_sum[i], num);

  printf("--> Qui-Quadrado da amostra:\t%.5lf\n\n", sum);
  printf("--> Qui-Quadrado Tabelado:\t%.5lf\n\n", QUI_QUADRADO_TABLE[N_INTERVALS - 1]);
  printf("--> Resultado:\t%s\n\n", sum < QUI_QUADRADO_TABLE[N_INTERVALS - 1] ? "Amostra aceita!" : "Amostra incosistente!");

  return 0;
}