#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n)
{
	for(int i=0 ; i<x ; i++)             // for row
	{
		if(arr[i][y] == 1)
		{
			return false;
		}
	}
	int row = x;
	int col = y;
	while(row>=0 && col>=0)
	{
		if(arr[row][col] == 1)
		{
			return false;
		}
		row--;
		col--;
	}
	row = x;
	col = y;
	while(row>=0 && col<n)
	{
		if(arr[row][col] == 1)
		{
			return false;
		}
		row--;
		col++;
	}
	return true;
}

bool nQueen(int **arr, int x, int n)
{
	if(x>=n)
	{
		cout << "Solution is : \n";
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {   
                cout << arr[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
	}
	for(int col=0 ; col<n ; col++)
	{
		if(isSafe(arr,x,col,n))
		{
			arr[x][col] = 1;
			if(nQueen(arr,x+1,n))
			{
				return true;
			}
			arr[x][col] = 0;  // back track
		}
	}
	return false;
}

int main()
{
	int n;
	cout << "Enter size of matrix : ";
	cin >> n;
	int ** arr = new int*[n];
	for(int i=0 ; i<n ; i++)
	{
		arr[i] = new int[n];	
	}	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			arr[i][j] = 0;
		}
	}
	cout << endl << endl;
	
	if(nQueen(arr,0,n))
	{
		cout << "no more sol found : \n";
	}
	else
	{
		cout << "No sol found\n";
	}
	
	for (int i = 0; i < n; i++) 
	{
        delete[] arr[i];
    }
    delete[] arr;
	return 0;
}