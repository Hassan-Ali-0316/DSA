#include<iostream>
#define d 256
using namespace std;

void search(string pat,string txt,int q)
{
	int m = pat.length();
	int n = txt.length();
	int p = 0;            // hash value for pattern
	int t = 0;			  // hash value for text
	int h = 1;
	int j = 0;
	
	for(int i=0 ; i<m-1 ; i++)
	{
		h = (h*d) % q; // h = 65536
	}
	// calculating hash value of pattern and first window of text
	for(int i=0 ; i<m ; i++)
	{
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}
	for(int i=0 ; i<=n-m ; i++)
	{
		if(p == t)
		{
			for(j=0 ; j<m ; j++)
			{
				if(txt[i+j] != pat[j])
				{
					break;
				}
			}
			if(j == m)
			{
				cout << "pattern?\n";
			}
		}
		if(i<n-m)
		{
			t = (d*(t-txt[i]*h)+txt[i+m])%q;
			
			if(t<0)
			{
				t = t+q;
			}
		}
	}
}

int main()
{
	string txt = "GEEKS FOR GEEKS";
	string pat = "GEEK";
	
	int q = INT_MAX;
	search(pat,txt,q);
}