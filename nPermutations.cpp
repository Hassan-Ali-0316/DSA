#include<iostream>
using namespace std;

bool isSafe(char el,char *safe,int index)
{
	for(int i=0 ; i<index ; i++)
	{
		if(safe[i] == el)
		{
			return false;
		}
	}
	return true;	
}

void func(char *arr,int n,char *safe, int index)
{
	if(index == n)
	{
		for(int i=0 ; i<n ; i++)
		{
			cout <<safe[i];
		}
		cout << endl;
		return;
	}
	
	for(int i=0 ; i<n ; i++)
	{
		if(isSafe(arr[i],safe,index))
		{
		 safe[index] = arr[i];
			func(arr,n,safe,index+1);
		}
	}
}

int main()
{
	int n;
	cout << "Enter num ";   // if n = 4 then alphabets are a,b,c,d
	cin >> n;
	char safe[n];
	char arr[n];
	for(int i=0 ; i<n ; i++)  
	{
		arr[i] = i+65;
	}
	func(arr,n,safe,0);
}