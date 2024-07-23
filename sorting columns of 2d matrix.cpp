#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void display(int **arr , int row , int col)
{
	for(int i=0 ; i<row ; i++)
	{
		for(int j=0 ; j<col ; j++)
		{
			cout << arr[i][j] << "   ";
		}
		cout << endl;
	}
}

void selection(int **arr , int row , int col)
{
	int k = 0;
	for(int i=0 ; i<row ; i++)
	{
		for(int j=0 ; j<col ; j++)
		{
			int current = j;
			for(k=j+1 ; k<row-1 ; k++)
			{
				if(arr[k][j]<arr[current][j])
				{
					current = k;
				}
			}
			if(current != j)
			{
				swap(arr[k][j],arr[current][j]);
			}
		}
	}
	
}

void sort(int **arr , int row , int col)
{
	for(int i=0 ; i<row ; i++)
	{
		for(int j=0 ; j<col ; j++)
		{
			for(int k=0 ; k<row-1 ; k++)
			{
				if(arr[k][j] > arr[k+1][j])
				{
					swap(arr[k+1][j],arr[k][j]);
				}
			}
		}
	}
	cout << endl;
	display(arr,row,col);
}

int main()
{
	int row = 3;
	int col = 3;
	int ** arr = new int*[row];
	for(int i=0 ; i<row ; i++)
	{
		arr[i] = new int[col];
	}
	srand(time(0));
	for(int i=0 ; i<row ; i++)
	{
		for(int j=0 ; j<col ; j++)
		{
			int r = rand() % 100;
			arr[i][j] = r;
		}
	}
	display(arr,row,col);
	sort(arr,row,col);
	cout << endl << endl;
	display(arr,row,col);
	cout << endl;
	for(int i=0 ; i<row ; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}