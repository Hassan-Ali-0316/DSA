#include<iostream>
#define GB 10
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;
		Node()
		{
			data = 0;
			left = NULL;
			right = NULL;
		}
		Node(int d)
		{
			data = d;
			left = NULL;
			right = NULL;
		}
};

bool flag = 0;

class BinarySearchTree
{
	public:
		Node* root;
		BinarySearchTree()
		{
			root = NULL;
		}
		bool isEmpty()
		{
			if(root == NULL)
			{
				return true;
			}
			return false;
		}
		void insertNode(int d)
		{
			Node* n1 = new Node(d);
			if(root == NULL)
			{
				cout << "Value inserted at root\n";
				root = n1;
				return;
			}
			Node* temp = root;
			while(temp != NULL)
			{
				if(temp->left == NULL && d<temp->data)
				{
					temp->left = n1;
					cout << "Value inserted to left\n";
					break;
				}
				else if(d<temp->data)
				{
					temp = temp->left;
				}
				else if(temp->right == NULL && d>temp->data)
				{
					temp->right = n1;
					cout << "Value inserted to right\n";
					break;
				}
				else if(d>temp->data)
				{
					temp = temp->right;
				}
				else
				{
					cout << "No duplicated allowed \n";
					return;
				}
			}
		}
		Node* findMin(Node* root)
		{
			while(root->left != NULL)
			{
				root = root->left;
			}
			return root;
		}
		Node* deleteNode(Node* &root,int d)
		{
			if(root == NULL)
			{
				return NULL;
			}
			else if(d<root->data)
			{
				root->left = deleteNode(root->left,d);
			}
			else if(d>root->data)
			{
				root->right = deleteNode(root->right,d);
			}
			else
			{
				flag = 1;
				if(root->left == NULL)
				{
					Node* temp = root->right;
					delete root;
					return temp;
				}
				else if(root->right == NULL)
				{
					Node* temp = root->left;
					delete root;
					return temp;
				}
				else // if root has both children
				{
					Node* temp = findMin(root->right);
					root->data = temp->data;
					root->right = deleteNode(root->right,temp->data);
				}
			}
			return root;
		}
		void inOrder(Node* root)
		{
			if(root == NULL)
			{
				return;
			}
			inOrder(root->left);
			cout << root->data << "  ";
			inOrder(root->right);
		}
		void print2d(Node* root,int space)
		{
			if(root == NULL)
			{
				return;
			}
			space = space  + GB;
			print2d(root->right,space);
			for(int i=GB ; i<space ; i++)
			{
				cout << "  ";
			}
			cout << root->data << endl;
			print2d(root->left,space);
		}
};

int main()
{
	BinarySearchTree t;
	t.insertNode(10);
	t.insertNode(5);
	t.insertNode(11);
	t.insertNode(4);
	t.insertNode(7);
	t.insertNode(8);
	cout << endl << "Inorder traverse: ";
	t.inOrder(t.root);
	cout << endl << endl;
	t.print2d(t.root,5);
	
	cout << endl << "-------------------------------------------------------"<< endl;
	
	cout << "Enter X : ";
	int x;
	cin >> x;
	cout << "1. Ceil \n2. Floor\n";
	int dec;
	cin >> dec;
	if(dec == 1)
	{
		x = x+1;
	}
	else
	{
		x = x-1;
	}
	t.deleteNode(t.root,x);
	if(flag == 0)
	{
		cout << "Value " << x << " not found !! hence inserting it in BST..." << endl;
		t.insertNode(x);
	}
	else
	{
		cout << "Value " << x << " found !! hence deleting it from BST..." << endl;
	}
	cout << endl << "-------------------------------------------------------"<< endl;
	t.print2d(t.root,5);
}