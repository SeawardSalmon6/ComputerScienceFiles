#include <iostream>

using namespace std;

int main() {
  int N, M, idDesc, prox, fixI;
  int max = 0, pos = 0, posDesc = 0;
  float porcentagem = 0;

  cin >> N >> M;

  int vetorDesc[N + 1];
  int vetorDescGer[N + 1];
  
  int vetorPosDesc[M + 1];
  float vetorSomaQtd[M + 1];
  float vetorPresentes[M + 1];
  
  for(int i = 0; i <= N; i++) {
      vetorDesc[i] = 0;
      vetorDescGer[i] = 0;
  }
  
  for(int i = 0; i <= M; i++) {
      vetorPresentes[i] = 0;
      vetorSomaQtd[i] = 0;
      vetorPosDesc[i] = 0;
  }

  for(int i = 1; i <= N; i++) {
    cin >> idDesc;
    vetorDesc[i] = idDesc;
  }

  for(int i = 1; i <= N; i++) {
    if(vetorDesc[i] == 0) {
      vetorDescGer[i] = 1;
      vetorSomaQtd[1]++;
      
      if(vetorDescGer[i] > max && N < 2) {
        max = 1;
      }
      
    } else {
      fixI = i;
      
      while(vetorDesc[i] != 0) {  
        prox = vetorDesc[i];
        vetorDescGer[fixI]++;

        i = prox;
      }
      
      i = fixI;
      
      vetorDescGer[i] += 1;
      vetorSomaQtd[vetorDescGer[i]]++;
    
      if(vetorSomaQtd[vetorDescGer[i]] == 1 && vetorDescGer[i] > max) {
      	max = vetorDescGer[i];
	  }
    }
  }
  
  for(int i = 1; i <= M; i++) {
    cin >> posDesc;
    vetorPosDesc[i] = posDesc;
  }
  
  for(int i = 1; i <= M; i++) {
  	pos = vetorPosDesc[i];
	
	vetorPresentes[vetorDescGer[pos]]++;
  }
  
  for(int i = 1; i <= max; i++) {
  	  porcentagem = (vetorPresentes[i] / vetorSomaQtd[i]) * 100.00;
	  	
	  cout.precision(2);
	  cout << fixed << porcentagem << " ";
  }
  
  cout << endl;
  
  return 0;
}
