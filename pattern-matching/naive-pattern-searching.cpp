#include <iostream>
#include <string>
using namespace std;

void naivePatternSearching(string T,string P){
	int n = T.length();
	int m = P.length();
	int i, j;
	for (i = 0; i <= n-m; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			if(T[i+j] != P[j])
			{
				break;
			}
		}
		if(j == m)
		{
			cout<<i<<" ";
		}
	}
}
int main(int argc, char const *argv[])
{
	string T = "my name is mohit sharma mohit sharma";
	string P = "mohit";
	naivePatternSearching(T,P);
	return 0;
}
