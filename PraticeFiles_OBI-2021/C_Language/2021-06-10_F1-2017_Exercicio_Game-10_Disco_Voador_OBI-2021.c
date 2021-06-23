#include <stdio.h>

int main() {
	int N, D, A, min = 0, i;
	
	scanf("%d %d %d", &N, &D, &A);
	
	if(D > A) {
		min = D - A;
		
	} else if(A > D) {
		min = (N - A) + D;
	}
	
	printf("%d\n", min);
	
	return 0;
}
