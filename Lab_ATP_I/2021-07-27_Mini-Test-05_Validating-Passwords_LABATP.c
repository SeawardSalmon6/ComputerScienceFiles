#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char c[31];
    
    printf("\n\nDigite uma senha de, no máximo, 30 caracteres: ");;
    scanf(" %s", c);

    int i = 0;
    char transicao, estado = 'A';

    do {
        transicao = c[i];

        switch(estado) {
            case 'A':
                if(transicao == 'a')
                    estado = 'A';
                else if(transicao == 'b')
                    estado = 'B';
                else
                    estado = 'E';
            break;

            case 'B':
                if(transicao == 'c')
                    estado = 'C';
                else
                    estado = 'E';
            break;

            case 'C':
                if(transicao == 'c')
                    estado = 'C';
                else if(transicao == '\0')
                    estado = 'D';
                else
                    estado = 'E';
            break;
        }
        i++;

    } while((estado != 'D') && (estado != 'E'));

    if(estado == 'D')
        printf("\n--> String válida!\n\n");
    else if(estado == 'E')
        printf("\n--> String inválida!\n\n");

    return 0;
}