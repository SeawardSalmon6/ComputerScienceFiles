#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define SORTED_FILENAME "dadosOrdenados.txt"

typedef struct
{
  FILE *fp;
  int pos, max;
  int *buffer;
} File_T;

void createTestFile(const char *filename)
{
  int i;
  FILE *fp = fopen(filename, "w");

  srand(time(NULL));
  for (i = 1; i < 990; i++)
    fprintf(fp, "%d\n", rand());
  fprintf(fp, "%d", rand());
  fclose(fp);
}

void merge(int *arr, int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  /* create temp arrays */
  int L[n1], R[n2];

  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  /* Copy the remaining elements of L[], if there
  are any */
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  /* Copy the remaining elements of R[], if there
  are any */
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int *arr, int l, int r)
{
  if (l < r)
  {
    // Same as (l+r)/2, but avoids overflow for
    // large l and h
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void fillBuffer(File_T *file, int t)
{
  int i;

  if (file->fp == NULL)
    return;

  file->pos = 0;
  file->max = 0;

  for (i = 0; i < t; i++)
    if (!feof(file->fp))
    {
      fscanf(file->fp, "%d", &file->buffer[file->max]);
      file->max++;
    }
    else
    {
      fclose(file->fp);
      file->fp = NULL;
      break;
    }
}

int getSmaller(File_T *file, int k, int t, int *smaller)
{
  int i, idx = -1;
  for (i = 0; i < k; i++)
    if (file[i].pos < file[i].max)
    {
      if (idx == -1)
        idx = i;
      else if (file[i].buffer[file[i].pos] < file[idx].buffer[file[idx].pos])
        idx = i;
    }

  if (idx != -1)
  {
    *smaller = file[idx].buffer[file[idx].pos];
    file[idx].pos++;

    if (file[idx].pos == file[idx].max)
      fillBuffer(file + idx, t);

    return 1;
  }

  return 0;
}

void saveFile(const char *filename, int *v, int size, int lineFlag)
{
  int i;
  FILE *fp = fopen(filename, "a");

  for (i = 0; i < size - 1; i++)
    fprintf(fp, "%d\n", v[i]);
  fprintf(fp, lineFlag ? "%d\n" : "%d", v[size - 1]);

  fclose(fp);
}

void mergeFiles(const char *filename, int k, int t)
{
  char newFile[20];
  int i, *buffer = (int *)malloc(t * sizeof(int));
  File_T *file = (File_T *)malloc(k * sizeof(File_T));

  for (i = 0; i < k; i++)
  {
    sprintf(newFile, "temp%d.txt", i + 1);
    file[i].fp = fopen(newFile, "r");
    file[i].max = 0;
    file[i].pos = 0;
    file[i].buffer = (int *)malloc(t * sizeof(int));
    fillBuffer(file + i, t);
  }

  int smaller, buffers = 0;
  while (getSmaller(file, k, t, &smaller) == 1)
  {
    buffer[buffers++] = smaller;
    if (buffers == t)
    {
      saveFile(filename, buffer, t, 1);
      buffers = 0;
    }
  }

  if (buffers != 0)
    saveFile(filename, buffer, buffers, 1);

  for (i = 0; i < k; i++)
    free(file[i].buffer);
  free(file);
  free(buffer);
}

// int compare(const void *a, const void *b)
// {
//   int ac = *(int *)a;
//   int bc = *(int *)b;
//   return ac - bc;
// }

int createSortedFile(const char *filename)
{
  int v[SIZE], count = 0, total = 0;
  char newFile[20];
  FILE *fp = fopen(filename, "r");

  while (!feof(fp))
  {
    fscanf(fp, "%d", &v[total++]);
    if (total == SIZE)
    {
      count++;
      sprintf(newFile, "temp%d.txt", count);
      mergeSort(v, 0, total - 1);
      saveFile(newFile, v, total, 0);
      total = 0;
    }
  }

  if (total > 0)
  {
    count++;
    sprintf(newFile, "temp%d.txt", count);
    mergeSort(v, 0, total - 1);
    saveFile(newFile, v, total, 0);
  }

  fclose(fp);
  return count;
}

void externalSorting(const char *filename)
{
  int k = createSortedFile(filename);
  int i, t;

  t = SIZE / (k + 1);
  printf("\n--> Número de arquivos: %d\n", k);
  printf("\n--> K-vias: %d\n", t);
  mergeFiles(SORTED_FILENAME, k, t);

  printf("\n--> Fim!\n\n");
}

int main()
{
  createTestFile("dados.txt");
  externalSorting("dados.txt");
  return 0;
}