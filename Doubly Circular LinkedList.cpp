#include<iostream>
using namespace std;

int i = 1;

class Node
{
	public:
		int data;
		Node* next;
		int key;
		Node* prev;
		Node()
		{
			key = 0;
			prev = NULL;
			data = 0;
			next = NULL;
		}
		Node(int d)
		{
			data = d;
			key = i;
			i++;
			next = NULL;
			prev = NULL;
		}
};

class LinkedList
{
	public:
		Node* head;
		Node* tail;
		LinkedList()
		{
			head = NULL;
			tail = NULL;
		}
		void insertatTail(int d)
		{
			Node* node1 = new Node(d);
			if(head == NULL)
			{
				head = node1;
				tail = node1;
				tail->next = head;
				head->prev = tail;	
				return;
			}
			else
			{
				Node* temp = head;
				while(temp != tail)
				{
					temp = temp->next;
				}
				tail->next = node1;
				node1->next = head;
				node1->prev = tail;
				head->prev = node1;
				tail = node1;
			}
			
		}
		void traverseforward()
		{
			Node* temp = head;
			while(1)
			{
				cout << temp->data << "\t" << "Key : " << temp->key << endl;;
				temp = temp->next;
				if(temp == head)
				{
					break;
				}
			}
			cout << endl;
		}
		void swapnodes(int k1,int k2)
		{
			if(k1 == k2)
			{
				return;
			}
			Node* temp1 = head;
			if(k1 != 1)
			{
				while(temp1->next != head)
				{
					if(k1 == temp1->key)
					{
						break;
					}
					temp1 = temp1->next;
				}	
			}

			Node* temp2 = head;
			while(temp2->next != head)
			{
				if(k2 == temp2->key)
				{
					break;
				}
				temp2 = temp2->next;
			}
			if(k1 == 1)
			{
				Node* t2 = temp2;
				Node* t2next = temp2->next;
				head = temp2;
				temp2->prev = NULL;
				temp2->next = temp1;
				temp1->prev = temp2;
				temp1->next = t2next;
				t2next->prev = temp1;
				tail->next = head;
			//	cout << t2next->data << endl;
				return;
			}
			if(k2 - k1 == 1 || k1 - k2 == 1)
			{
				Node* t1prev = temp1->prev;  
		     	Node* t2next = temp2->next; 
		        t1prev->next = temp2;    
		        temp2->prev = t1prev;	
		        temp2->next = temp1;	
		        temp1->prev = temp2;        
		        temp1->next = t2next;   
		        t2next->prev = temp1;
				return;
			}
			Node* tempp = temp1;
			Node * ex = temp1->next;
			
			temp1->prev->next = temp2;
			temp1->next = temp2->next;
			temp1 = temp2;
					
			temp2->prev->next = tempp;
			temp2->next = ex;
			temp2 = tempp;				
		}
};

int main()
{
	LinkedList l;
	l.insertatTail(3333);
	l.insertatTail(909);
	l.insertatTail(6767);
	l.insertatTail(3122);
	l.insertatTail(1234);
	l.insertatTail(5678);
	l.insertatTail(91011);
	cout << endl;
	l.traverseforward();
	l.swapnodes(3,6);
	cout << "After swapping nodes with key 3 & 6 , we get\n";
	l.traverseforward();
}