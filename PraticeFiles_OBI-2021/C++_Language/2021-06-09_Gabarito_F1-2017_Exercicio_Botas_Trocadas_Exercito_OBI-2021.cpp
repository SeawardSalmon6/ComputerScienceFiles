#include <iostream>

using namespace std;

int main() {
	int N, M;
	char L;
	int total = 0, vetorD[61], vetorE[61];
	
	cin >> N;
	
	// zerando os valores dispon?veis nos vetores
	for(int i = 0; i <= 60; i++) {
		vetorD[i] = 0;
		vetorE[i] = 0;
	}
	
	
	for(int i = 0; i < N; i++) {
		cin >> M >> L; // fazendo a leitura do tamanho e do lado
		
		if(L == 'E') { // compara se o lado ? o ESQUERDO
			vetorE[M]++; // se for o esquerdo, adiciona-se 1 ao vetor na posi??o do tamanho
			
		} else {
			vetorD[M]++; // se for o direito, adiciona-se 1 ao vetor na posi??o do tamanho
		}
	}
	
	for(int i = 30; i <= 60; i++) {
		if(vetorD[i] < vetorE[i]) {
			total += vetorD[i];
			
		} else {
			total += vetorE[i];
		}
	}
	
	cout << total << endl;
	
	return 0;
}

