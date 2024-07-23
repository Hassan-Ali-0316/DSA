#include<iostream>
using namespace std;


bool found = 0;
bool isSafe(char **arr,int x,int y,int m,int n,int **sol)
{
	if(x<m && y<n && x>=0 && y>=0 && arr[x][y] == 'E' && arr[x+1][y] != 'E' && arr[x][y+1] != 'E' && sol[x][y] == 0)
	{
		found = 1;
		return true;
	}
	found = 0;
	return false;
}
int x1 = 0;
int y1 = 0;

void Parking(char **arr,int x,int y,int m,int n,int **sol)
{
	if(found)
	{
		sol[x][y] = 1;
		x1 = x;
		y1 = y;
		cout << x << "   " << y << endl;
		for(int i=0 ; i<m ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				cout << sol[x][y] << "  ";
			}
			cout << endl;
		}
		sol[x][y] = 0;
		return;
	}
	sol[x][y] = 1;
	
	if(isSafe(arr,x+1,y,m,n,sol))
	{
		Parking(arr,x+1,y,m,n,sol);
	}
	if(isSafe(arr,x,y+1,m,n,sol))
	{
		Parking(arr,x,y+1,m,n,sol);
	}
	cout << "v";
	sol[x][y] = 0;
}

int main()
{
	int m = 3;
	int n = 5;
	char **arr = new char*[m];
	int **sol = new int*[m];
	for(int i=0 ; i<m ; i++)
	{
		arr[i] = new char[n];
		sol[i] = new int[n];
	}
	
	for(int i=0 ; i<m ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			cin >> arr[i][j];
			sol[i][j] = 0;
		}
	}
	cout << endl;
	for(int i=0 ; i<m ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	
	for(int i=0 ; i<m ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(arr[i][j] == 'E')
			{
				Parking(arr,i,j,m,n,sol);
				x1 = 0;
				y1 = 0;
			}	
		}	
	}	
	
	for(int i=0 ; i<m ; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

// S  E  E  P  P
// E  P  E  E  P
// E  E  P  P  P