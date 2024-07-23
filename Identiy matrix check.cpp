#include<iostream>
using namespace std;

int main() 
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) 
	{
        cin >> arr[i];
    }

    int min = 0,max = 0,minVal = 9999999,maxVal = 0;


	// [1,2,15,25,6,7,30,40,50]
    for (int i = 0; i < size; i++) 
	{
        if (arr[i] < maxVal) 
		{
            min = i;
        } 
		else 
		{
            maxVal = arr[i];
        }
    }

    for (int i = size - 1; i >= 0; i--) 
	{
        if (arr[i] > minVal) 
		{
            max = i+1;   // +1 cuz we will iterate till <max
        } 
		else 
		{
            minVal = arr[i];
        }
    }
//        cout << maxVal << "  " << minVal << endl << maxIndex << "  " << minIndex << endl;
  	cout << "Array : ";
	for(int i=0 ; i<size ; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << "\n\nUnsorted part of array : ";
	for(int i=max ; i<min ; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << "\n\n\t" << max << "  " << min << endl;
	for(int i=max ; i<min ; i++)         
	{
		for(int j=max ; j<min-1 ; j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j+1],arr[j]);
			}
		}
	}
	
	cout << "\n\nAfter Sorting sub-array : ";
	for(int i=0 ; i<size ; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;      
}

