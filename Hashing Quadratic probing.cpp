#include<iostream>
using namespace std;

class Node
{
	public:
		int roll;
		string name;
	//	Node* next;
		Node()
		{
	//		next = NULL;
		}
		Node(int r,string n)
		{
			roll = r;
			name = n;
	//		next = NULL;
		}	
};

class hasht
{
	public:
	Node** map;
	int size;
	hasht(int s)
	{
		size = s;
		map = new Node*[s];
		for(int i=0 ; i<s ; i++)
		{
			map[i] = NULL;
		}
	}	
	int hashf(string n)
	{
		int sum = 0;
		for(int i=0 ; i<n.length() ; i++)
		{
			sum = sum + n[i];
		}
		return (sum%size);
	}
	void insert(int r,string n)
	{
		Node* n1 = new Node(r,n);
		int idx= hashf(n);
		if(map[idx] == NULL)
		{
			map[idx] = n1;
		}
		else
		{
			for(int i=0 ; i<size ; i++)
			{
				int idx2 = (idx+(i*i)%size);
				if(map[idx2] == NULL)
				{
					map[idx2] = n1;
					break;
				}
			}
		}
	}
	void search(int r,string n)
	{
		int idx1 = hashf(n);
		if(n == map[idx1]->name)
		{
			cout << "name: " << map[idx1]->name << endl << "roll : " << map[idx1]->roll << endl;
		}
		else
		{
			for(int i=0 ; i<size ; i++)
			{
				int idx2 = (idx1+i*i)%size;
				if(map[idx2]->name == n)
				{
					cout << "name: " << map[idx1]->name << endl << "roll : " << map[idx1]->roll << endl;
					return;
				}
			}
			cout << "Not found\n";
			return;
		}
	}
	void deleteN(string n)
	{
		int idx1 = hashf(n);
		if(map[idx1] == NULL)
		{
			cout << "Not fOUND\n";
			return;
		}
		if(map[idx1]->name == n)
		{
			Node* temp = map[idx1];
			map[idx1] = NULL;
			delete temp;
		}
		else
		{
			for(int i=0 ; i<size ; i++)
			{
				int idx2 = (idx1+i*i)%size;
				if(map[idx2]->name == n)
				{
					Node* temp = map[idx2];
					map[idx2] = NULL; 
					delete temp;
					return;
				}
			}
			cout << "Not Found\n";
		}
	}
	void print()
	{
		for(int i=0 ; i<size ; i++)
		{
			cout << i << "|     ";
			if(map[i]!= NULL)
			{
				cout << "name: " << map[i]->name << "   " << "roll : " << map[i]->roll;
			}
			cout << endl;
		}
	}
};

int main()
{
	hasht h(10);
	h.insert(4444,"khair");
	h.insert(5555,"Ali");
	h.insert(1234,"Z");
	h.insert(6789,"ZZ");
	h.insert(1111,"ZZZ");
	h.deleteN("ZZ");
	h.print();
}