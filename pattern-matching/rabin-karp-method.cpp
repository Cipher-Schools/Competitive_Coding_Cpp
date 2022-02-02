#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void rabinKarp(string T, string P){
	int n = T.length();
	int m = P.length();
	int prime = 101;
	int hp = 0;
	int ht = 0;
	for (int i = m-1; i >= 0; i--)
	{
		hp = hp*prime + ((int)(P[i]));
		ht = ht*prime + ((int)(T[i]));
	}
	bool found = false;
	for(int i = 0;i <= n-m;i++)
	{
		if(i == 0)
		{
			if(hp == ht)
			{
				int j;
				for(j = 0;j < m;j++){
					if(T[i+j] != P[j]){
						break;
					}
				}
				if(j == m){
					found = true;
				}
			}
		}else
		{
			ht = ((ht - ((int)T[i-1]))/prime) + (((int)T[i+m-1])*pow(prime,m-1));
			int j;
			for(j = 0;j < m;j++){
				if(T[i+j] != P[j]){
					break;
				}
			}
			if(j == m){
				found = true;
			}
		}
		if(found){
			cout<<i<<" ";
			found = false;
		}
	}

}
int main(int argc, char const *argv[])
{
	string T = "my name is mohit sharma mohit sharma";
	string P = "mohit";
	rabinKarp(T,P);
	return 0;
}
