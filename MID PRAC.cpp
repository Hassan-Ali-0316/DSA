#include<iostream>
using namespace std;

bool isSafe(int **arr,int x,int y,int m,int n,int **sol)
{
	if(x<n && y<n && x>=0 && y>=0 && arr[x][y] == 1 && sol[x][y] == 0)
	{
		return true;	
	}	
	return false;
}

int maxi = 0;
int sum = 0;

void display(int **arr,int m,int n)
{
	for(int i=0 ; i<m ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
}

void maxPaths(int **arr,int x,int y,int m,int n,int **sol)
{
	if(x == m-1 && y == n-1)
	{
		maxi++;
		sol[x][y] = 1;
		sol[x][y] = 0;
		return;
	}
	sol[x][y] = 1;
	sum++;
	
	if(isSafe(arr,x+1,y,m,n,sol))
	{
		maxPaths(arr,x+1,y,m,n,sol);
	}
	if(isSafe(arr,x,y+1,m,n,sol))
	{
		maxPaths(arr,x,y+1,m,n,sol);
	}
	sol[x][y] = 0;
	sum--;
}

int main()
{
	int m,n;
	cout << "Enter rows : ";
	cin >> m;
	cout << "Enter columns : ";
	cin >> n;
	
	int **sol = new int*[m];
	int **arr = new int*[m];
	for(int i=0 ; i<m ; i++)
	{
		sol[i] = new int [n];
		arr[i] = new int[n];	
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
	display(arr,m,n);
	maxPaths(arr,0,0,m,n,sol);
	cout << "\n\nMAX : "  << maxi << endl;
	
	for(int i=0 ; i<m ; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}