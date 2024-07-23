#include<iostream>
using namespace std;

class contact
{
	public:
		string name;
		int age;
		contact(){}
		contact(string n,int a)
		{
			name = n;
			age = a;	
		}	
		void print()
		{
			cout << name << "   " << age << endl;
		}
};

class node
{
	public:
		node* next;
		contact c;
		node()
		{
			next = NULL;
		}
		node(string n,int a)
		{
			next = NULL;
			c.name = n;
			c.age = a;
		}
};

class hasht
{
	public:
		node** chained;
		int capacity;
		int size;
		hasht(int s)
		{
			capacity = s;
			chained = new node*[s];
			for(int i=0 ; i<s ; i++)
			{
				chained[i] = nullptr;	
			}	
			size = 0;
		}
		int hashfun(string s)
		{
			int idx = 0;
			for(int i=0 ; i<s.length() ; i++)
			{
				idx += s[i];
			}
			return (idx%capacity);
		}
		void add(string s,int a)
		{
			int idx = hashfun(s);
			contact t(s,a);
			if(chained[idx] == NULL)
			{
				chained[idx] = new node(s,a);
				chained[idx]->next = NULL;
			}
			else
			{
				node* temp = chained[idx];
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = new node(s,a);
			}
		}
		void search(string s)
		{
			int idx = hashfun(s);
			if(chained[idx] == NULL)
			{
				cout << "DNE\n";
				return;
			}
			node* temp = chained[idx];
			int i = 0;
			while(temp!= NULL)
			{
				if(temp->c.name == s)
				{
					temp->c.print();
					break;
				}
				i++;
				temp = temp->next;
			}
			cout << "\t\t" <<i << endl;
		}
		void printall()
		{
			for(int i=0 ; i<capacity ; i++)
			{
				if(chained[i]== NULL)
				{
					cout << "-\n";
				}
				else
				{
					node* temp = chained[i];
					while(temp != NULL)
					{
						cout << temp->c.name << "(" << temp->c.age << ")-->";
						temp = temp->next;
					}
					cout << endl;
				}
			}
		}
};

int main()
{
	hasht h(10);
	h.add("hassan",19);
	h.add("ibad",17);
	h.add("haris",11);
	h.add("zainab",19);
	h.add("nassah",211);
	h.printall();
}