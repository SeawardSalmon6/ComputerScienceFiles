#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *string, aux;
	int i;

	string = (char*) malloc(sizeof(char));
	for(i = 0; i < 1000; i++) {
		if(!scanf("%c", &aux))
			return 0;

		if(aux == '\n' || aux == '\r') {
			string[i] = '\0';
			break;
		}

		string = (char*) realloc(string, (i + 3) * sizeof(char));
		string[i] = aux;
	}

	printf("-> %s\n", string);
	free(string);

	return 0;
}