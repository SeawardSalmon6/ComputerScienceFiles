#include <stdio.h>

int main() {
	int cardAtual = 0, 
	    cardAnterior = 0,
	    c = 0,
	    d = 0;
	int i;
	
	for(i = 1; i <= 5; i++) {
		scanf(" %d", &cardAtual);
		
		if(cardAtual > cardAnterior && i > 1) {
			c++;
			
		} else if(cardAnterior > cardAtual && i > 1) {
			d++;
		}
		
		cardAnterior = cardAtual;
	}
	
	if(c == 4) {
		printf("C\n");
		
	} else if(d == 4) {
		printf("D\n");
		
	} else if(c < 4 && d < 4) {
		printf("N\n");
	}
	
	return 0;
}
