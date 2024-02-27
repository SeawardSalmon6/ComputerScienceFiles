#include <iostream>

using namespace std;

int main() {
    int iddMonica, filhoA, filhoB, filhoC;
    
    cin >> iddMonica >> filhoA >> filhoB;
    
    filhoC = iddMonica - (filhoA + filhoB);
    
    if(filhoC > filhoA && filhoC > filhoB) {
        cout << filhoC << endl;
        
    } else if(filhoB > filhoA && filhoB > filhoC) {
        cout << filhoB << endl;
        
    } else if(filhoA > filhoB && filhoA > filhoC) {
        cout << filhoA << endl;
    }
    
    return 0;
}
