#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;


void display(int *arr,int n)
{
	for(int i=0 ; i<n ; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void sort(int *arr,int n)
{
	for(int i=0 ; i<n ; i++)
	{
		int current = i;
		for(int j=i+1 ; j<n ; j++)
		{
			if(arr[j]<arr[current])
			{
				current = j;
			}
		}
		if(current != i)
		{
			swap(arr[i],arr[current]);
		}
	}
}


int binarySearch(int *arr,int n,int num)
{
	int i = 0;
	int l = 0;
	int u = n-1;
	while(l<=u)
	{
		int mid = ((l+u)/2);
		if(arr[mid] == num)                //     1 2 3 4 5 6 7 8 9 10
		{
			cout << "Iteration : " << i << endl << "Mid val " << mid << endl << "act num : " << arr[mid] << endl;
			cout << "Current start = " <<  l << endl << "Current last = " << u << endl << endl; 	
			return mid;
		}
		else if(arr[mid]<num)
		{
			l = mid + 1;
		}
		else // if (arr[mid]>num]
		{
			u = mid - 1;
		}
		i++;
	}
	return -1;
}

int binRec(int *arr,int l,int u,int num,int mid)
{
	mid = ((l+u)/2);
	if(arr[mid] == num)
	{
		return mid;
	}
	else if(arr[mid]<num)    // 1 2 3 4 5 6 7 8 9 10
	{
		return binRec(arr,mid+1,u,num,mid);
	}
	else 
	{
		return binRec(arr,l,u-1,num,mid);
	}
	return -1;
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
	cout << "\nAfter Sorting : ";
	sort(arr,n);
	display(arr,n);
	cout << endl;
	for(int i=0 ; i<2 ; i++)
	{
		cout << "Enter number to search : ";
		int num;
		cin >> num;
		int x = binarySearch(arr,n,num);
		cout << "Number found at : " << x << endl << endl;
	}
	cout << endl;
	cout << "Enter number to search through recursion : ";
	int num;
	cin >> num;
	int x = binRec(arr,0,n-1,num,0);
	cout << "Number Found at Index position : " << x << endl;
	delete[] arr;
	arr = NULL;
}