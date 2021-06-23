#include <iostream>

using namespace std;

int main()
{
    int L, C, tipA, tipB;
    
    cin >> L >> C;
    
    tipA = (L * C) + ((L - 1) * (C - 1));
    tipB = ((L - 1) * 2) + ((C - 1) * 2);
    
    cout << tipA << endl;
    cout << tipB << endl;

    return 0;
}

#include <stdio.h>

int main() {
	int L, C, tipA, tipB;
	
	scanf("%d %d", &L, &C);
	
	tipA = (L * C) + ((L - 1) * (C - 1));
    tipB = ((L - 1) * 2) + ((C - 1) * 2);
	
	printf("%d\n", tipA);
	printf("%d\n", tipB);
	
	return 0;
}
