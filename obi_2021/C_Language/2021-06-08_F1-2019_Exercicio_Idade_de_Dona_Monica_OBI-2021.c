#include <stdio.h>

int main()
{
    int iddMonica, filhoA, filhoB, filhoC;
    
    scanf("%d %d %d", &iddMonica, &filhoA, &filhoB);
    
    filhoC = iddMonica - (filhoA + filhoB);
    
    if(filhoA > filhoB && filhoA > filhoC) {
        printf("%d\n", filhoA);
        
    } else if(filhoB > filhoA && filhoB > filhoC) {
        printf("%d\n", filhoB);
        
    } else if(filhoC > filhoB && filhoC > filhoA){
        printf("%d\n", filhoC);
    }

    return 0;
}
