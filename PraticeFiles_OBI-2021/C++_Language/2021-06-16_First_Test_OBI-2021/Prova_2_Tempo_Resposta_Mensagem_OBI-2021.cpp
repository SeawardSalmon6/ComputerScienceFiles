#include <iostream>

using namespace std;

int main() {
	int numReg;
	int amigo   = 0,
		max     = 0;
	char verify = 'S';
	
	cin >> numReg;
	
	char id[numReg]     = { 0 };
	int num[numReg]     = { 0 },
		timer[101]      = { 0 },
		counterRec[101] = { 0 },
		counterEnv[101] = { 0 };
	
	for(int i = 0; i < numReg; i++) {
		cin >> id[i];
		cin >> num[i];
		
		if(num[i] > max) {
			max = num[i];
		}

		if(id[i] == 'R') {
			counterRec[num[i]]++;
			
		} else if(id[i] == 'E') {
			counterEnv[num[i]]++;
		}
	}
	
	for(int i = 0; i <= max; i++) {
		if(counterRec[i] != counterEnv[i]) {
			counterRec[i] = -1;
			counterEnv[i] = -1;
		}
	}
	
	while(verify != 'Q')
	{
		for(int t = amigo + 1; t <= max; t++)
		{
			if(counterRec[t] > 0)
			{
				amigo = t;
				break;
			}
			else if(counterRec[t] == -1 && t != max)
			{
				amigo = t;
				break;
			}
			else if(t == max) { verify = 'Q'; amigo = t; }
		}
		
		for(int i = 0; i < numReg; i++)
		{	
			if(verify != 'Q')
			{
			    if(id[i] == 'E' && num[i] == amigo) {
					verify = 'E';

				} else if(id[i] == 'R' && num[i] == amigo && counterRec[amigo] > 0) {
					verify = 'S';
				}
    			
    			if(verify == 'S')
    			{
    			    if(id[i] == 'T') {
    			        timer[amigo] += num[i] - 1;
    			        
    			    } else if(counterRec[amigo] > 0) {
    			        timer[amigo]++;
    			    }
    			}
    			
			} else { break; }
		}
		
		if(counterRec[amigo] == -1) {
			cout << amigo << " -1\n";
		
		} else if(counterRec[amigo] > 0) {
			cout << amigo << " " << timer[amigo] << endl;
		}
	}
	
	return 0;
}
