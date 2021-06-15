#include <stdio.h>

int main() {
	int M, N, pares = 0, i;
	char L;
	
	int vetorEsq[61] = { 0 };
	int vetorDir[61] = { 0 };
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++) {
		scanf(" %d %c", &M, &L);
		
		if(L == 'D') {
			vetorDir[M]++;
			
		} else {
			vetorEsq[M]++;
		}
	}
	
	for(i = 30; i <= 60; i++) {
	
		if(vetorDir[i] < vetorEsq[i]) {
			pares += vetorDir[i];
			
		} else {
			pares += vetorEsq[i];
		}
	}
	
	printf("%d\n", pares);
	
	return 0;
}
