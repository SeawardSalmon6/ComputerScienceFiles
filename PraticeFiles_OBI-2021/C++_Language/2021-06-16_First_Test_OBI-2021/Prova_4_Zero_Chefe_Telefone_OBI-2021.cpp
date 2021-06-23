#include <iostream>

using namespace std;

int main() {
	int numReg;
	int	soma = 0,
		cont = 0;
	
	cin >> numReg;
	
	int num[numReg] = { 0 };
	
	for(int i = 0; i < numReg; i++) {
		cin >> num[i];
	}
	
	for(int i = 0; i < numReg; i++) {	
		if(num[i] == 0) {
		    
		    while(num[i - cont] == 0) {
		        cont++;
		    }
		    
		    soma -= num[i - cont];
		    num[i - cont] = 0;
		    cont = 0;
			
		} else {
			soma += num[i];
		}
	}
	
	cout << soma << endl;
	
	return 0;
}
