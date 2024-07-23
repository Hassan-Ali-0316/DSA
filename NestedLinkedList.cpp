#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* nested;
		Node* next;
		Node()
		{
			data = 0;
			nested = NULL;
			next = NULL;
		}
		Node(int d)
		{
			nested = NULL;
			data = d;	
			next = NULL;
		}
};
class LinkedList
{
	public:
		Node* head;	
//		Node* nested;
		LinkedList()
		{
//			nested = NULL;
			head = NULL;
		}
		void insertatHead(int d)
		{
			Node* newNode = new Node(d);
			if(head == NULL)
			{
				head = newNode;
				newNode->next = NULL;	
			}
			else
			{
				Node* temp = head;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newNode;
				newNode->next = NULL;
			}
		}
		void insertnested(int key,int nestedData)
		{
			Node* temp = head;
			int flag = 0;
			while(temp != NULL)
			{
				if(temp->data == key)
				{
					flag = 1;
					Node* x = new Node(nestedData);
					if(temp->nested == NULL)
					{
						temp->nested = x;
						x->next = NULL;
					}
					else
					{
						Node* t = temp->nested;
						while(t->next != NULL)
						{
							t = t->next;	
						}	
						t->next = x;
						x->next = NULL;
					}
				}
				temp = temp->next;
			}
			if(flag != 1)
			{
				cout << "No nodes exists with value " << key << endl;
				return;
			}
		}
		void traverseHead()
		{
			Node* temp = head;
			while(temp != NULL)
			{
				cout << temp->data << "  ";
				temp = temp->next;
			}
			cout << endl;
		}
		void traverseParticularKey(int key)
		{
			Node* temp = head;
			while(temp->next != NULL)
			{
				if(temp->data == key)
				{
					Node* t = temp->nested;
					cout << "Key : "<< temp->data << " : ";
					while(t->next != NULL)
					{
						cout << t->data << "  ";
						t = t->next;
					}
					break;
					cout << endl;
				}
				temp = temp->next;
			}
		}
		void traverseAll()
		{
			if(head == NULL)
			{
				return;
			}
			Node* temp = head;
			while(temp != NULL)
			{
				cout << "Key : "<< temp->data << " : ";
				Node* t = temp->nested;
				if(temp->nested == NULL)
				{
					cout << endl;
					// 
				}
				while(t->next != NULL)
				{
					cout << t->data << "  ";
					t = t->next;
				}
				cout << t->data;
				cout << endl;
				temp = temp->next;
			}
		}
		LinkedList converted()
		{
			LinkedList l;
			Node* temp = head;
			while(temp != NULL)
			{
				Node* t = temp->nested;
				int reversed = 0;
				int d = 1;
				int num = 0;
				while(t != NULL)
				{
					num = (t->data*d) + num;
					d = d * 10;
					t = t->next;
				}
				while(num!=0)
				{
					int digit = num%10;
					reversed = reversed * 10 + digit;
					num = num/10;
				}
				l.insertatHead(reversed);
				temp = temp->next;
			}
			return (l);
		}
};

int main()
{
	LinkedList l;
	l.insertatHead(0);
	l.insertatHead(1);
	l.insertatHead(2);
	l.insertatHead(3);
	l.insertatHead(4);
	l.insertatHead(5);
	l.traverseHead();
	l.insertnested(0,1);
	l.insertnested(0,1);
	l.insertnested(0,4);
	l.insertnested(0,7);
	l.insertnested(1,6);
	l.insertnested(1,3);
	l.insertnested(2,3);
	l.insertnested(2,1);
	l.insertnested(2,3);
	l.insertnested(3,4);
	l.insertnested(3,4);
	l.insertnested(4,9);
	l.insertnested(4,8);
	l.insertnested(5,6);
	cout << endl;
	cout << endl;
	l.traverseAll();
	LinkedList l1;
	l1 = l.converted();
	cout << "\nFinal LinkedList\n";
	l1.traverseHead();
}