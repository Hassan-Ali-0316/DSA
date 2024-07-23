
#include<iostream>
using namespace std;

bool isSafe(int** arr,int x, int y, int n, int** sol)
{
//	if(x<n && y<n && x>=0 && y>=0 && arr[x][y] == 1 && sol[x][y] == 0)
//	{
//		return true;
//	}
//	return false;
    return (x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1 && sol[x][y] == 0);
}

void Maze(int **arr, int x, int y, int n, int **sol, string sols)
{
	if(x == n-1 && y == n-1)
	{
		sol[x][y] = 1;
		cout << endl << "Solution :\n";
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				cout << sol[i][j] << "  ";
			}
			cout << endl;
		}
		cout << "\n\n" << "   Paths : " << sols << endl;
		sol[x][y] = 0;
		return;
	}
	sol[x][y] = 1;                                    // remember D L R U
	if(isSafe(arr,x+1,y,n,sol))
	{
		Maze(arr,x+1,y,n,sol,sols+'D');
	}
	if(isSafe(arr,x,y-1,n,sol))
	{
		Maze(arr,x,y-1,n,sol,sols+'L');
	}
	if(isSafe(arr,x,y+1,n,sol))
	{
		Maze(arr,x,y+1,n,sol,sols+'R');
	}
	if(isSafe(arr,x-1,y,n,sol))
	{
		Maze(arr,x-1,y,n,sol,sols+'U');
	}
	if(isSafe(arr,x+1,y+1,n,sol))
	{
		Maze(arr,x+1,y+1,n,sol,sols+'X');
	}
	sol[x][y] = 0;
}

int main()
{
	int n;
	cout << "Enter size of matrix : ";
	cin >> n;
	int ** arr = new int*[n];
	int ** sol = new int*[n];
	for(int i=0 ; i<n ; i++)
	{
		arr[i] = new int[n];	
		sol[i] = new int[n];
	}	
	cout << "Enter maze : \n";
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			cout << "Enter " << i+1 << " and " << j+1 << " : ";
			cin >> arr[i][j];  
			sol[i][j] = 0;
		}
	}
	cout << endl << endl;
	string sols = "";
	
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	Maze(arr,0,0,n,sol,sols);
	
	for (int i = 0; i < n; i++) 
	{
        delete[] arr[i];
        delete[] sol[i];
    }
    delete[] arr;
    delete[] sol;
	return 0;
}



// 1  0  0
// 0  1  0
// 0  0  1

// 1 1 0 1
// 1 1 1 1
// 1 0 0 1
// 0 1 0 1

// 1 0 1 1 1 1 
// 1 0 1 0 0 1
// 1 0 1 1 0 1
// 1 1 1 1 0 1
// 0 1 0 0 0 1