/*
	heap is a data structure (CBT) that comes with heap order property.
	CBT:
		1. every level is filled except last
		2. nodes are always added from left to right
		
	Heap order property: 
		1. Max heap : Child should be less than parent
		2. Min heap	: Child should be greater than parent
	Heapify: it is the process of creating heap data structure from a binary tree.it is used to create min heap or a max heap
	
	
	for inserting min time O(1) and max time O(logn)
*/		

#include<bits/stdc++.h>
using namespace std;

class heap
{
	public:
		int *arr;
		int capacity;
		int size;
		heap(int capacity)
		{
			arr = new int[capacity];
			this->capacity = capacity;
			this->size = 0;
		}		
		void insert(int data)
		{
			if(size == capacity)
			{
				cout << "Heap overflow\n";
				return;
			}
			size++;
			int i = size-1;
			arr[i] = data;
			while(i != 0 && arr[parent(i)]>arr[i])
			{
				swap(arr[parent(i)],arr[i]);
				i = parent(i);		
			}
		}
		int height()
		{
			return ceil(log2(size+1)-1);
		}
		int parent(int i)
		{
			return (i-1)/2;	
		}
		int leftChild(int i)
		{
			return ((2*i)+1);	
		}
		int rightChild(int i)
		{
			return((2*i)+2);
		}
		void linearSearch(int val)
		{
			for(int i=0 ; i<size ; i++)
			{
				if(val == arr[i])
				{
					cout << "Value found at index : " << i << endl;
					return;
				}
			}
			cout << "Value not found\n";
			return;
		}
		int searchforLchild(int k)
		{
			for(int i=0 ; i<size ; i++)
			{
				if(k == arr[i])
				{
					return arr[leftChild(i)];
				}
			}
			return -1;
		}
		int searchforRchild(int k)
		{
			for(int i=0 ; i<size ; i++)
			{
				if(k == arr[i])
				{
					return arr[rightChild(i)];
				}
			}
			return -1;
		}
		void print()
		{
			for(int i=0 ; i<size ; i++)
			{
				cout << arr[i] << "  ";
			}
			cout << endl << endl;
			return;
		}
		int extractMin()   // return minimum and removes it from heap also calls heapify()
		{
			if(size<=0)
			{
				return INT_MAX;	
			}  
			else if(size == 1)
			{
				size--;
				return arr[0];
			}
			int root = arr[0];
			arr[0] = arr[size-1];
			size--;
			heapify(0);
			return root;
		}
		void heapify(int i)
		{
			int l = leftChild(i);
			int r = rightChild(i);
			int smallest = i;
			if(l<size && arr[l]<arr[i])
			{
				smallest = l;
			}
			if(r<size && arr[r]<arr[smallest])
			{
				smallest = r;
			}
			if(smallest != i)
			{
				swap(arr[i],arr[smallest]);
				heapify(smallest);
			}
		}
		void heapSort()
		{
			cout << endl;
			for(int i=0 ; i<capacity ; i++)
			{
				int x = extractMin();
				cout << x << "  ";
			}
			cout << endl;
		}
		void kthsmallest(int k)
		{
			for(int i=0 ; i<capacity ; i++)
			{
				int x = extractMin();
				cout << "\t" << x << endl;
				if(k == i+1)
				{
					cout << "Kth smallest: " << x << endl;
				//	return;
				}
			}
		}
		void decrease(int i,int mini)
		{
			arr[i] = mini;
			while(i!=0 && arr[parent(i)]>arr[i])
			{
				swap(arr[i],arr[parent(i)]);
				i = parent(i);
			}
		}
		void deleteKey(int i)
		{
			decrease(i,INT_MIN);
			extractMin();
		}
		~heap()
		{
			delete[] arr;
		}
};

int main()
{
	cout << "Enter capactiy of heap: ";
	int n,ch;
	cin >> n;
	heap h(n);
	while(1)
	{
		cout << "\n-----------------------------------------------------------------------\n";
		cout << "Enter 1 to insert\n";
		cout << "Enter 2 to search\n";
		cout << "Enter 3 to extract minimum\n";
		cout << "Enter 4 to get height of min\n";
		cout << "Enter 5 to traverse heap\n";
		cout << "Enter 6 to get left child of a particular node\n";
		cout << "Enter 7 to get right child of a particular node\n";
		cout << "Enter 8 to delete a particular key\n";
		cout << "Enter 9 to perform heap sort\n";
		cout << "Enter 10 to exit\n";
		cin >> ch;		
		if(ch == 1)
		{
			cout << "Enter data to be inserted: ";
			int k;
			cin >> k;
			h.insert(k);
		}
		else if(ch == 2)
		{
			cout << "Enter value to be searched: ";
			int k;
			cin >> k;
			h.linearSearch(k);
		}
		else if(ch == 3)
		{
			cout << "Minimum value: " << h.extractMin() << endl;
		}
		else if(ch == 4)
		{
			cout << "Height of Heap: " << h.height() << endl;
		}
		else if(ch == 5)
		{
			h.print();
		}
		else if(ch == 6)
		{
			cout << "Get left child of? ";
			int k;
			cin >> k;
			cout << h.searchforLchild(k) << endl;
		}
		else if(ch == 7)
		{
			cout << "Get right child of? ";
			int k;
			cin >> k;
			cout << h.searchforRchild(k) << endl;
		}
		else if(ch == 8)
		{
			cout << "Enter index of key to delete: ";
			int k;
			cin >> k;
			h.deleteKey(k);
		}
		else if(ch == 9)
		{
			cout << "Heap sorted array: ";
			h.heapSort(); 
		}
		else
		{
			break;
		}
		cout << "\n-----------------------------------------------------------------------\n"; 
	}
}