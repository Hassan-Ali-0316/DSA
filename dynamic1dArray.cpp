#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
using namespace std;

void bubsort(int *arr,int s)
{
	int temp;
	for(int i=0 ; i<s-1 ; i++)
	{
		for(int j=0 ; j<s-i-1 ; j++)  // 1  66  2  99  3
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int binsearch(int *arr , int l, int num)
{
	int s = 0;
	for(int i=0 ; i<=l ; i++)
	{
		int mid = (s+l)/2;
		if(arr[mid] == num)
		{
			cout << "Iteration : " << i << endl << "Mid val " << mid << endl << "act num : " << arr[mid] << endl;
			cout << "start = " <<  s << endl << "last = " << l << endl << endl; 
			return mid;
		}
		else if(num<arr[mid])
		{
			l = mid - 1;
		}
		else  // if (num > arr[mid])
		{
			s = mid + 1;	
		}
	}
	return -1;
}


void display(int *arr,int size)
{
	for(int i=0 ; i<size ; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << "\n\n";
}

int main()
{
	cout << "Enter size of array : ";
	int s; 
	cin >> s;
	srand(time(0));
	int *arr = {new int[s]{}};
	for(int i=0 ; i<s ; i++)
	{
		int r = rand() % 99;
		arr[i] = r;
	}
	
	cout << "Before sort : " << s << "\n";
	display(arr,s);
	bubsort(arr,s);
	cout << "\nAfter sort : \n";
	
	for(int i=0 ; i<s ; i++)
	{
		display(arr,s);
		cout << "\n\t"  << endl << endl;
		cout << "\nEnter number to search : ";
		int r;
		cin >> r;
		int x = binsearch(arr,s,r);
		cout << "The element position is : " << x+1 << endl << endl;
	}
	delete[] arr;
}