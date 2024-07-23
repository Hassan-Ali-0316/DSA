#include<iostream>      // task 1,2,3,4 are done in this file
#include<ctime>
#include<cstdlib>
using namespace std;

int x=0;
class Node
{
	public:
		int data;
		int key;
		Node* next;
		Node()
		{
			key = x;
			x++;
			data = 0;
			next = NULL;	
		}	
		Node(int v)
		{
//			key = x;
//			x++;
			this->data = v;
		}
};

void addinstart(Node* &node,int d)           // task 1 (b)
{
	Node* temp = new Node(d);
	temp->next = node;
	node = temp;
}

void addinend(Node* &node, int d)           // task 1 (a)
{
    Node* node1 = new Node();
    node1->data = d;
    node1->next = NULL;

    if (node == NULL)
    {
        node = node1;
    }
    else
    {
        Node* temp = node;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node1;
        node1->next = NULL;
    }
}


void traverse(Node* &node)
{
	Node* temp = node;
	while(temp != NULL)
	{
		cout << temp->data << "  " << temp->key << endl;;
		temp = temp->next;		
	}
	cout << endl;
}

void rec(Node* &head)
{
	Node* temp = head;
	Node* current = head;
	Node* next = NULL;
	Node* prev = NULL;
	
}
void reverse(Node* &head, int k1, int k2)
{
	Node* t1 = head;
	Node* t2 = head;
	while(t1->key != k1)
	{
		t1 = t1->next;
	}
	cout << t1->data;
	while(t2->key != k2)
	{
		t2 = t2->next;
	}
	cout << "\n" << t2->data << endl;
	Node* current = t1;
	Node* temp = t1;
	Node* next = NULL;
	Node* prev = NULL;
	while(t1 != t2)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	
}

void deletelastnode(Node* &node)       // task 3 (a)
{
	if(node == NULL)
	{
		return;
	}
	Node* temp = node->next;
	Node* current = node;
	while(temp->next != NULL)
	{
		temp = temp->next;
		current = current->next;
	}
		current->next = temp->next;
		delete temp;
		temp = NULL;
}

int main()
{
	Node* head = NULL;
	addinend(head,1);
	addinend(head,2);
	addinend(head,3);
	addinend(head,4);
	addinend(head,5);
	addinend(head,6);
	addinend(head,7);
	addinend(head,8);
	addinend(head,9);
	traverse(head);
	
	int k1=2,k2=6;
	cout << endl << endl;
	reverse(head,k1,k2);
	traverse(head);
}