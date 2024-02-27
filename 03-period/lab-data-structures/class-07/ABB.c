#include <stdlib.h> //Para usar malloc, free, exit ...
#include <stdio.h>	//Para usar printf ,...
#include "ABB.h"

// Opera��es
//------------------------------------------------------
// Cria uma �rvore bin�ria vazia
void Definir(tree t)
{
	t = NULL;
}

// Verifica se a AB � uma �rvore vazia
int Vazia(tree t)
{
	return (t == NULL);
}

// Define n� raiz
void Criar_raiz(tree t, tipo_dado elem)
{
	// o tipo 'tree' � um ponteiro de n�!
	tree raiz = malloc(sizeof(no));
	if (!raiz)
	{
		printf("Memoria insuficiente!\n");
		return;
	}

	raiz->info = elem;
	raiz->esq = NULL;
	raiz->dir = NULL;
	t = raiz;
}

// Retorna a altura (profundidade) da AB
int Altura(tree t)
{
	if (t == NULL)
		return 0;

	int altE = Altura(t->esq);
	int altD = Altura(t->dir);

	if (altE > altD)
		return (altE + 1);

	return (altD + 1); // altura = max(altE,altD) + 1
}

// Fun��o recursiva para verificar se uma AB � balanceada
boolean Balanceada(tree t)
{
	if (t == NULL)
		return TRUE;
	else if (t->esq == NULL && t->dir == NULL) // t n�o tem filhos
		return TRUE;
	else if (t->esq != NULL && t->dir != NULL)			   // t tem ambas sub�rvores n�o-nulas
		return (Balanceada(t->esq) && Balanceada(t->dir)); // recurs�o
	else if (t->esq != NULL)							   // t tem um �nico filho � na esquerda
		return (Altura(t->esq) == 1);
	else // t tem um �nico filho � na direita
		return (Altura(t->esq) == 1);
}

// Fun��o (recursida) para calcular o n�mero de n�s da AB
int Numero_nos(tree t)
{
	if (t == NULL)
		return 0;

	int nE = Numero_nos(t->esq);
	int nD = Numero_nos(t->dir);

	return (nE + nD + 1);
}

// Fun��o (recursiva) para verificar se
// uma AB � perfeitamente balanceada
boolean Perf_balanceada(tree t)
{
	if (t == NULL)
		return TRUE;
	else if (t->esq == NULL && t->dir == NULL) // t n�o tem filhos
		return TRUE;
	else if (t->esq != NULL && t->dir != NULL)						 // t tem ambas sub�rvores n�o-nulas
		return (Perf_balanceada(t->esq) && Perf_balanceada(t->dir)); // recurs�o
	else if (t->esq != NULL)										 // t tem um �nico filho � na  esquerda
		return (Numero_nos(t->esq) == 1);
	else // t tem um �nico filho � na direita
		return (Numero_nos(t->esq) == 1);
}

// Fun��o p/ adicionar um filho � direita de um n�, cujo ponteiro � dado (pai).
// Se o n� n�o possui filho � direita, ent�o cria esse filho com conte�do "elem"
boolean Insere_dir(tree pai, tipo_dado elem)
{
	if (pai == NULL)
		return FALSE;

	if (pai->dir != NULL)
	{
		printf("Ja tem filho a direita\n");
		return FALSE;
	}

	// Jeito #1
	Criar_raiz(pai->dir, elem);

	// Jeito #2 ('na m�o')
	// tree no = malloc(sizeof(no));
	// no->esq = NULL;
	// no->dir = NULL;
	// no->info = item;
	// pai->dir = no;

	return TRUE;
}

// Fun��o p/ adicionar um filho � esquerda de um n�, cujo ponteiro � dado (pai).
// Se o n� n�o possui filho � esquerda, ent�o cria esse filho com conte�do "elem"
boolean Insere_esq(tree pai, tipo_dado elem)
{
	if (pai == NULL)
		return FALSE;

	if (pai->esq != NULL)
	{
		printf("Ja tem filho a esquerda\n");
		return FALSE;
	}

	Criar_raiz(pai->esq, elem);

	return TRUE;
}

// Percorre a �rvore em pr�-ordem
void Pre_ordem(tree t)
{
	if (t != NULL)
	{
		Visita(t);
		Pre_ordem(t->esq);
		Pre_ordem(t->dir);
	}
}

