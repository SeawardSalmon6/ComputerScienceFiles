#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    unsigned char letter, password[31] = { 0 };
    
    printf("\n\nDigite uma senha de, no máximo, 30 caracteres: ");
    scanf(" %s", password);

    int i = 0;
    char state = 'T';

    do {
        letter = password[i];

        if((letter >= 65 && letter <= 90) || (letter == '\0')) state = 'T';
        else state = 'F';

        i++;

    } while(state != 'F' && letter != '\0');

    if(state == 'T')
        printf("\n--> Senha válida!\n\n");
    else if(state == 'F')
        printf("\n--> Senha inválida! Só aceitamos senhas com todas as letras maiúsculas.\n\n");

    return 0;
}