#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int card;
		Node* next;
		Node()
		{
			card = 0;
			next = NULL;
		}
		Node(int c)
		{
			card = c;
			next = NULL;
		}
};

class Stack
{
	public:
		Node* top;
		Stack()
		{
			top = NULL;
		}
		void push(int c)
		{
			Node* n1 = new Node(c);
			if(top == NULL)
			{
				top = n1;
				top->next = NULL;
			}
			else
			{
				n1->next = top;
				top = n1;
			}
		}
		int pop()
		{
			int t = top->card;
			Node* temp = top;
			top = top->next;
			delete temp;
			return t;
		}
		void traverse()
		{
			Node* temp = top;
			while(temp != NULL)
			{
				cout << temp->card << endl;
				temp = temp->next;
			}
			cout << endl;
		}
		bool isEmpty()
		{
			if(top == NULL)
			{
				return 1;
			}
			return 0;
		}
};
int main()
{
	Stack* s = new Stack();
	Stack* a = new Stack();
	Stack* b = new Stack();
	Stack* c = new Stack();
	Stack* d = new Stack();
	srand(time(0));
	int arr[100];
	bool flag = 0;
	for(int i=0 ; i<100 ; i++)
	{
		int r = rand() % (100);
		r++;
		arr[i] = r;
	}
	for(int i=0 ; i<100 ; i++)
	{
		s->push(arr[i]);
	}
	
	while(!s->isEmpty())
	{
		int x = s->pop();
		a->push(x);
		x = s->pop();
		b->push(x);
		x = s->pop();
		c->push(x);
		x = s->pop();
		d->push(x);
	}
	int asum = 0,bsum = 0,csum = 0,dsum = 0;
	while(!a->isEmpty())
	{
		asum = asum + a->pop();
	}
	while(!b->isEmpty())
	{
		bsum = bsum + b->pop();
	}
	while(!c->isEmpty())
	{
		csum = csum + c->pop();
	}
	while(!d->isEmpty())
	{
		dsum = dsum + d->pop();
	}
	cout << asum << endl << bsum << endl << csum << endl << dsum << endl << endl;
	delete s;
}