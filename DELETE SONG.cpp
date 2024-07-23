#include<iostream>
#include<vector>
using namespace std;

int x = 0;
class Node
{
	public:
		int key;
		int c1;
		int c2;
		Node* next;
		Node()
		{
			key = 0;
			c1 = 0;
			c2 = 0;
			next = NULL;
		}
		Node(int c1,int c2)
		{
			key = x;
			x++;
			next = NULL;
			this->c1 = c1;
			this->c2 = c2;
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
		void insert(int c1,int c2)
		{
			Node* node1 = new Node(c1,c2);
			if(head == NULL)
			{
				head = node1;
				node1->next = head; 
			}	
			else
			{
				Node* temp = head;
				while(temp->next != head)
				{
					temp = temp->next;
				}
				temp->next = node1;
				node1->next = head;
			}
		} 
		void traverse()	
		{
			Node* temp = head;
			while(temp->next != head)
			{
				cout << "key : " << temp->key << " coins : " << temp->c1 << "   " << temp->c2 << endl;
				temp = temp->next;
			}
			cout << "key : " << temp->key << " coins : " << temp->c1 << "   " << temp->c2 << endl;
			cout << endl;
		}
		void keepTrack(int coins)
		{
			vector<int> visited;
			Node* temp = head;
			while(temp->next != head)
			{
				if(temp->c1 + temp->c2 == coins)
				{
					visited.push_back(temp->key);
				}
				temp = temp->next;
			}
			cout << endl;
			if(temp->c1 + temp->c2 == coins)
			{
				visited.push_back(temp->key);
			}
			cout << "Cities which match are: \n";
			for(int i=0 ; i<visited.size() ; i++)
			{
				cout << visited[i] << endl;
			}
			cout << endl;
			return;
		}
};

int main()
{
	int coins = 10;
	LinkedList l;
	l.insert(1,2);
	l.insert(3,4);
	l.insert(5,5);
	l.insert(3,3);
	l.insert(3,7);
	l.insert(9,11);
	l.insert(9,1);
	cout << "Cities : \n";
	l.traverse();
	cout << endl;
	l.keepTrack(10);
}