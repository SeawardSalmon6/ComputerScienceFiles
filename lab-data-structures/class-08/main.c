#include <stdlib.h>
#include "grafo.h"

int main(){
	Grafo g = criaGrafo();
	
	readGraph(g, "grafo.txt");
	printGraph(g);
	
	return 0;
}



