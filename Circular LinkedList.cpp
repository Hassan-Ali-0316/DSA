#include<iostream>
using namespace std;

int x = 1;

class Node
{
	public:
		int data;
		int key;
		Node* next;
		Node()
		{
			data = 0;
			next = NULL;	
		}	
		Node(int d)
		{
			this->data = d;
			this->key = x;
			x++;
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
		void addinStart(int d)
		{
			Node* node1 = new Node(d);
			if(head == NULL)
			{
				head = node1;
				head->next = head;
				return;
			}
			else
			{
				Node* temp = head;
				while(temp->next != head)
				{
					temp = temp->next;
				}
				node1->next = head;
				head = node1;
				temp->next = head;
			}
		}
		void addinEnd(int d)
		{
			Node* node1 = new Node(d);
			if(head == NULL)
			{
				head = node1;
				head->next = head;
				return;
			}
			Node* temp = head;
			while(temp->next != head)
			{
				temp = temp->next;
			}
			temp->next = node1;
			node1->next = head;
		}
		void addinMiddle(int d,int p)
		{
			Node* node1 = new Node(d);
			if(p == 1)
			{
				addinStart(d);
				return;
			}
			int i = 1;
			int flag = 0;
			Node* temp = head;
			while(temp->next != head)
			{
				if(i == p-1)   // consider we want to add at position 2, then p-1 value wil be inserted after 1st
				{
					flag = 1;
					node1->next = temp->next;
					temp->next = node1;
					return;
				}
				i++;
				temp = temp->next;
			}
			if(temp->next == head)
			{
				addinEnd(d);
				return;
			}
			if(flag != 1 && temp->next != head)
			{
				cout << "Index Position does not exists\n";
				return;
			}		
		}
		void traverse()
		{
			if(head == NULL)
			{
				cout << "Empty linked list :/ \n";
				return;
			}
		    Node* temp = head;
		    if (temp == NULL)
		    {
		        cout << "The list is empty." << endl;
		        return;
		    }
		    do
		    {
		        cout << temp->data << "->";
		        temp = temp->next;
		    } while (temp != head);
		
		    cout << "HEAD" << endl;
		}
		void deletefirstnode()
		{
			if(head == NULL)
			{
				cout << "Empty linked list :/ \n";
				return;
			}
			Node* temp = head;
			Node* curr = head->next;
			while(temp->next != head)
			{
				temp = temp->next;
			}
			temp->next = curr;
			head = curr;
			return;
		}
		void deleteanynode()
		{
			if(head == NULL)
			{
				cout << "Linked list empty :/ \n";
				return;
			}
			Node* temp = head;
			Node* current = head->next;
			cout << "Enter Index of the position where you want to delete : ";
			int i;
			cin >> i;
			if(i == 1)
			{
				deletefirstnode();
				return;
			}
			int counter = 1,flag = 0;;
			while(temp != NULL)
			{
				if(counter == i-1)
				{
					flag = 1;
					break;
				}
				temp = temp->next;
				current = current->next;
				counter++;
			}
			if(flag == 0)
			{
				cout << "\nIndex position not found\n";
				return;
			}
			temp->next = current->next;
		}
};

int main()
{
	int ch;
	LinkedList l1;
	while(1)
	{
		cout << "\nPress 1 if you want to insert elements in linked list in start\n";
    	cout << "Press 2 if you want to insert elements in linked list in end\n";
    	cout << "Press 3 if you want to insert elements in linked list in middle\n";
    	cout << "Press 4 to delete any node of linked list\n";
    	cout << "Press 5 to print linked list\n";
    	cout << "Press any key to exit\n";
    	cout << "                                                               Enter Choice : ";
    	cin >> ch;
    	if(ch == 1)
    	{
    		cout << "Enter value to be inserted : ";
    		int v;
    		cin >> v;
    		l1.addinStart(v);
		}
		else if(ch == 2)
		{
			cout << "Enter value to be inserted : ";
    		int v;
    		cin >> v;
    		l1.addinEnd(v);
		}
		else if(ch == 3)
		{
			cout << "Enter value to be inserted : ";
    		int v;
    		cin >> v;
    		cout << "Enter Position where element is to be inserted : ";
    		int p;
    		cin >> p;
    		l1.addinMiddle(v,p);
		}
		else if(ch == 4)
		{
			l1.deleteanynode();	
		}
		else if(ch == 5)
		{
			cout << "\n----------------------------------------------------------------------------------";
			cout << "\nLinked List : \n";
			l1.traverse();
			cout << "----------------------------------------------------------------------------------\n";
		}
		else
		{
			break;
		}
	//	cout << endl;
	}
}