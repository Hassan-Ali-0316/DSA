#include<iostream>
using namespace std;

void display(string **arr,int n)
{
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

bool found(string **arr,int x,int y,int n)
{
	if(x>=0 && y>=0 && x<n && y<n && arr[x][y] == "*")
	{
		return true;
	}
	return false;
}

void chess(string **arr,int x,int y,int n,int row,int col)
{
	if(x == n-1 && y == n-1 && (!found(arr,x,y,n)))
	{
		return;
	}
	if(found(arr,x,y,n))
	{
		char c = static_cast<char>(col);
		cout << c << row << endl;
	}
	if(y == n-1 && x!=n-1)
	{
		x = x+1;
		y = 0;
		col = 65;
		row = row-1;
	}
	chess(arr,x,y+1,n,row,col+1);	
}

int main()
{
	int n = 8;
	string **arr = new string*[n];
	for(int i=0 ; i<n ; i++)
	{
		arr[i] = new string[n];
	}
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << endl;
	display(arr,n);
	cout << endl;
	chess(arr,0,0,n,8,65);
	for(int i=0 ; i<n ; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}