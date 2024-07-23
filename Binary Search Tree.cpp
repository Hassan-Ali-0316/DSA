#include<bits/stdc++.h>
#define gb 10
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

class BST
{
	public:
		Node* root;
		BST()
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
		void insert(int d,Node* temp)
		{
			if(root == NULL)
			{
				Node* n1 = new Node(d);
				root = n1;
				root->left = NULL;
				root->right = NULL;
				cout << "Value inserted at root\n";
			}
			else
			{
				if(temp->left == NULL && d<temp->data)
				{
					Node* n1 = new Node(d);
					temp->left = n1;
				}
				else if(d<temp->data)
				{
					insert(d,temp->right);
				}
				else if(temp->right == NULL && d>temp->data)
				{
					Node* n1 = new Node(d);
					temp->right = n1;
				}
				else
				{
					insert(d,temp->right);
				}
			}
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
};
	
	
void print2d(Node* obj,int space)
{
	if(obj == NULL)
	{
		return;
	}
	space = space + gb;
	print2d(obj->right,space);
	cout << endl;
	for(int i=gb ; i<space ; i++)
	{
		cout << " ";
	}
	cout << obj->data << endl;
	print2d(obj->left,space);
}	

int height(Node* obj)
{
	if(obj == NULL)
	{
		return -1;
	}
//	height(obj->left);
	int lh = height(obj->left);
	int rh = height(obj->right);
	if(lh>rh)
	{
		return (lh+1);
	}
	else
	{
		return (rh+1);
	}
}

Node* search(Node* obj,int val)
{
	if(obj == NULL)
	{
		return NULL;	
	}		
	else
	{
		while(obj != NULL)
		{
			if(val == obj->data)
			{
				return obj;
			}
			else if(val<obj->data)
			{
				obj = obj->left;
			}
			else
			{
				obj = obj->right;
			}
		}
		return NULL;
	}
}	


Node* searchRec(Node* temp,int v)
{
	if(temp == NULL)
	{
		return temp;
	}
	if(v<temp->data)
	{
		return searchRec(temp->left,v);
	}
	else if(v>temp->data)
	{
		return searchRec(temp->right,v);
	}
	else
	{
		return temp;
	}
}

void preOrder(Node* obj)        // NLR
{
	if(obj == NULL)
	{
		return;
	}
	cout << obj->data << "  ";
	preOrder(obj->left);
	preOrder(obj->right);
}

void inOrder(Node* obj)       // LNR
{
	if(obj == NULL)
	{
		return;
	}
	inOrder(obj->left);
	cout << obj->data << "  ";
	inOrder(obj->right);
}

void postOrder(Node* obj)    // LRN
{
	if(obj == NULL)
	{
		return;
	}
	postOrder(obj->left);
	postOrder(obj->right);
	cout << obj->data << "  ";
}

int countNodes(Node* obj)
{
	if(obj == NULL)
	{
		return 0;
	}
	int left = countNodes(obj->left);
	int right = countNodes(obj->right);
	
	return (left+right+1);
}

int sumOfNodes(Node* obj)
{
    if (obj == NULL)
    {
        return 0;
    }

    int leftSum = sumOfNodes(obj->left);
    int rightSum = sumOfNodes(obj->right);

    return obj->data + leftSum + rightSum;
}
void levelorder(Node* root , int level , int h)
{
	if(!root)
	{
		return;
	}
	
	if(level == h)
	{
		cout << root->data << "   ";
	}
	levelorder(root->left,level-1,h);
	levelorder(root->right,level-1,h);
	
	
}
void temp(Node *root)
{	
	int level = height(root);
	
	for(int i = level ; i >= 0 ; i--)
	{
		levelorder(root,level,i);
	}
}


int main()
{
	int ch;
	BST* ob = new BST();
	while(1)
	{
		cout << "Enter 1 to insert\n";
		cout << "Enter 2 to print 2d\n";
		cout << "Enter 3 to check if empty\n";
		cout << "Enter 4 to clear screen\n";
		cout << "Enter 5 to search for node\n";
		cout << "Enter 6 to get height of tree\n";
		cout << "Enter 7 to preorder traverse\n";
		cout << "Enter 8 to postorder traverse\n";
		cout << "Enter 9 to inorder traverse\n";
		cout << "Enter 10 to calculate sum of nodes\n";
		cout << "Enter 11 to count nodes\n";
		cout << "Enter any key to exit\n";
		cin >> ch;
		if(ch == 1)
		{
			cout << "Enter value to be inserted : ";
			int d;
			cin >> d;
			Node* temp = ob->root;
			ob->insert(d,temp);
		}
		else if(ch == 2)
		{
			print2d(ob->root,5);
		}
		else if(ch == 3)
		{
			cout << "Is empty : " << ob->isEmpty() << endl;
		}
		else if(ch == 4)
		{
			system("cls");
		}
		else if(ch == 5)
		{
			cout << "Enter value to be searched : ";
			int v;
			cin >> v;
			if(searchRec(ob->root,v) != NULL)
			{
				cout << "Value found!!\n";	
			}	
			else
			{
				cout << "Value not found!!\n";
			}
		}
		else if(ch == 6)
		{
			cout << "Height of tree : " << height(ob->root) << endl;
		}
		else if(ch == 7)
		{
			cout << "PreOrder Traverse : ";
			preOrder(ob->root);
			cout << endl;
		}
		else if(ch == 8)
		{
			cout << "PostOrder Traverse : ";
			postOrder(ob->root);
			cout << endl;
		}
		else if(ch == 9)
		{
			cout << "inOrder Traverse : ";
			inOrder(ob->root);
			cout << endl;
		}
		else if(ch == 10)
		{
			cout << "Sum of nodes : " << sumOfNodes(ob->root) << endl;
		}
		else if(ch == 11)
		{
			cout << "Number of nodes : " << countNodes(ob->root) << endl;
		}
		else
		{
			break;
		}
	}
	
	cout << endl << endl;
	temp(ob->root);
	delete ob;	
}




bstnode* search(bstnode* obj,int s)
{
	if(obj == NULL)
	{
		return obj;	
	}	
	else
	{
		if(s<obj->data)
		{
			obj = search(obj->left,s);
		}
		else if(s>obj->data)
		{
			obj = search(obj->right,s);
		}
		else
		{
			return obj;
		}
	}
	return obj;
}


void deleteNode(bstnode* &root,int d)
{
	if(root == NULL)
	{
		return;
	}
	if(d<root->data)
	{
		deleteNode(root->left,d);
	}
	else if(d>root->data)
	{
		deleteNode(root->right,d);
	}
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if(root->left == NULL)
		{
			bstnode* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			bstnode* temp = root;
			root = root->left;
			delete temp;
		}
		else //if(root->left != NULL && root->right != NULL)
		{
			bstnode* temp = root->right;
			while(temp->left != NULL)
			{
				temp = temp->left;
			}
			root->data = temp->data;
			deleteNode(root->right,temp->data);
		}
	}
}