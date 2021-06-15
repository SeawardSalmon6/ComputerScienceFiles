#include <iostream>

using namespace std;

int main() {
	int N, D, A, min = 0;
	
	cin >> N >> D >> A;
	
	if(D > A) {
		min = D - A;
		
	} else if(A > D) {
		min = (N - A) + D;
	}
	
	cout << min << endl;
	
	return 0;
}
