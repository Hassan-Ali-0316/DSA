#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* prev;
		Node* next;
		Node()
		{
			data = 0;
			next = NULL;
			prev = NULL;
		}
		Node(int d)
		{
			data = d;
			prev = NULL;
			next = NULL;
		}
};

class Queue
{
	public:
		Node* front;
		Node* rear;
		Queue()
		{
			front = NULL;
			rear = NULL;
		}
		void enqueue(int d)
		{
			Node* node1 = new Node(d);
			if(front == NULL && rear == NULL)
			{
				front = node1;
				rear = node1;
				rear->next = front;
				front->prev = rear;
				front->next = NULL;
			}
			else
			{
				node1->next = rear;
				rear->prev = node1;
				rear = node1;
			}
		}
		bool isEmpty()
		{
			if(front == NULL || rear == NULL)
			{
				return true;
			}
			return false;           // no isFull function becauze ll is never full
		}
		void dequeue()
		{
			if(isEmpty())
			{
				cout << "Queue empty!\n";
				return;
			}
			front = front->prev;
		}
		void traverse()
		{
			if(isEmpty())
			{
				cout << "Queue Empty !!\n";
				return;
			}
			Node* temp = rear;
			while(temp != front)
			{
				cout << temp->data << "  ";
				temp = temp->next;
			}
			cout << temp->data;
			cout << endl;
			return;
		}
		void traverseBack()
		{
			if(isEmpty())
			{
				cout << "Queue Empty !!\n";
				return;
			}
			Node* temp = front;
			while(temp != rear)
			{
				cout << temp->data << "  ";
				temp = temp->prev;
			}
			cout << temp->data << endl;
			return;
		}
		void empty()
		{
			front = NULL;
			rear = NULL;
		}
};

int main()
{
	Queue* q = new Queue();
	srand(time(0));
	int ch;
	while(1)
	{
		cout << "1. enqueue()\n";
		cout << "2. dequeue()\n";
		cout << "3. empty()\n";
		cout << "4. traverse()\n";
		cout << "5. traverseBack()\n";
		cout << "6. exit()\n";
		cin >> ch;
		if(ch == 1)
		{
			int r = rand() % 101;
			q->enqueue(r);
		}
		else if(ch == 2)
		{
			q->dequeue();
		}
		else if(ch == 3)
		{
			q->empty();
		}
		else if(ch == 4)
		{
			q->traverse();
		}
		else if(ch == 5)
		{
			q->traverseBack();
		}
		else
		{
			break;
		}
	}
	delete q;
}