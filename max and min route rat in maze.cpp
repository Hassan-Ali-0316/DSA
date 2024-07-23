#include<iostream>
using namespace std;

//bool isSafe(int ** arr, int x, int y, int n, int **sol)
//{
//	if(x<n && x>=0 && y<n && y>=0 && arr[x][y] == 1 && sol[x][y] == 0)
//	{
//		return true;
//	}
//	return false;
//}
//
//int max1 = INT_MIN;
//int min1 = INT_MAX;
//int num1 = 0;
//string maxp = "";
//string minp = "";
//void solve(int **arr, int x, int y, int n, int** sol, string sols)
//{
//	if(x == n-1 && y == n-1)
//	{
//		num1 ++;
//		sol[x][y] = 1;
//		
//		if(num1>max1)
//		{
//			max1 = num1;
//			maxp = sols;
//		}
//		if(num1<min1)
//		{
//		   	min1 = num1;
//		   	minp = sols;
//		}
//		   
// 		sol[x][y] = 0;
// 		num1--;
// 		return;
//   }
//	
//	
//	sol[x][y] = 1;
//	num1++;
//	if(isSafe(arr,x+1,y,n,sol))
//	{
//		solve(arr,x+1,y,n,sol,sols+'D');
//	}
//	if(isSafe(arr,x,y-1,n,sol))
//	{
//		solve(arr,x,y-1,n,sol,sols+'L');
//	}
//	if(isSafe(arr,x,y+1,n,sol))
//	{
//		solve(arr,x,y+1,n,sol,sols+'R');
//	}
//	if(isSafe(arr,x-1,y,n,sol))
//	{
//		solve(arr,x-1,y,n,sol,sols+'U');
//	}
//	if(isSafe(arr,x+1,y+1,n,sol))
//	{
//		solve(arr,x+1,y+1,n,sol,sols+'X');
//	}	
//	sol[x][y] = 0;
//	num1--;
//}

bool isSafe(int **arr,int **sol,int i,int j,int n)
{
	if(i>=0 && i<n && j>=0 && j<n and arr[i][j] ==1 && sol[i][j]==0)
	{
		return true;
	}
	
	return false;
}
int num1=0;
string maxp = "";
string minp = "";
int max1 = INT_MIN;
int min1 = INT_MAX;

void maze(int **arr,int **sol,int x,int y,int n,string sols)
{
	if(x==n-1 && y==n-1)
	{
		num1++;
		sol[x][y] = 1;
		if(num1>max1)
		{
			maxp = sols;
			max1 = num1;
		}
		if(num1<min1)
		{
			minp = sols;
			min1 = num1;
		}
	
		sol[x][y] = 0;
		num1--;
	}
	num1++;
	sol[x][y] = 1;
	if(isSafe(arr,sol,x,y+1,n))
	{
		maze(arr,sol,x,y+1,n,sols+'D');
	}
	if(isSafe(arr,sol,x-1,y,n))
	{
		maze(arr,sol,x-1,y,n,sols+'L');
	}
	if(isSafe(arr,sol,x+1,y,n))
	{
		maze(arr,sol,x+1,y,n,sols+'R');
	}
	if(isSafe(arr,sol,x,y-1,n))
	{
		maze(arr,sol,x,y-1,n,sols+'U');
	}
	
	sol[x][y] = 0;
	num1--;
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
	maze(arr,sol,0,0,n,sols);
	//solve(arr,0,0,n,sol,sols);
	cout << "\n\nMax Route :" << max1 << "\n";
	cout << maxp << endl;
	cout << "\n\nMin Route :" << min1 << "\n";
	cout << minp << endl;
	for (int i = 0; i < n; i++) 
	{
        delete[] arr[i];
        delete[] sol[i];
    }
    delete[] arr;
    delete[] sol;
	return 0;
}

// 1  1  1
// 1  1  1
// 0  0  1

