#include<iostream>
using namespace std;

int getLchild(int i)
{
	return (i*2)+1;
}
int getRchild(int i)
{
	return (i*2)+2;
}
int parent(int i)
{
	return (i-1)/2;
}
int getheight(int arr[],int size)
{
	int i=size-1;
	int h=0;
	while(i !=0)
	{
		if(arr[i]<arr[parent(i)])
		{
			break;
		}
		else
		{
			h++;
		}
		i = parent(i);
	}
	return h;
}
int main()
{
	int arr[13] = {14,34,27,40,37,54,30,13,50,21,39,56,89};
	cout << "Height of min heap: " << getheight(arr,13) << endl;
}