A#include<bits/stdc++.h>
using namespace std;


class Stack
{
	public:
		int* arr;
		int top;
		int size;
		Stack(int d)
		{
			size = d;
			top = -1;
			arr = new int[d];	
		}	
		bool isFull()
		{
			if(top == size)
			{
				return true;
			}
			return false;
		}
		bool isEmpty()
		{
			if(top == -1)
			{
				return true;
			}
			return false;
		}
		void push(int v)
		{
			if(isFull())
			{
				cout << "Stack overflow\n";
				return;
			}
			top++;
			arr[top] = v;
		}
		void pop()
		{
			if(isEmpty())
			{
				cout << "Stack Underflow\n";
				return;
			}
			arr[top] = 0;
			top--;
		}
		int count()
		{
			return (top+1);
		}
		int seek(int pos)
		{
			if(isEmpty())
			{
				cout << "Stack underflow\n";
				return -1;
			}
			return arr[pos];
		}
		void change(int pos,int val)
		{
			if(isEmpty())
			{
				cout << "Stack Underflow\n";
				return;
			}
			arr[pos] = val;
		}
		void Display()
		{
			for(int i=top ; i>=0 ; i--)
			{
				cout << arr[i] << "  ";
			}
			cout << endl;
		}
		void empty()
		{
			if(isEmpty())
			{
				cout << "Stack empty\n";
				return;
			}
			for(int i=0 ; i<top ; i++)
			{
				arr[i] = 0;
			}
			int temp = top;
			for(int i=temp ; i>=0 ; i--)
			{
				top--;
			}
		}
		~Stack()
		{
			delete[] arr;
		}
};

int main()
{
	int ch;
	Stack* s = new Stack(10);
	int i=0;
	srand(time(0));
	while(1)
	{
		cout << "1. Push()\n";
		cout << "2. Pop()\n";
		cout << "3. Seek()\n";
		cout << "4. isEmpty()\n";
		cout << "5. isFull()\n";
		cout << "6. change()\n";
		cout << "7. count()\n";
		cout << "8. Display()\n";
		cout << "9. empty()\n";
		cout << "0. exit()\n";
		cin >> ch;
		if(ch == 1)
		{
			i++;
			int r = rand() % 1001;
			s->push(r);
		}
		else if(ch == 2)
		{
			i--;
			s->pop();
		}
		else if(ch == 3)
		{
			int r = rand() % i;
			cout << "Value Seeked : " << s->seek(r) << endl;;
		}
		else if(ch == 4)
		{
			if(s->isEmpty())
			{
				cout << "Stack Underflow\n";
			}
			else
			{
				cout << "Okay hai\n";
			}
		}
		else if(ch == 5)
		{
			if(s->isFull())
			{
				cout << "Stack Overflow\n";
			}
			else
			{
				cout << "Okay hai\n";
			}
		}
		else if(ch == 6)
		{
			int v = rand() % 1001;
			int r = rand() % i;
			s->change(r,v);
		}
		else if(ch == 7)
		{
			cout << s->count() << endl;
		}
		else if(ch == 8)
		{
			s->Display();
		}
		else if(ch == 9)
		{
			i=0;
			s->empty();
		}
		else
		{
			exit(1);
		}
	}
	delete s;
}