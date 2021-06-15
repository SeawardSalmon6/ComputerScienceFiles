#include <iostream>

using namespace std;

int main() {
	int cardAtual = 0,
		cardAnterior = 0,
		c = 0,
		d = 0;
	
	for(int i = 1; i <= 5; i++) {
		cin >> cardAtual;
		
		if(cardAtual > cardAnterior && i != 1) {
			c++;
				
		} else if(cardAnterior > cardAtual) {
			d++;	
		}
		
		cardAnterior = cardAtual;
	}
	
	if(c == 4) {
		cout << "C\n";
		
	} else if(d == 4) {
		cout << "D\n";
		
	} else if(d < 4 && c < 4) {
		
		cout << "N\n";
	}
	
	return 0;
}

#include <stdio.h>

int main() {
	int cardAtual, cardAnterior, c, d;
	
	for(int i = 1; i <= 5; i++) {
		scanf("%d", &cardAtual);
		
		if(cardAtual > cardAnterior && i != 0) {
			c++;
			
		} else if(cardAnterior > cardAtual) {
			d++;
		}
	}

	cardAnterior = cardAtual;
	
	if(c == 4) {
		print("C\n");
		
	} else if(d == 4) {
		print("C\n");
		
	} else if(c < 4 && d < 4) {
		print("N\n");
	}
	
	return 0;
}
