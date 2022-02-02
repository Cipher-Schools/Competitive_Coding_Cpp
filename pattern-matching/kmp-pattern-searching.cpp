#include <iostream>
#include <string>
using namespace std;

void prefixTable(string P, int m, int* F)
{
	int i = 1;
	int j = 0;
	F[0]= 0;
	while(i < m)
	{
		if(P[i] == P[j]){
			F[i] = j+1;
			i++;
			j++;
		}else{
			if(j > 0){
				j = F[j-1];
			}else{
				F[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearching(string T, string P)
{
	int n = T.length();
	int m = P.length();
	int i = 0;
	int j = 0;
	int prefixtable[m];
	prefixTable(P, m , prefixtable);
	while(i < n)
	{
		if(T[i] == P[j])
		{
			i++;
			j++;
		}
		if(j == m){
			cout<<i-j<<" ";
			j = prefixtable[j-1];
		}else if(i < n && P[j] != T[i]){
			if(j>0){
				j = prefixtable[j-1];
			}else{
				i++;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	string T = "my name is mohit sharma mohit sharma";
	string P = "mohit";
	KMPSearching(T,P);
	return 0;
}
