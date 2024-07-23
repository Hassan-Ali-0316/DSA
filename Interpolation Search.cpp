#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// interpolation search is best when array is sorted and elements of array are uniformally distributed.
// binary search take O(logn) time
// advance version of binary search
// binary search always go to middle element while interpolation may go to different locations according to the value of the key being searched

void sort(int *arr,int n)
{
	for(int i=1 ; i<n ; i++)
	{
		int key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
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

int interpolation(int *arr,int n,int num)
{
	int l = 0;
	int u = n-1;
	while(l<=u && num >= arr[l] && num <= arr[u])
	{
		 // Probing the position with keeping
        // uniform distribution in mind.
        int pos = l + (((double)(u - l) / (arr[u] - arr[l])) * (num - arr[l]));
        
        if(arr[pos] == num)
        {
        	return pos;
		}	
		else if(arr[pos]<num)          // 1 2 3 4 5 6 7 8 9
		{
			l = pos + 1;
		}
		else
		{
			u = pos - 1;
		}
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
	for(int i=0 ; i<n ; i++)
	{
		cout << "Enter number to search : ";
		int num;
		cin >> num;
		int x = interpolation(arr,n,num);
		cout << "Number found at : " << x << endl << endl;
	}
	cout << endl;
	delete[] arr;
	arr = NULL;
}