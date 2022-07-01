#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define boolean int	 // tipo boleano
#define tam_fila 100 // tamanho max. fila

// Fila circular

// Estruturas
//----------------------------------
// Tipo registro
typedef struct
{
	char nome[30];
	int idade;
} tipo_dado;

// Tipo fila (sequencial)
typedef struct
{
	tipo_dado A[tam_fila];
	int inicio, fim;
} fila;
//----------------------------------

// Opera��es
//----------------------------------
// Cria uma fila vazia
void Definir(fila *q)
{
	q->fim = 0;
	q->inicio = 0;
}

// Checa se uma fila est� vazia
boolean Vazia(fila *q)
{
	return (q->inicio == q->fim);
}

// Checa se uma fila est� cheia
boolean Cheia(fila *q)
{
	return (q->inicio == ((q->fim + 1) % tam_fila));
	// Obs: Crit�rio adotado p/ fila cheia: os dois ponteiros ir�o diferir em uma posi��o
}

// Adiciona um elemento no fim da fila q
boolean Inserir(fila *q, tipo_dado elem)
{
	if (Cheia(q))
		return FALSE;

	q->fim = (q->fim + 1) % tam_fila;
	q->A[q->fim] = elem;
	return TRUE;
}

// Remove o elemento do in�cio da fila, retornando uma c�pia do mesmo
// ITEM A)
boolean Remover(fila *q, tipo_dado *elem)
{
	if (Vazia(q))
		return FALSE;

	*elem = q->A[q->inicio + 1];
	q->inicio = (q->inicio + 1) % tam_fila;
	return TRUE;
}

// Retorna o tamanho da fila
// ITEM B) - DICA: Usar q->inicio, q->fim e tam_fila
int Tamanho(fila *q)
{
	if (q->fim >= q->inicio)
		return (q->fim - q->inicio);

	return tam_fila - (q->inicio - q->fim) + 1;
}

// Imprime os campos de um elemento do 'tipo_dado'
void Imprimir_elem(tipo_dado x)
{
	printf("Nome: %s - ", x.nome);
	printf("Idade: %d \n", x.idade);
	return;
}

// Imprime os elementos de uma fila
// ITEM C)
void Imprimir(fila *q)
{
	// Dica: Lembre-se que nesta implementacao de fila, o ponteiro
	// do in�cio est� posicionado UMA unidade ANTES do in�cio da fila!
	// Logo, o primeiro elemento da fila � dado por q->inicio+1
	if (Vazia(q))
	{
		printf("\n-> Lista vazia!\n");
		return;
	}

	int i = (q->inicio + 1) % tam_fila;
	while (i != q->fim + 1)
	{
		Imprimir_elem(q->A[i]);
		i = (i + 1) % tam_fila;
	}
}
//----------------------------------

// Programa teste (para validar as implementa��es)
int main(void)
{
	// Vari�veis
	fila DBZ, Disney;
	tipo_dado a1, a2, b1, b2, removido;

	// Cria dois conjuntos vazios (para testar o c�digo)
	Definir(&DBZ);
	Definir(&Disney);

	strcpy(a1.nome, "Gohan");
	a1.idade = 23;
	strcpy(a2.nome, "Goku");
	a2.idade = 42;
	strcpy(b1.nome, "Mickey");
	b1.idade = 90;
	strcpy(b2.nome, "Pato Donald");
	b2.idade = 80;

	Inserir(&DBZ, a1);
	Inserir(&DBZ, a2);
	Inserir(&Disney, b1);
	Inserir(&Disney, b2);

	Imprimir(&DBZ);
	Imprimir(&Disney);

	Remover(&DBZ, &removido);

	Imprimir(&DBZ);

	return 0;
}
