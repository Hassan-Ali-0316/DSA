#include<iostream>
#include<vector>
using namespace std;
vector <int> insertion(vector<int> arr , int s)
{
	int current;
	for(int i=1 ; i<s ; i++)
	{
		current = arr[i];
		int j = i-1;
		while(arr[j]>current && j>=0)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = current;
	}
	return arr;
}
int main()
{
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(2);
	arr.push_back(44);
	arr.push_back(76);
	arr.push_back(1001);
	for(int i=0 ; i<arr.size() ; i++)
	{
		cout << arr[i] << "   ";
	}
	cout << endl << endl;
	vector<int> x = insertion(arr,arr.size());
	for(int i=0 ; i<x.size() ; i++)
	{
		cout << x[i] << "   ";
	}
	cout << endl << endl;
}