#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int timeYears = 0;
	float heightAnacleto = 1.50, heightFelisberto = 1.10;

	while(heightFelisberto < heightAnacleto) {
		heightFelisberto += 0.03;
		heightAnacleto += 0.02;

		timeYears++;
	}

	printf("\nPara que Felisberto seja mais alto que Anacleto, ele vai precisar crescer por mais: %d anos\n\n", timeYears);

	return 0;
}