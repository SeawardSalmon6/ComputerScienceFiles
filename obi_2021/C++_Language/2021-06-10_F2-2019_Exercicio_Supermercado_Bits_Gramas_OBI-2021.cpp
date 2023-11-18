#include <iostream>

using namespace std;

int main() {
	int N, G;
	double P = 0,
		   menorP = 1000.00,
		   valAtual = 0.00;
	
	cin >> N;
	
	for(int i = 1; i <= N; i++) {
		cin >> P >> G;
		
		valAtual = (1000.00 * P) / G;
		
		if(valAtual <= menorP) {
			menorP = valAtual;
		}
	}
	
	cout.precision(2);
	cout << fixed << menorP << endl;
	
	return 0;
}
