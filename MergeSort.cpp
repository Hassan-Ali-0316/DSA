#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;


void merge(int *arr,int s,int mid,int e)
{
	int n1 = mid-s+1;
	int n2 = e-mid;
	int a[n1];
	int b[n2];
	
	int k=s;
	for(int i=0 ; i<n1 ; i++)
	{
		a[i] = arr[k];
		k++;
	}
	k = mid+1;
	for(int i=0 ; i<n2 ; i++)
	{
		b[i] = arr[k];
		k++;
	}
	int i=0;
	int j=0;
	k=s;
	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
		{
			arr[k] = a[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = b[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		arr[k] = a[i];
		k++;
		i++;
	}
	while(j<n2)
	{
		arr[k] = b[j];
		k++;
		j++;
	}
}

void mergeSort(int *arr,int s,int e)
{
	if(s<e)
	{
		int mid = ((s+e)/2);
		mergeSort(arr,s,mid);
		mergeSort(arr,mid+1,e);
		
		merge(arr,s,mid,e);
	}
}

void display(int *arr,int n)
{
	for(int i=0 ; i<n ; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}


int main()
{
	cout << "Enter size of array : ";
	int n;
	cin >> n;
	int *arr = new int[n];
	srand(time(0));
	for(int i=0 ; i<n ; i++)
	{
		int r = rand() % 500;
		arr[i] = r;	
	}	
	cout << "\nBefore Sorting : ";
	display(arr,n);
	cout << "\nAfter Sorting in ascending order : ";
	mergeSort(arr,0,n-1);
	display(arr,n);
	cout << endl;
	
	cout << "\nAfter Sorting in descending order : ";
	mergeSortas(arr,0,n-1);
	display(arr,n);
	
	delete[] arr;
	arr = NULL;
}

// merge sort works on divide and conquer rule
// it divides input array in two halves calls itself for the two halves recursively(before mid array and after mid array) and then merges again

// time complexity is O(nlog(n))