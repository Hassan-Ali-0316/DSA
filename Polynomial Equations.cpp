#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		int power;
		char var;
		Node* next;
		Node()
		{
			data = 0;
			power = 0;
			var = '-';
			next = NULL;
		}
		Node(int data,int p) 				
		{
			this->data = data;
			this->power = p;
			this->var = 'x';
			next = NULL;	
		}	
};


class LinkedList
{
	public:
		Node* head;
		LinkedList()
		{
			head = NULL;	
		}	
		void insert(int d,int p)
		{
			Node* node1 = new Node(d,p);
			if(head == NULL)
			{
				head = node1;
				head->next = NULL;
			}
			else
			{
				node1->next = head;
				head = node1;
			}
		}
		void traverse()
		{
			Node* temp = head;
			while(temp != NULL)
			{
				cout << "+(" << temp->data << temp->var << temp->power << ") ";
				temp = temp->next;
			}
			cout << endl;
		}
		void insertAtTail(int d,int p)
		{
			Node* node1 = new Node(d,p);
			if(head == NULL)
			{
				head = node1;
				head->next = NULL;
			}
			else
			{
				Node* temp = head;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = node1;
				node1->next = NULL;
			}	
		}
		LinkedList derivative()
		{
			LinkedList l;
			Node *temp = head;
			while(temp->next != NULL)
			{
				int num = temp->data*temp->power;
				int po = temp->power = temp->power - 1;
				if(temp->power = 0)
				{
					continue;
				}
				else
				{
					l.insertAtTail(num,po);
				}
				temp = temp->next;
			}
			return l;
		}
};

LinkedList add(LinkedList &l1,LinkedList &l2)
{
	LinkedList l;
	Node* t1 = l1.head;
	Node* t2 = l2.head;
	while(t1 != NULL && t2 != NULL)
	{
		if(t1->power > t2->power)
		{
			l.insertAtTail(t1->data,t1->power);
			t1 = t1->next;
		}
		if(t1->power < t2->power)
		{
			l.insertAtTail(t2->data,t2->power);
			t2 = t2->next;
		}
		if(t1->power == t2->power)
		{
			int sum = t1->data + t2->data;
			l.insertAtTail(sum,t1->power);
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	return l;
}


int main()
{
	LinkedList l1;
	l1.insert(+2,0);
	l1.insert(-4,1);
	l1.insert(23,2);
	cout << "Equation 1 : ";
	l1.traverse();
	
	LinkedList l2;
	l2.insert(2,0);
	l2.insert(4,1);
	l2.insert(7,2);
	l2.insert(69,3);
	cout << "Equation 2 : ";
	l2.traverse();
	
	LinkedList l3;
	l3 = add(l1,l2);
	cout << "\nSum : ";
	l3.traverse();
	
	LinkedList l4;
	l4 = l2.derivative();
	cout << "Derivative of linkedList 2 : ";
	l4.traverse();
	
	
}
