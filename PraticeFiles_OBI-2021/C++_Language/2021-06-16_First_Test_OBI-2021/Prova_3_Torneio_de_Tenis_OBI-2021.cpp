#include <iostream>

using namespace std;

int main() {
	char resultJogo;
	int grupo;
	int vitoria = 0;
	
	for(int i = 1; i <= 6; i++) {
		cin >> resultJogo;
		
		if(resultJogo == 'V') {
			vitoria++;	
		}
	}
	
	if(vitoria >= 5) {
		cout << "1" << endl;
		
	} else if(vitoria >= 3 && vitoria < 5) {
		cout << "2" << endl;
		
	} else if(vitoria >= 1 && vitoria < 3) {
		cout << "3" << endl;
		
	} else {
		cout << "-1" << endl;
	}
	
	return 0;
}
