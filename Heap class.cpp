#include<iostream>
#include<math.h>
using namespace std;

class contact
{
	public:
		string name;
		int grade;
		int age;
		contact(){}
		contact(string n,int a,int g)
		{
			name = n;
			age = a;
			grade = g;	
		}	
		void print()
		{
			cout << name << "   " << age << "  " << grade << endl;
		}
};

class heap
{
	public:
		int capacity;
		int size;
		contact* c;
		heap()
		{
			capacity = 0;
			size = 0;
		}
		heap(int c1)
		{
			capacity = c1;
			size = 0;
			c = new contact[c1];
		}
		int parent(int i)
		{
			return (i-1)/2;
		}
		void insert(string n,int a,int g)
		{
			if(size == capacity)
			{
				cout << "HEAP OVERFLOW\n";
				return;
			}
			contact temp(n,a,g);
			if(size == 0)
			{
				c[size] = temp;
				size++;
			}
			else
			{
				size++;
				int i = size-1;
				c[i] = temp;
				while(i!=0 && c[i].age<c[parent(i)].age)
				{
					swap(c[i],c[parent(i)]);
					i = parent(i);
				}
			}
		}
		int lchild(int i)
		{
			return (i*2)+1;
		}
		int rchild(int i)
		{
			return (i*2)+2;
		}
		contact extractMin()
		{
			if(size<=0)
			{
				return c[0];
			}
			if(size == 1)
			{
				return c[0];
				size--;
			}
			contact temp;
			temp = c[0];
			c[0] = c[size-1];
			size--;
			heapify(0);
			return (temp);
		}

	void heapify(int i)
	{
	    int lc = lchild(i);
	    int rc = rchild(i);
	    int smallest = i;
	
	    if (lc < size && c[lc].age < c[i].age) {
	        smallest = lc;
	    }
	    if (rc < size && c[rc].age < c[smallest].age) {
	        smallest = rc;
	    }
	    if (smallest != i)
	    {
	        swap(c[i], c[smallest]);
	        heapify(smallest);
	    }
	}

		void print()
		{
			for(int i=0 ; i<size ; i++)
			{
				cout << c[i].name << "   " << c[i].age << "   " << c[i].grade << endl;
			}
			cout << endl;
		}
		int find(string name)
		{
			for(int i=0 ; i<size ; i++)
			{
				if(name == c[i].name)
				{
					return i;
				}
			}
		}
		void decrease(int i,int mini)
		{
			c[i].age = mini;
			while(i!=0 && c[i].age<c[parent(i)].age)
			{
				swap(c[i],c[parent(i)]);
				i = parent(i);
			}
			
		}
		contact deleteKey(string name)
		{
			int k = find(name);
			int mini = INT_MIN;
			decrease(k,mini);
			contact temp;
			temp = extractMin();
			return temp;
		}
		int height()
		{
			return (ceil(log2(size+1)-1));
		}
};

int main()
{
	heap h(5);
	h.insert("hassan",13,100);
	h.insert("khair",2,201);
	h.insert("ibad",21,150);
	h.insert("haris",41,300);
//	h.print();
	cout << "Now heapifying according to grade\n\n";
	
	contact temp;
//	temp = h.extractMin();
	
//	h.print();
//	temp.print();
	h.insert("REHMAN",4,132);
	h.insert("hunain",312,2);
	h.print();
	cout << endl<< endl;
	temp = h.deleteKey("haris");
	h.print();
	cout << endl << endl;
	temp.print();
	cout << endl;
	cout << h.height();
}