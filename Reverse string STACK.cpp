#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Stack
{
	public:
		T* data;
		int top;
		const int size = 10;
		Stack()
		{
			data = new T[size];
			top = -1;
		}
		bool isFull()
		{
			if(top == size-1)
			{
				cout << "Stack OverFlow\n";
				return true;	
			}
			else
			{
				return false;
			}
		}
		bool isEmpty()
		{
			if(top == -1)
			{
				cout << "Stack underflow\n";
				return true;
			}
			return false;
		}
		void push(T d)
		{
			if(!isFull())
			{
				top++;
				data[top] = d;
			}
		}
		void pop()
		{
			if(!isEmpty())
			{
				top--;
			}
		}
		void traverse()
		{
			for(int i=0 ; i<top ; i++)
			{
				cout << data[i] << "  ";
			}
			cout << endl;
		}
		void delMid(int count)
		{
			if(count == size/2)
			{
				pop();
				return;
			}
			int t = data[top];
			pop();
			delMid(count+1);
			push(t);
		}
		T getTop()
		{
			return data[top];
		}
		void sortedInsert(int n)
		{
			if(isEmpty() || (!isEmpty() && getTop() > n))
			{
				push(n);
				return;
			}
			int n1 = getTop();
			
			sort();
			push(n1);
		}
		void sort()
		{
			if(isEmpty())
			{
				return;
			}
			int n = getTop();
			pop();
			sort();
			sortedInsert(n);
		}
};

int main()
{
	Stack<int> s;
	for(int i=0 ; i<10 ; i++)
	{
		s.push(i+1);
	}
	s.traverse();
	s.delMid(0);
	s.traverse();
	s.sort();
}