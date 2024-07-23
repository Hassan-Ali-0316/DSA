#include<iostream>
using namespace std;

bool isSafe(int** arr, int** sol, int x, int y, int n)
{	
	if(x<n && x>=0 && y<n && y>=0 && arr[x][y] == 1 && sol[x][y] == 0)
	{
		return true;
	}
	return false;
}

void mine(int** arr, int** sol, int x, int y, int n)
{
	if(y == n-1)
	{
		cout << "Length of shortest safe route is " << len << endl;
		return;
	}
	sol[x][y] = 1;
	if(isSafe(arr,sol,x+))
}
int main()
{
	
}


//   1  0  1  1
//   1  1  0  0
//   1  1  1  1 
//   1  1  1  1