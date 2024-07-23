#include<iostream>
using namespace std;

class node
{
	public:
		node* left;
		node* right;
		int data;
		node()
		{
			left = NULL;
			right = NULL;
		}
		node(int d)
		{
			data = d;
			left = NULL;
			right = NULL;
		}
};

class bst
{
	public:
		node* root;
		bst()
		{
			root = NULL;
		}
		void insert(int d)
		{
			node *n = new node(d);
			if(root == NULL)
			{
				root = n;
				return;
			}
			node* temp = root;
			while(1)
			{
				if(temp->left == NULL && d<temp->data)
				{
					temp->left = n;
					break;
				}
				else if(temp->left != NULL && d<temp->data)
				{
					temp = temp->left;
				}
				else if(temp->right == NULL and d>temp->data)
				{
					temp->right = n;
					break;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
		int height(node* temp)
		{
			if(temp == NULL)
			{
				return -1;
			}
			int lh = height(temp->left);
			int rh = height(temp->right);
			return (max(lh,rh)+1);
		}
		void levelOrder(node* temp,int l,int i,int &x)
		{
			if(temp == NULL)
			{
				return;
			}
			if(l == i)
			{
				x++;
				cout << temp->data << "  ";
			}
			levelOrder(temp->left,l-1,i,x);
			levelOrder(temp->right,l-1,i,x);
		}
		void levelOrderhelp(node* temp)
		{
			int l = height(temp);
			int x = 0;
			for(int i=l ; i>=0 ; i--)
			{
				levelOrder(temp,l,i,x);
				cout << "Number of leaf nodes at level: " << i << " are: " << x << endl;
				x=0;
			}
		}
		int check(node* temp)
		{
			if(temp == NULL)
			{
				return -1;
			}
			int lh = check(temp->left);
			int rh = check(temp->right);
			
			return (max(lh,rh)+1);
		}
		bool aretheySame(node* temp)
		{
			int lh = check(temp->left);
			int rh = check(temp->right);
			return (lh == rh);
		}
};

int main()
{
	bst b;
	b.insert(4);
	b.insert(2);
	b.insert(10);
	b.insert(7);
	b.insert(3);
	b.insert(1);
	b.insert(15);
	cout << endl;
	b.levelOrderhelp(b.root);
	
	if(b.aretheySame(b.root))
	{
		cout << "Trees are at same level\n";
	}
	else
	{
		cout << "Trees are not at same level\n";
	}
	
	int pre[6] = {10,5,1,7,40,50};

	
}