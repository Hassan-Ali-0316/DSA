//#include<iostream>
//#include<cstdlib>
//#include<bits/stdc++.h>
//#include<ctime>
//using namespace std;
//
//
//void shell(int *arr, int size)
//{
//	for(int gap=size ; gap>=1 ; gap = gap/2)
//	{
//		for(int j=gap ; j<size ; j++)
//		{
//			for(int i=j-gap ; i>=0 ; i = i-gap)
//			{
//				if(arr[i+gap]>arr[i])
//				{
//					break;
//				}
//				else
//				{
//					swap(arr[i+gap],arr[i]);
//				}
//			}
//		}
//	}
//}
//// best = nlogn
//// worst = n^2
//
//
//void comb(int *arr,int size)
//{
//	int gap = size;
//	bool swapped = true;
//	while(gap>0 || swapped == true)
//	{
//		gap = gap/1.3;
//		swapped = false;
//		for(int i=0 ; i<size-gap ; i++)
//		{
//			if(arr[i]>arr[i+gap])
//			{
//				swapped = true;
//				swap(arr[i],arr[i+gap]);	
//			}	
//		}
//	}
//}
//
//// best = nlogn
//// worst = n^2
//
//
//void bubble(int *arr, int size)
//{
//	bool flag = 0;
//	for(int i=0 ; i<size ; i++)
//	{
//		for(int j=0 ; j<size ; j++)
//		{
//			if(arr[i] > arr[i+1])
//			{
//				swap(arr[i],arr[i+1]);
//				flag = 1;
//			}
//		}
//		if(flag == 0)
//		{
//			return;
//		}
//	}
//}
//
//void insertion(int *arr,int size)
//{
//	for(int i=1 ; i<size ; i++)
//	{
//		int key = arr[i];
//		int j=i-1;
//		while(j>=0 && arr[j]>key)
//		{
//			arr[j+1] = arr[j];
//			j--;
//		}
//		arr[j+1] = key;
//	}
//}
//
//void selection(int *arr,int size)
//{
//	for(int i=0 ; i<size ; i++)
//	{
//		int current = i;
//		for(int j=i+1 ; j<size ; j++)
//		{
//			if(arr[j]<arr[current])
//			{
//				current = j;
//			}
//		}
//		if(current != i)
//		{
//			swap(arr[i],arr[current]);
//		}
//	}
//}
//
//int main()
//{
//	int size = 10;
//	int *arr = new int[size]{};
//	
//	srand(time(0));
//	for(int i=0 ; i<size ; i++)
//	{
//		int r = rand() % 100;
//		arr[i] = r;	
//	}
//	for(int i=0 ; i<size ; i++)
//	{
//		cout << arr[i] << "   ";
//	}
//	cout << endl;;
//	comb(arr,size);
//	for(int i=0 ; i<size ; i++)
//	{
//		cout << arr[i] << "   ";
//	}
//	
//	delete[] arr;
//}

#include<stdio.h>
#include<iostream>
using namespace std;

void HelloWorld(string str)
{
	printf("Hello World");
}

int main()
{
	HelloWorld("printf");
}

