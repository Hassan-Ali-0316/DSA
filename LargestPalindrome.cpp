#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		Node()
		{
			data = 0;
			next = NULL;
		}
		Node(int data) 				
		{
			this->data = data;
			next = NULL;	
		}	
};


int checker(int num)
{
	int count = 0;
	int temp = num;
	int n1 = 0;
	while(temp>0)
	{
		int digit = temp % 10;
		n1 = n1 * 10 + digit;
		temp = temp/10;
	}
	if(num == n1)
	{
		while(n1>0)
		{
			n1 = n1/10;
			count++;
		}
	}
	return count;
}

class LinkedList
{
	public:
		Node* head;
		LinkedList()
		{
			head = NULL;	
		}	
		void insert(int d)
		{
			Node* node1 = new Node(d);
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
		void traverse()
		{
			Node* temp = head;
			while(temp != NULL)
			{
				cout << temp->data << "  ";
				temp = temp->next;
			}
			cout << endl;
		}
		void deletee(int num)
		{
			Node* t = head;
			Node* temp = head->next;
			while(temp != NULL)
			{
				if(temp->data == num)
				{
					t->next = temp->next;
					break;
				}
				temp = temp->next;
				t = t->next;
			}
		}
		void Palindrome()
		{
			int num = 0;
			int maxx = INT_MIN;
			int digits = 0;
			Node* temp = head;
			while(temp != NULL)
			{
				digits = checker(temp->data);
				if(digits>maxx)
				{
					maxx = 	digits;
					num = temp->data;
				}
				temp = temp->next;	
			}
			cout << "\n\nLargest Palindrome : " << num << " with digits " << maxx << endl;
		}
};



 void check(int num,int temp,int &n1)
{
	if(temp==0)
	{
		if(n1 == num)
		{
			cout << "Palindrome";
		}
		return;
	}
	int digit = temp % 10;
	n1 = n1 * 10 + digit;
	check(num,temp/10,n1);
}

int main()
{
	LinkedList l;
	l.insert(1);
	l.insert(100);
	l.insert(121);
	l.insert(432);
	l.insert(4235);
	l.insert(909);
	l.insert(12321);
	l.insert(35);
	l.insert(9009);
	l.insert(454);
	l.insert(67);
	l.insert(666);
	l.traverse();
	l.Palindrome();
}