// Percorre a �rvore no esquema in-ordem
void In_ordem(tree t)
{
	if (t != NULL)
	{
		In_ordem(t->esq);
		// Visita(t);
		// In_ordem(t->dir);
	}
}

// Percorre a �rvore em p�s-ordem
void Pos_ordem(tree t)
{
	if (t != NULL)
	{
		Pos_ordem(t->esq);
		Pos_ordem(t->dir);
		Visita(t);
	}
}

// Fun��o "Visita" na forma de impress�o de dado
void Visita(tree t)
{
	printf("Valor: %d\n", t->info.valor);
}

// Fun��o (recursiva) de busca para ABB
pno Busca_r(tree raiz, tipo_dado elem)
{
	if (raiz == NULL)
		return NULL;

	if (elem.valor == raiz->info.valor)
		return raiz;

	if (elem.valor < raiz->info.valor)
		return Busca_r(raiz->esq, elem);
	else
		return Busca_r(raiz->dir, elem);
}

// Fun��o (n�o-recursiva) de busca para ABB
pno Busca_nr(tree raiz, tipo_dado elem)
{
	pno p = raiz;

	while (p != NULL)
	{
		if (p->info.valor == elem.valor)
			return p;
		else if (elem.valor > p->info.valor)
			p = p->dir;
		else
			p = p->esq;
	}

	return p;
}

// Fun��o (recursiva) para inserir um elemento com um
// valor x em uma ABB, caso ele ainda n�o esteja l�.
// Retorna o ponteiro para o n� que cont�m o elem. c/ valor x
tree Busca_insere(tree raiz, tipo_dado elem)
{
	if (raiz == NULL)
	{
		raiz = malloc(sizeof(tree));
		raiz->info = elem;
		raiz->esq = NULL;
		raiz->dir = NULL;
		return raiz;
	}

	if (elem.valor < raiz->info.valor)
		return Busca_insere(raiz->esq, elem);
	else if (elem.valor > raiz->info.valor)
		return Busca_insere(raiz->dir, elem);

	return raiz;
}

// Fun��o (recursiva) para buscar e remover um elemento com um
// valor x. Retorna true se removeu o elemento; false, se o
// elemento de valor x n�o estava na �rvore
// Implementacao 3 da aula
boolean Busca_remove(tree raiz, tipo_dado elem)
{
	//�rvore vazia; x n�o est� na �rvore
	if (raiz == NULL)
		return FALSE;

	// Encontrou exatamente x: eliminar
	if (raiz->info.valor == elem.valor)
	{
		Remove_no(raiz);
		// Caso altere a raiz no procedimento, altera aqui
		return TRUE;
	}

	if (raiz->info.valor < elem.valor)
		// Buscar e remover na sub-�rvore direira
		return Busca_remove(raiz->dir, elem);
	else
		// Buscar e remover na sub-�rvore esquerda
		return Busca_remove(raiz->esq, elem);
}

// Fun��o de remo��o dado um n� p
// p � o ponteiro para o n� a ser removido.
// Retorna em p o ponteiro para o n� que o substituiu
// Implementacao 3 da aula
void Remove_no(pno p)
{
	pno q;

	if (p->esq == NULL)
	{
		// Substitui pelo filho � direita
		q = p;
		p = p->dir;
		free(q);
	}
	else if (p->dir == NULL)
	{
		// Substitui pelo filho � esquerda
		q = p;
		p = p->esq;
		free(q);
	}
	else
		Substitui_menor_a_direita(p, p->dir);
	// Alternativamente: Substituir_maior_a_esquerda(p, p->esq)
}

// Encontra o sucessor de p, isto �, o descendente mais
//� esquerda da sub-arvore � direita de p. � um n�
// terminal: seu conte�do � copiado em q e ele ser� removido
// Implementacao 3 da aula
void Substitui_menor_a_direita(pno p, pno suc)
{
	pno q;

	if (suc->esq == NULL)
	{
		p->info = suc->info;

		// Remover sucessor
		q = suc;
		suc = suc->dir;
		free(q);
	}
	else
		Substitui_menor_a_direita(p, suc->esq);
}
