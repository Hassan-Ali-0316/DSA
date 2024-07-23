#include<iostream>
using namespace std;


class linearhash
{
	public:
		int* arr;
		int size;
		linearhash(int s)
		{
			size = s;
			arr = new int[s];
			for(int i=0 ; i<s ; i++)
			{
				arr[i] = INT_MIN;
			}
		}
		int hashfun(int n)
		{
			return (n%size);
		}
		void insert(int d)
		{
			int idx1 = hashfun(d);
			if(arr[idx1] == INT_MIN)
			{
				arr[idx1] = d;
			}
			else
			{
				while(arr[idx1]!=INT_MIN)
				{
					idx1 = hashfun(idx1+1);
				}
				arr[idx1] = d;
			}
		}
		void print()
		{
			for(int i=0 ; i<size ; i++)
			{
				if(arr[i]!=INT_MIN)
				{
					cout << arr[i] << "  ";
				}
			}
			cout << endl;
		}
		void search(int d)
		{
			int idx = hashfun(d);
			if(arr[idx] == d)
			{
				cout << "Idx: " << idx << endl;
			}
			else
			{
				while(arr[idx]!=d)
				{
					idx = (hashfun(idx+1));
				}
				cout << "Idx: " << idx << endl;
			}
		}
};

int main()
{
	linearhash l(10);
	l.insert(4);
	l.insert(5);
	l.insert(14);
	l.print();
	
}