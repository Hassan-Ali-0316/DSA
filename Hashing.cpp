/*

	Hashing is a technique of converting a given input key into output value it is done via hash function
	A hash function is any function that is used to map data of arbitary size to a fixed size value. this function generates new values 
	according to a mathematical hashing algorithm
	the values returned by this function are called hash values/hash codes
	time complexity for storing data is O(1)
	time complexity for searching/retreiving data is O(1)
	components of hashing:
							1. Key
							2. Hash function
							3. Hash table
							
	collision happens when hash function generates same hash (output) for differnt inputs
	
	-> COLLISION CONTROL: The process of finding alternate index position in hash table is call collision control or collision management
	   Two ways to tackle:
	1.Closed Hashing (Open addressing)
										1. linear probing
										2. quadratic probing
										3. Double hashing
										
			c) DOUBLE HASHING: in double hashing we use two hash functions, the hash function is h1(k), this ufnction takes in our key and
			   gives out a location on hash table .if the new location is empty,we can place our key and never use second hash function.
			   however in case of collision we use second hash function h2(k) in combination with first hash finction to fund new location							
	2. Open Hashing (Separate chaining):
		it is a technique which uses singly linkedlist known as a chain.
		when multiple items are hashed into same slot index , then these elements are inserted into singly linkedlist
	

*/

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
			next = nullptr;	
		}	
		Node(int d)
		{
			data = d;
			next = nullptr;	
		}	
};

class Hashing
{
	public:
		Node** chained;
		int capacity;
		int size;
		Hashing(int s)
		{
			chained = new Node*[s];
			for(int i=0 ; i<s ; i++)
			{
				chained[i] = nullptr;
			}
			capacity = s;
			size = 0;
		}
		int hashfunc(int d)
		{
			return (d%capacity);
		}
		void insert(int d)
		{
			int idx = hashfunc(d);
			Node* n1 = new Node(d);
			if(chained[idx] == nullptr)
			{
				chained[idx] = n1;
				chained[idx]->next = nullptr;
				size++;
			}
			else
			{
				Node* temp = chained[idx];
				while(temp->next != nullptr)
				{	
					temp = temp->next;
				}
				temp->next = n1;
			}
		}
		void search(int d)
		{
			int idx = hashfunc(d);
			int i = 0;
			Node* temp = chained[idx];
			while(temp != NULL)
			{
				if(temp->data == d)
				{
					cout << "Found at sub index " << i+1 << "\n";
					return;
				}
				temp = temp->next;
				i++;
			}
			cout << "Not found\n";
			return;
			
		}
		void deletenode(int d)
		{
			int idx = hashfunc(d);
			Node* curr = chained[idx];
			Node* prev = NULL;
			
			while(curr != NULL && curr->data != d)
			{
				prev = curr;
				curr = curr->next;
			}
			if(curr != NULL)
			{
				if(prev == NULL)
				{
					chained[idx] = curr->next;
				}
				else
				{
					prev->next = curr->next;
				}
				delete curr;
				size--;
			}
		}
		void print()
		{
			for(int i=0 ; i<capacity ; i++)
			{
				cout << "[" << i<< "]   ";
				if(chained[i] == NULL)
				{
					cout << "-" << endl;
				}
				else
				{
					Node* temp = chained[i];
					while(temp != NULL)
					{
						cout << temp->data << "  ";
						temp = temp->next;
					}
					cout << endl;
				}
			}
		}
};
int main()
{
	Hashing h(5);
	int c;
	while(1)
	{
		cout << "Keep inserting data: (1/0)? : ";
		cin >> c;
		if(c == 1)
		{
			int d;
			cout << "Enter value: ";
			cin >> d;
			h.insert(d);
		}
		else
		{
			break;
		}
	}
	while(1)
	{
		cout << "\n-----------------------------------------\n";
		h.print();
		cout << "\n-----------------------------------------\n";
		cout << "Search? (1): \n";
		cout << "Delete? (2): \n";
		cin >> c;
		if(c == 1)
		{
			cout << "Val?: ";
			int d;
			cin >> d;
			h.search(d);
		}
		else if(c == 2)
		{
			cout << "Val?: ";
			int d;
			cin >> d;
			h.deletenode(d);
		}
		else
		{
			break;
		}
	}
}