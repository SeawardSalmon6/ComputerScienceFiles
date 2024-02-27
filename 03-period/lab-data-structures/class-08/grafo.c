// Arquivo com implementa��es das fun��es
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

No criaNo(int id, int val)
{
	No n = (No)malloc(sizeof(struct no));
	n->id = id;
	n->val = val;
	n->prox = NULL;
	return n;
}

void addNo(No n, int id, int val)
{
	No novo = criaNo(id, val);

	if (n == NULL)
		return;

	while (n->prox != NULL)
		n = n->prox;

	n->prox = novo;
}

void imprimeNo(No n)
{
	while (n != NULL)
	{
		printf("-> (%d, val: %d)", n->id, n->val);
		n = n->prox;
	}
}

Grafo criaGrafo()
{
	Grafo G = (Grafo)malloc(sizeof(struct grafo));
	G->vertices = NULL;

	return G;
}

// Fun��o para efetuar a leitura do grafo via arquivo
void readGraph(Grafo G, const char *filename)
{
	FILE *fp;
	int bsize = 20;
	int o, d, v, i;

	char buffer[bsize];
	fp = fopen(filename, "r");

	// Primeira linha do arquivo indica o numero de vertices
	fgets(buffer, bsize, fp);
	sscanf(buffer, "%d", &G->nNo);												// Salva o numero de vertices
	G->vertices = (No)malloc(G->nNo * sizeof(struct no)); // Cria o vetor de vertices

	// Primeiro elemento de cada lista identifica o vertice que a lista representa
	for (i = 0; i < G->nNo; i++)
	{
		(G->vertices + i)->id = i;
		(G->vertices + i)->val = -1; // Valor defaul (nao utilizado)
		(G->vertices + i)->prox = NULL;
	}

	// Percorre o arquivo
	while (!feof(fp))
	{
		fgets(buffer, bsize, fp);
		sscanf(buffer, "%d %d %d", &o, &d, &v);
		// Adiciona um novo vertice com id = d e valor = v na lista da posicao o do vetor
		addNo((G->vertices + o), d, v);
	}

	fclose(fp);
	return;
}

// Imprime o grafo a partir das listas de adjacencia
void printGraph(Grafo G)
{
	int i;
	printf("\nGrafo - Lista de Adjacencia\n\n");
	for (i = 0; i < G->nNo; i++)
	{
		printf("(%d)", (G->vertices + i)->id);
		imprimeNo((G->vertices + i));
		printf("\n");
	}
}
