/*
 A binary tree is called a balanced binary tree if difference between height of left and right sub tree is not more than k(1).
 balancing tree is important because if we search for a value BST has less time complexity(Ologn) as compared to BT 0(n)

 AVL Tree is a self balancing binary search tree where the difference between heights of left and right subtrees
 can not be more than 1 for all nodes. This difference is called balancing factor (BF)  = {-1 , 0 , 1}
 
 balancing types:
 				1.  LEFT LEFT Imbalance (Right Rotation)
 				2.  RIGHT RIGHT Imbalance (Left Rotation)
 				3.  LEFT RIGHT Imbalance (Left-Right Rotation)
 				4.  RIGHT LEFT Imbalance (Right-Left Rotation)
 
*/ 

#include<iostream>
#define gb 10
using namespace std;

class Node
{
	public:
		Node* left;
		Node* right;
		int data;
		int height;
		Node()
		{
			left = NULL;
			right = NULL;
			data = 0;
			height = -1;
		}
		Node(int d)
		{
			left = NULL;
			right = NULL;
			data = d;
			height = -1;	
		}
};

class AVL
{
	public:
		Node* root;
		AVL()
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
		int height(Node* r)
		{
			if(r == NULL)
			{
				return -1;
			}
			int lh = height(r->left);
			int rh = height(r->right);
			
			if(lh>rh)
			{
				return (lh+1);
			}
			else
			{
				return (rh+1);
			}
		}
		int balanceFactor(Node* temp)
		{
			if(temp == NULL)
			{
				return -1;
			}
			return (height(temp->left) - height(temp->right));
		}
		Node* rightRotate(Node* y)
		{
			Node* x = y->left;
			Node* t2 = x->right;
			// perform rotation
			
			x->right = y;
			y->left = t2;	
			return x;
		}
		Node* leftRotate(Node* x)
		{
			Node* y = x->right;
			Node* t2 = y->left;
			// perform rotation
			
			y->left = x;
			x->right = t2;
			return y;
		}
		Node* insert(Node* root,int d)
		{
			Node* n1 = new Node(d);
			if(root == NULL)
			{
				cout << "\tvalue inserted\n";
				root = n1;
				return root;
			}
			if(d<root->data)
			{
				root->left = insert(root->left,d);
			}
			else if(d>root->data)
			{
				root->right = insert(root->right,d);
			}
			else
			{
				cout << "No duplicates allowed !\n";
			}
			
			int bf = balanceFactor(root);
			// left left case
			if(bf>1 && d<root->left->data)
			{
				return rightRotate(root);
			}
			// right right case
			if(bf<-1 && d>root->right->data)
			{
				return leftRotate(root);
			}
			// left right case
			if(bf>1 && d>root->left->data)
			{ 
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
			if(bf<-1 && d<root->right->data)
			{
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
			return (root);
		}
		Node* smallestnode(Node* root)
		{
			Node* current = root;
			while(current->left != NULL)
			{
				current = current->left;
			}
			return current;
		}
		Node * deleteNode(Node *root, int d) 
		{
		    if (root == NULL) 
			{
		      return NULL;
		    }
		    else if (d<root->data) 
			{
		      root->left = deleteNode(root->left,d);
		    }
		    else if (d>root->data) 
			{
		      root->right = deleteNode(root->right,d);
		    }
		    else 
			{
		      if (root->left == NULL) 
			  {
		        Node *temp = root->right;
		        delete root;
		        return temp;
		      } 
			  else if (root->right == NULL) 
			  {
		        Node *temp = root->left;
		        delete root;
		        return temp;
		      } 
			  else 
			  {
			  	// inorder successor
		        Node *temp = smallestnode(root->right);
		        root->data = temp->data;
		        // Delete the inorder successor 
		        root->right = deleteNode(root->right,temp->data);
		      }
		    }
			if(root == NULL)
			{
				return root;
			}
		    int bf = balanceFactor(root);
		    if (bf>1 && balanceFactor(root->left) >= 0)
		    {
		     	return rightRotate(root);
			}
		    else if (bf<-1 && balanceFactor(root->right) <= 0)
		    {
		    	return leftRotate(root);
			}
		    else if (bf>1 && balanceFactor(root->left) == -1) 
			{
		      root->left = leftRotate(root->left);
		      return rightRotate(root);
		    }
		    else if (bf<-1 && balanceFactor(root->right) == 1) 
			{
		      root->right = rightRotate(root->right);
		      return leftRotate(root);
		    }
		    return root;
		  }
		void preOrder(Node* obj)  // NLR
		{
			if(obj == NULL)
			{
				return;
			}
			cout << obj->data << "  ";
			preOrder(obj->left);
			preOrder(obj->right);
		}
		void postOrder(Node* obj)  // LRN
		{
			if(obj == NULL)
			{
				return;
			}
			preOrder(obj->left);
			preOrder(obj->right);
			cout << obj->data << "  ";
		}
		void inOrder(Node* obj)  // LNR
		{
			if(obj == NULL)
			{
				return;
			}
			preOrder(obj->left);
			cout << obj->data << "  ";
			preOrder(obj->right);
		}
		void levelOrder(Node*root,int level,int h) 
		{
			if(root == NULL)
			{
				return;
			}
			if(level == h)
			{
				cout << root->data << "  ";
			}
			
			levelOrder(root->left,level-1,h);
			levelOrder(root->right,level-1,h);
		}
		void bfs(Node*root)
		{
			int level = height(root);
			for(int i=level ; i>=0 ; i--)
			{
				levelOrder(root,level,i);
			}
		}
		void sumsum(Node* root,int level,int h,int &sum)
		{
			if(root == NULL)
			{
				return;
			}
			if(level == h)
			{
				sum = sum+root->data;
			}
			sumsum(root->left,level-1,h,sum);
			sumsum(root->right,level-1,h,sum);
		}
		int calculatelevelSum(Node* root,int d,int &sum)
		{
			int level = height(root);
			if(d>level)
			{
				cout << "Nat possible\n";
				return -1;
			}
			for(int i=level ; i>0 ; i--)
			{
				sumsum(root,d,i,sum);
			}
			return sum;
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
	for(int i=gb ; i<space ; i++)
	{
		cout << " ";
	}
	cout << obj->data << endl;
	print2d(obj->left,space);
}


int main()
{
	int ch;
	AVL* ob = new AVL();
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
		cout << "Enter 10 to delete node\n";
		cout << "Enter 11 to level order traverse\n";
		cout << "Enter 12 to calculate sum of particular level\n";
		cout << "Enter any key to exit\n";
		cin >> ch;
		if(ch == 1)
		{
			cout << "Enter value to be inserted : ";
			int d;
			cin >> d;
			ob->root =  ob->insert(ob->root,d);
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
//			cout << "Enter value to be searched : ";
//			int v;
//			cin >> v;
//			if(searchRec(ob->root,v) != NULL)
//			{
//				cout << "Value found!!\n";	
//			}	
//			else
//			{
//				cout << "Value not found!!\n";
//			}
		}
		else if(ch == 6)
		{
			cout << "Height of tree : " << ob->height(ob->root) << endl;
		}
		else if(ch == 7)
		{
			cout << "PreOrder Traverse : ";
			ob->preOrder(ob->root);
			cout << endl;
		}
		else if(ch == 8)
		{
			cout << "PostOrder Traverse : ";
			ob->postOrder(ob->root);
			cout << endl;
		}
		else if(ch == 9)
		{
			cout << "inOrder Traverse : ";
			ob->inOrder(ob->root);
			cout << endl;
		}
		else if(ch == 10)
		{
			cout << "Enter value to delete : ";
			int d;
			cin >> d;
			ob->deleteNode(ob->root,d);
			cout << endl;
		}
		else if(ch == 11)
		{
			ob->bfs(ob->root);
		}
		else if(ch == 12)
		{
			cout << "Enter level to calculate sum : ";
			int d;
			cin >> d;
			int sum = 0;
			cout << ob->calculatelevelSum(ob->root,d,sum) << endl << endl;
		}
		else
		{
			break;
		}
	}
	delete ob;		
}