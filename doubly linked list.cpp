#include<iostream>
using namespace std;

int i = 1;

class Node
{
public:
    int data;
    int key;
    Node* prev;
    Node* next;
    Node()
    {
        data = 0;
        key = 0;
        prev = NULL;
        next = NULL;
    }
    Node(int v)
    {
        data = v;
        key = i;
        i++;
        prev = NULL;
        next = NULL;
    }
};

int getLength(Node* &head)
{
	int l=0;
	Node* temp = head;
	while(temp != NULL)
	{
		l++;
		temp = temp->next;
	}
	return l;
}

void print(Node* &head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\tKey = " << temp->key << endl;
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int v)
{
    Node* temp = new Node(v);
    temp->next = head;
    if (head != NULL) 
	{
        head->prev = temp;
    }
    head = temp;
}

void insertAtTail(Node* &head , int v)
{
	Node* node1 = new Node(v);
	if(head == NULL)
	{
		head = node1;
		head->prev = NULL;
		head->next = NULL;
		return;
	}
	Node* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node1;
	node1->prev = temp;
	node1->next = NULL;
}

void insertAtMiddle(Node* &head , int v, int p)
{
	if(p == 1)
	{
		insertAtHead(head,v);
		return;
	}
	Node* temp = head;
	int x = 1;
	int flag = 0;
	while(temp->next != NULL)
	{
		if(x == p-1)
		{
			flag = 1;
			Node* node1 = new Node(v);
			node1->next = temp->next;
			node1->prev = temp;
			if (temp->next != nullptr)
            {
                temp->next->prev = node1;
            }
            temp->next = node1;
			return;
		}
		temp = temp->next;
		x++;
	}
	if(flag != 1 && p == (getLength(head)+1))
	{
		insertAtTail(head,v);
	}
	else
	{
		cout << "Cannot Insert element at position " << p << " since size of linked list = " << getLength(head) << "\n\n";
		return;
 	}
}

void printback(Node* &head)
{
	if(head == NULL)
	{
		cout << "empty\n";
	}
	Node* temp = head;
	while(temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	while(temp != NULL)
	{
		cout << temp->data << "\tKey = " << temp->key << endl;
		temp = temp->prev;
	}
	cout << endl;
}

void deleteanyNode(Node* &head, int k)
{
	if(head == NULL)
	{
		cout << "Linked List empty\n";
		return;
	}
	if(head->key == k)
	{
		Node* temp = head->next;
		delete head;
		head = temp;
		head->prev = NULL;
		return;
	}
	int flag = 0;
	Node* temp = head;
	while(temp != NULL)
	{
		if(temp->key == k)
		{
			flag = 1;
			temp->prev->next = temp->next;
			temp->next->prev /* temp->next */ = temp->prev;
			break;
		}
		temp = temp->next;
	}
	if(flag != 1)
	{
		cout << "Key not found :/ \n";
		return;
	}
}

void deletelastNode(Node* &head)
{
	if(head == NULL)
	{
		cout << "Linked list empty\n";
		return;
	}
	Node* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	return;
}

int main()
{
    Node* head = NULL;
    int ch;
    while(1)
    {
    	cout << "Press 1 if you want to insert elements in linked list in start\n";
    	cout << "Press 2 if you want to insert elements in linked list in end\n";
    	cout << "Press 3 if you want to insert elements in linked list in middle\n";
    	cout << "Press 4 to delete last key  of linked list\n";
    	cout << "Press 5 to delete any node (other than last) of linked list\n";
    	cout << "Press 6 to print linked list\n";
    	cout << "Press any key to exit\n";
    	cout << "                                                               Enter Choice : ";
    	cin >> ch;
    	if(ch == 1)
    	{
    		cout << "Enter value to be inserted : ";
    		int v;
    		cin >> v;
    		insertAtHead(head,v);
		}
		else if(ch == 2)
		{
			cout << "Enter value to be inserted : ";
    		int v;
    		cin >> v;
    		insertAtTail(head,v);
		}
		else if(ch == 3)
		{
			cout << "Enter value to be inserted : ";
    		int v;
    		cin >> v;
    		cout << "Enter Position where element is to be inserted : ";
    		int p;
    		cin >> p;
    		insertAtMiddle(head,v,p);
		}
		else if(ch == 4)
		{
			deletelastNode(head);
		}
		else if(ch == 5)
		{
			cout << "Enter Key of element to be deleted (other than last)\n";
			int k;
			cin >> k;
			deleteanyNode(head,k);
		}
		else if(ch == 6)
		{
			cout << "\n----------------------------------------------------------------------------------";
			cout << "\nLinked List : \n";
			print(head);
			cout << "----------------------------------------------------------------------------------\n";
		}
		else
		{
			break;
		}
	}	
}