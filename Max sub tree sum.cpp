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

class check
{
	public:
		int min;
		int maxi;
		bool isBST;
		int sum;
		int summax;
		check()
		{
			min = INT_MAX;
			maxi = INT_MIN;
			isBST = true;
			sum = 0;
			int summax = 0;
		}
};
int co = 0;

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
		check maxsumbst(Node* root,int &maxsum)
		{
			if(root == NULL)
			{
				check c;
				c.maxi = INT_MIN;
				c.min = INT_MAX;
				c.isBST = true;
				c.sum = 0;
				c.summax = maxsum;
				return c;
			}
			if(root->left == NULL && root->right == NULL)
			{
				check c;
				maxsum = max(maxsum,root->data);
				c.maxi = root->data;
				c.min = root->data;
				c.isBST = true;
				c.sum = root->data;
				c.summax = maxsum;
				co++;
				return c;
			}
			
			// traversing left of tree till root->left and root->right both are not null and same for right and there fore all the leaf nodes have values ;
			// check.maxi = value of leaf node
			// check.min = value of leaf node
			// check.isBST = true because a tree with one node is alwaays a bst
			// check.sum = leaf node because only one element
			// check.summax = maxsum   i.e  INT_MIN
			

			check ltree = maxsumbst(root->left,maxsum);
			check rtree = maxsumbst(root->right,maxsum);
			
			check st;
			// only if left sub tree is bst and right sub tree is bst and the maximum of left subtree is less than root data and minimum of right sub tree is
			// greater than only it satisfies the condition of binary search tree.
			// this will be always true for leafnodes
			if(ltree.isBST && rtree.isBST && ltree.maxi<root->data && rtree.min>root->data)
			{
				// here we calculate the maximum element in left sub tree & minimum element of right sub tree
				st.maxi = max(root->data,max(ltree.maxi,rtree.maxi));
				st.min = min(root->data,min(ltree.min,rtree.min));
				co++;
				maxsum = max(maxsum,root->data+ltree.sum+rtree.sum);
				st.sum = (root->data+ltree.sum+rtree.sum);          // calculating sub of each sub tree
				st.summax = maxsum;
				st.isBST = true;
				return st;
			}
			cout << "\nSub tree with root node " << root->data << " is not a perfect BST\n";
			// if above conditions are not satisfied then obviously it is not a bst so we set it false
			st.isBST = false;
			st.summax = maxsum;
			st.sum  = root->data + ltree.sum + rtree.sum;
			co--;
			return st;
		}
		int sol(Node* root)
		{
			int maxsum = INT_MIN;
			return maxsumbst(root,maxsum).summax;
		}
		void insertNode(Node* &root)
		{
			cout << "Do you want to enter to left of " << root->data << " ? (T/F) : ";
			char ch;
			cin >> ch;
			if(ch == 't' || ch == 'T')
			{
				cout << "Enter value to be inserted : ";
				int d;
				cin >> d;
				Node* node1 = new Node(d);
				root->left = node1;	
				insertNode(root->left);
			}
			cout << "Do you want to enter right of " << root->data << " ? (T/F) : ";
			cin >> ch;
			if(ch == 'T' || ch == 't')
			{
				cout << "Enter value to be inserted : ";
				int d;
				cin >> d;
				Node* node1 = new Node(d);
				root->right = node1;	
				insertNode(root->right);
			}
		}
		void inOrder(Node* root)        // LRN
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
	cout << "Enter root value : ";
	int r;
	cin >> r;
	Node* n = new Node(r);
	t.root = n;
	t.insertNode(t.root);
	cout << "Sum is : " << t.sol(t.root) << endl;
	
	cout << endl << endl << "\t\t" << co << endl;
}