/*

	Rabin Kalp algorithm matches hash value of the pattern with the hash value of the current sub string of text and if the hash value matches
	then only it starts matching indiviual characters
	
	In rabin kalp, hash value is calculated using rolling hash function, which allows you to update hash value for a new sub string by 
	efficiently removing contribution of old characters and adding contribution of new character 

*/

#include<iostream>
using namespace std;

void search(string pat,string text,int q)
{
	int m = pat.length();
	int n = text.length();
	int i,j;
	int p = 0;   // hash value for pattern
	int t = 0;  //  hash value for text
 	int h = 1;
 	int d = 256;
 	for(int i=0 ; i<m-1 ; i++)
 	{
 		h = (h*d)%q;
	}
 	for(int i=0 ; i<m ; i++)                                      
 	{
 		p = (d*p + pat[i]) % q;        
		t = (d*t + text[i]) % q;	
	}
	cout << "Pattern hash: " << p << endl << "Text hash: " << t << endl;
	for(int i=0 ; i<=n-m ; i++)
	{
		if(p == t)
		{
			bool found = true;
			for(int j=0 ; j<m ; j++)
			{
				if(text[i+j] != pat[j])
				{
					found = false;
					break;
				}
			}
			if(found)
			{
				cout << "Pattern found at index i = " << i << endl;
			}
		}
		if(i<n-m)
		{
			t = (d * (t - text[i]*h) + text[i+m]) % q;
			if(t<0)
			{
				t = t+q;
			}
		}
	}
}

int main()
{
	string text = "ACCDEFGHABJKLDMABKKIANAB";
	string pat = "AB";
	
	int q = 101;
	
	search(pat,text,q);	
}