#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stddef.h>

#define TRUE 1
#define FALSE 0
#define boolean int // tipo boleano

// Pilha din�mica

// Estruturas e tipos
//--------------------------------------
// Tipo elemento (unidade dinamica)
typedef struct elem
{
	char info;
	struct elem *lig;
} tipo_elem;

// Tipo pilha
typedef struct
{
	tipo_elem *topo;
} pilha;
//--------------------------------------

// Opera��es
//--------------------------------------
// Cria uma pilha vazia
void Define(pilha *p)
{
	p->topo = NULL;
}

// Checa se a pilha est� vazia
boolean Vazia(pilha *p)
{
	return (p->topo == NULL);
}

// Insere x no topo da pilha (empilha)
boolean Push(char x, pilha *p)
{
	tipo_elem *q = (tipo_elem *)malloc(sizeof(tipo_elem));

	if (q == NULL)
		return FALSE;

	q->info = x;
	q->lig = p->topo;
	p->topo = q;

	return TRUE;
}

// Acessa ('olha') o elemento do topo da pilha (mas sem remov�-lo)
tipo_elem *Topo(pilha *p)
{
	return p->topo;
}

// Remove o elemento no topo da pilha, sem retorn�-lo (desempilha)
void Pop_up(pilha *p)
{
	tipo_elem *q = p->topo;
	p->topo = p->topo->lig;
	free(q);
}

// Imprime o atributo info de um tipo 'tipo_elem'
void imprimeElem(tipo_elem x)
{
	printf("Elemento: %c\n", x.info);
}

// Imprime os elementos da pilha
// ITEM A)
void imprimePilha(pilha *p)
{
	tipo_elem *aux;
	aux = p->topo;

	while (aux != NULL)
	{
		imprimeElem(*aux);
		aux = aux->lig;
	}
}
//--------------------------------------

//--------------------------------------
// Programa principal
int main()
{
	// Vari�veis
	char c;
	pilha *p = (pilha *)malloc(sizeof *p);
	tipo_elem *pointer_elem;

	printf("Digite um caractere: ");
	scanf("%c", &c);

	Define(p);

	// ITEM B)
	//-----------------------------------------
	tipo_elem *aux;
	aux = p->topo;

	while (aux != NULL)
	{
		if (aux->info == c)
		{
			Push(c, p);
			break;
		}

		aux = aux->lig;
		Pop_up(p);
		p->topo = aux;
	}
	//-----------------------------------------

	return 0;
}
//--------------------------------------
