#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define CharCount 256

void badCharHeuristics(string P,int m, int badchar[])
{
	for(int i = 0; i< CharCount; i++)
	{
		badchar[i] = -1;
	}
	for(int i = 0; i < m; i++)
	{
		badchar[P[i]] = i;
	}
}
void boyreMoorePatternSearching(string T, string P)
{
	int n = T.length();
	int m = P.length();
	int badchar[CharCount];
	badCharHeuristics(P, m, badchar);
	int s = 0;
	while(s <= (n-m))
	{
		int j = m-1;
		while(j >=0 && T[s+j] == P[j])
		{
			j--;
		}

		if(j<0){
			cout<<s<<" ";
			s += ((s+m < n)? (m - badchar[T[s+m]]):1);
		}else{
			s += max(1, j - badchar[T[s+j]]);
		}
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	string T = "this is a test string";
	string P = "test";
	boyreMoorePatternSearching(T,P);
	return 0;
}
