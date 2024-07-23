#include<iostream>
using namespace std;

void heapify(int *arr,int s,int i)
{
	int smallest = i;
	int l = ((2*i)+1);
	int r = ((2*i)+2);
	
	if(l<s && arr[l]>arr[smallest])
	{
		smallest = l;
	}
	if(r<s && arr[r]>arr[smallest])
	{
		smallest = r;
	}
	if(smallest != i)
	{
		swap(arr[i],arr[smallest]);
		heapify(arr,s,smallest);
	}
}

void heapSort(int *arr,int s)
{
	for(int j=((s/2)-1) ; j>=0 ; j--)
	{
		heapify(arr,s,j);
	}
	for(int i=s-1 ; i>0 ; i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}

void display(int *arr,int s)
{
	for(int i=0 ; i<s ; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int main()
{
	int size = 6;
	int *arr = new int[size]{7,10,4,3,20,15};
	cout << "Array: ";
	display(arr,size);
	heapSort(arr,size);
	cout << endl;
	display(arr,size);
	delete[] arr;
}