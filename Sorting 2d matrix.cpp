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
void display1d(int *arr,int size)
{
	for(int i=0 ; i<size ; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void selection(int *arr , int s)
{
	for(int i=0 ; i<s ; i++)
	{
		int current = i;
		for(int j=i+1 ; j<s ; j++)
		{
			if(arr[j]<arr[current])
			{
				current = j;
			}
		}
		if(current != i)
		{
			swap(arr[current],arr[i]);
		}
	}
}

void sort(int **arr , int row , int col)
{
	int* temp = {new int[row*col]{}};
	int k = 0;
	cout << endl;
	for(int i=0 ; i<row ; i++)
	{
		for(int j=0 ; j<col ; j++)
		{
			temp[k] = arr[i][j];
			k++;
		}
	}
	k = 0;
	int size = row*col;
	selection(temp,size);
	for(int i=0 ; i<row ; i++)
	{
		for(int j=0 ; j<col ; j++)
		{
			arr[i][j] = temp[k];
			k++;
		}
	}
}



void insertion(int *arr , int row)
{
	for(int i=1 ; i<row ; i++)
	{
		int current = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>current)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = current;
	}
}

bool doesnot(int c,int maxel[],int val)
{
	for(int i=0 ; i<c ; i++)
	{
		if(maxel[i] == val)
		{
			return 1;	
		}	
	}
	return 0;
}
void freq(int *arr,int size)
{
	int current = 0;
	int c = 0,d = 0;
	int maxel[size];
	int minel[size];
	for(int i=0 ; i<size ; i++)
	{
		current = i+1;
		if(arr[i] == arr[current] || arr[i+2] == arr[current])
		{
			maxel[c] = arr[current];
			c++;
		}
		if(arr[i] != arr[current] && doesnot(c,maxel,arr[i]) == 0)
		{ 
			minel[d] = arr[i];
			d++;
		}
	}
	cout << endl;
	int x = 0;
		for(int i=c ; i<d+c+1 ; i++)
	{
		maxel[i] = minel[x];
		x++;
	}
	cout << "concatenatoing ; \n";
	for(int i=0 ; i<c+d ; i++)
	{
		cout << maxel[i] << "    ";
	}
}

void columnsort(int **arr, int row, int col)
{
	int sum[row];
	int x = 0;
	for(int i=0 ; i<col ; i++)
	{
		for(int j=0 ; j<row ; j++)
		{
			x = x + arr[j][i];
		}
		sum[i] = x;
		x=  0;
	}
	for(int i=0 ; i<col-1 ; i++)
	{
		for(int j=0 ; j<col-i-1 ; j++)
		{
			if(sum[j]>sum[j+1])
			{
				swap(sum[j],sum[j+1]);
				for(int k=0 ; k<row ; k++)
				{
					swap(arr[k][j],arr[k][j+1]);
				}
			}
		}
		
	}
	cout << endl << endl;
	display(arr,row,col);
}


int main()
{
	int row = 3,col = 3;
	int** arr = new int*[row];
	for(int i=0 ; i<row ; i++)
	{
		arr[i] = new int[col];
	}
	srand(0);
	for(int i=0 ; i<row ; i++)
	{
		for(int j=0 ; j<col ; j++)
		{
			int r = rand() % 11;
			arr[i][j] = r;
		}
	}
	display(arr,row,col);
	columnsort(arr,row,col);
}
