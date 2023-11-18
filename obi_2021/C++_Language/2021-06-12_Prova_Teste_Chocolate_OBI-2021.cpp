#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int N, X1, X2, Y1, Y2;
	double distancia;
	
	cin >> N >> X1 >> Y1 >> X2 >> Y2;
	
	distancia = sqrt((pow((X2 - X1), 2) + pow((Y2 - Y1), 2)));
	
	if(distancia >= N / 2) {
		cout << "S\n";
	} else {
		cout << "N\n";
	}
	
	return 0;
}
