#include<iostream>
#include<ctime>
#include<cstdlib>
#include <bits/stdc++.h>
#include<chrono>
// pivot : any element in array can be chosen as pivot
// After first pass all the elements less than pivot element will be on left and elements that are greater will be at right hand 
// more efficient than merge sort in terms of space
// time complexity same as merge sort i.e O(nlogn)
using namespace std;


void display(string *arr,int n)
{
	for(int i=0 ; i<n ; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl << endl;
}

int partitionStart(int *arr,int s,int e) // with pivot as starting element
{
	int pivot = arr[s];
	int pIndex = e;

	for(int i=e ; i>s ; i--)
	{
		if(arr[i]>pivot)
		{
			swap(arr[i],arr[pIndex]);
			pIndex--;
		}
	}
	swap(arr[pIndex],arr[s]);
	return (pIndex);
}

void quickSortStart(int *arr,int s,int e)
{
	if(s<e)
	{
		int pIndex = partitionStart(arr,s,e);
		quickSortStart(arr,s,pIndex-1);
		quickSortStart(arr,pIndex+1,e);
	}
}

int partitionEnd(int *arr,int s,int e)
{
	int pivot = arr[e];
	int pIndex = s;
	
	for(int i=s ; i<e ; i++)
	{
		if(arr[i]<pivot)
		{
			swap(arr[i],arr[pIndex]);
			pIndex++;
		}
	}
	swap(arr[pIndex],arr[e]);
	return (pIndex);
}


void quickSortEnd(int *arr,int s,int e)
{
	if(s<e)
	{
		int pIndex = partitionEnd(arr,s,e);	
		quickSortEnd(arr,s,pIndex-1);
		quickSortEnd(arr,pIndex+1,e);
	}
}

int partition(string *str,int s,int e)
{
	string pivot = str[e];
	int pIndex = s;
	
	for(int i=s ; i<e ; i++)
	{
		if(str[i]<pivot)
		{
			swap(str[i],str[pIndex]);
			pIndex++;
		}
	}
	swap(str[e],str[pIndex]);
	return pIndex;
}

void quickSort(string *arr,int s,int e)
{
	if(s<e)
	{
		int p = partition(arr,s,e);
		
		quickSort(arr,s,p-1);
		quickSort(arr,p+1,e);
	}
}

int main()
{
	cout << "Enter size of array : ";
	int n;
	cin >> n;
	string *arr = new string[n];
	srand(time(0));
	int j = 6;
	for(int i=0 ; i<n ; i++)
	{
		int r = 65 + j;
		j--;
		char x = static_cast<char>(r);
		arr[i] = x;	
	}	
	cout << "\nBefore Sorting : ";
	display(arr,n);
	quickSort(arr,0,n-1);
	cout << "\nAfter Sorting : ";
	
	display(arr,n);
	cout << endl;
}