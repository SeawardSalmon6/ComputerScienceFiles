#include <iostream>

using namespace std;

int main() {
	int M, N, pares = 0;
	char L;
	
	int vetorEsq[61] = { 0 };
	int vetorDir[61] = { 0 };
	
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> M >> L;
		
		if(L == 'D') {
			vetorDir[M]++;
			
		} else {
			vetorEsq[M]++;
		}
	}
	
	for(int i = 30; i <= 60; i++) {
	
		if(vetorDir[i] < vetorEsq[i]) {
			pares += vetorDir[i];
			
		} else {
			pares += vetorEsq[i];
		}
	}
	
	cout << pares << endl;
	
	return 0;
}
