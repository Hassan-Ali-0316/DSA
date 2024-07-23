#include<iostream>
#define GB 10
using namespace std;

class Node
{
	public:
		Node* left;
		Node* right;
		int data;
		Node()
		{
			left = NULL;
			right = NULL;
			data = 0;
		}
		Node(int d)
		{
			left = NULL;
			right = NULL;
			data = d;
		}
};

class BST
{
	public:
		Node* root;
		BST()
		{
			root = new Node();
			root = NULL;
		}
		void insert(Node* &root,int d)
		{
			if(root == NULL)
			{
				Node* node1 = new Node(d);
				root = node1;
				return;
			}
			else if(d<root->data)
			{
				insert(root->left,d);
			}
			else if(d>root->data)
			{
				insert(root->right,d);
			}
			else
			{
				cout << "No duplicates allowed!\n";
				return;
			}
		}
		void inOrder(Node* root)
		{
			if(root == NULL)
			{
				return;
			}
			inOrder(root->left);
			cout << root->data << " ";
			inOrder(root->right);
		}
		void print2d(Node* root,int space)
		{
			if(root == NULL)
			{
				return;
			}
			space = space + GB;
			print2d(root->right,space);	
			for(int i=GB; i<space ; i++)
			{
				cout << "  ";
			}
			cout << root->data << endl;
			print2d(root->left,space);
		}
		void deletetree(Node* &root)
		{
			if(root == NULL)
			{
				return;
			}
			deletetree(root->left);
			deletetree(root->right);
			delete root;
		}
};

// if there are n nodes and we make any ith element as node in range of n then total number of distinct trees that could be made are : 
//     no of distinct bst's = no of left subtrees * no or right subtrees
// also number of binary search trees that could be made is catalan series
int catalan(int n)
{
    if (n<=1)
    {
        return 1;
    }
    int cat = 0;
    for (int i=1; i<=n; i++)
    {
        cat = cat + catalan(i - 1) * catalan(n - i);
    }
    return (cat);
}


int main()
{
	cout << "Enter n : ";
	int n;
	cin >> n;
	int arr[n];
	for(int i=0 ; i<n ; i++)
	{
		arr[i] = i+1;	
	}
	
	int res = catalan(n);
	int k = 1;
	cout << "Max trees that could be made : " << res << endl << endl;
	for(int i=0 ; i<res ; i++)
	{
		BST *tree = new BST();
		for(int j=0 ; j<n ; j++)
		{
			tree->insert(tree->root,arr[j]);
		}
		tree->print2d(tree->root,5);
		swap(arr[0],arr[k]);
		if(k == n-1)
		{
			k=1;	
		}	
		else
		{
			k++;
		}
		cout << endl << "--------------------------------------------------------------------------" << endl;
		tree->deletetree(tree->root);
	}
}