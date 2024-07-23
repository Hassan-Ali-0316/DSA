#include<iostream>
#include<cstring>
using namespace std;

bool isSafe(int i,int l,string S)
{
	if(i>=0 && i<l && S[i]!=S[i+1])
	{
		return true;
	}
	return false;
}

void alternate(string S,int i,int l)
{
	if(isSafe(i+1,l,S))
	{
		alternate(S,i+1,l);
	}
	if(i == l-1)
	{
		cout << "Yes\n";
		exit(0);
	}
}

int main()
{
	string S1 = "MFMFMFMFMMMF";
	string S2 = "FM";
	alternate(S2,0,S2.length());
	cout << "NO\n";
}