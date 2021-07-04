#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int input, mm;

    printf("\nInsira o tempo do processamento em horas: ");
    scanf("%d", &input);

    mm = input * 60;

    printf("\nO tempo desse processo de %d horas, em minutos é de:\n%d minuto(s)\n", input, mm);

    return 0;
}