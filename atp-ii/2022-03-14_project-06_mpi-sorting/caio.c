#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 200

void intercala(int p, int q, int r, int v[])
{
   int *w;
   w = malloc ((r-p) * sizeof (int));
   int i = p, j = q;
   int k = 0;

   while (i < q && j < r) {
      if (v[i] <= v[j])  w[k++] = v[i++];
      else  w[k++] = v[j++];
   }
   while (i < q)  w[k++] = v[i++];
   while (j < r)  w[k++] = v[j++];
   for (i = p; i < r; ++i)  v[i] = w[i-p];
   free (w);
}
void mergeSort(int p, int r, int v[])
{
   if (p < r-1) {
      int q = (p + r)/2;
      mergeSort (p, q, v);
      mergeSort (q, r, v);
      intercala (p, q, r, v);
   }
}
void insertionSort(int vet[], int k){
    int i, j, valor;

    for(i=1;i<k;i++){
        valor=vet[i];
        j=i;
        while(j>0 && vet[j-1] > valor){
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = valor;
    }
}
int main(int argc, char **argv){ //use of MPI in function main
    struct timeval start, end;
    FILE *arq;
    FILE *arq2;
    int vet[N];

    arq = fopen("bigint.dat","r");

    for(int i=0; i<N;i++){
        fscanf(arq, "%d ", &vet[i]);
    }

    fclose(arq);

    MPI_Init(NULL, NULL); //Start MPI
    int world_size;
    int world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size); //receive numbers of process
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); //rank of process

    int indiceVet;
    indiceVet = N/world_size; // calculate value of n/k using MPI

    int vetInsert[indiceVet]; //sliced array
    int vetMerge[N]; //array that will be used for mergeSort

    gettimeofday(&start, NULL);

    MPI_Scatter(vetInsert, N, MPI_INT, vetMerge, N, MPI_INT, 0, MPI_COMM_WORLD); //almost the same of MPI_Bcast
    //sends a segment of vet to all the process in COMM
    //vetdiv receives the segment
    //after the array split in sub-arrays, the program can execute insertionSort

    insertionSort(vetInsert, indiceVet); //sort the array
    MPI_Gather(vetInsert, indiceVet, MPI_INT, vetMerge, indiceVet, MPI_INT,0 , MPI_COMM_WORLD);

    mergeSort(0, N,vetMerge);
    gettimeofday(&end, NULL);

    printf("\nTime Elapsed program: %lf\n", (double) ((end.tv_sec - start.tv_sec) + 1E-6 * (end.tv_usec - start.tv_usec)));

    arq2 = fopen("saida.dat","wt");

    for(int i=0; i<N;i++){
        fprintf(arq2, "%d \n", vetMerge[i]);
    }
    fclose(arq2);

    MPI_Finalize();
}