#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

	const int IDADE_MIN = 18;
	const int IDADE_MAX = 70;

    int idade;

    printf("\nInsira sua idade: ");
    scanf("%d", &idade);

    if(idade < IDADE_MIN)
        printf("\nVocê não pode dirigir e nem se aposentar!\n\n");
    else if(idade >= IDADE_MIN && idade < IDADE_MAX)
        printf("\nVocê já pode dirigir, mas ainda não pode se aposentar!\n\n");
    else if(idade >= IDADE_MAX)
        printf("\nVocê pode dirigir e já pode se aposentar!\n\n");

    return 0;
}