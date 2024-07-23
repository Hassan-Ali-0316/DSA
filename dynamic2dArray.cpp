#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	int rows,cols;
	cout << "Enter number of row : ";
	cin >> rows;
	cout << "Enter number of columns : ";
	cin >> cols;
	
	int** dynamic2darr = new int*[rows];
	for(int i=0 ; i<rows ; i++)
	{
		dynamic2darr[i] = new int[cols];
	} 
	
	cout << endl << endl;
	for(int i=0 ; i<rows ; i++)
	{
		for(int j=0 ; j<cols ; j++)
		{
			cout << "Enter element of row " << i+1 << "and column " << j+1 << "\t";
			cin >> dynamic2darr[i][j];	
		}
	}
	
	for(int i=0 ; i<rows ; i++)
	{
		for(int j=0 ; j<cols ; j++)
		{
			cout << dynamic2darr[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i=0 ; i<rows ; i++)
	{
		delete[] dynamic2darr[i];
	}
	delete[] dynamic2darr;
}