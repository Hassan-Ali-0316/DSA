#include<iostream>
#define GB 10
using namespace std;
class bstnode
{
	public:
		bstnode* left;
		bstnode* right;
		int data;
		bstnode()
		{
			data = 0;
			left = NULL;
			right = NULL;
		}
		bstnode(int d)
		{
			data = d;
			left = NULL;
			right = NULL;
		}
};


class bst
{
	public:
		bstnode* root;
		bst(){root = NULL;}
		void insert(int d)
		{
			bstnode* b1 = new bstnode(d);
			if(root == NULL)
			{
				root = b1;
				root->left = NULL;
				root->right = NULL;
			}
			else
			{
				bstnode* temp = root;
				while(1)
				{
					if(temp->left == NULL && d<temp->data)
					{
						temp->left = b1;
						break;
					}
					else if(temp->left != NULL && d<temp->data)
					{
						temp = temp->left;
					}
					else if(temp->right == NULL && d>temp->data)
					{
						temp->right = b1;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
			}
		}
		void inOrder(bstnode* obj)
		{
			if(obj == NULL)
			{
				return;
			}
			inOrder(obj->left);
			cout << obj->data << "  ";
			inOrder(obj->right);
		}
};

int height(bstnode* obj)
{
	if(obj == NULL)
	{
		return -1;
	}
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
void levelOrder(bstnode* root,int h,int i,int &s)
{
	if(root == NULL)
	{
		return;
	}
	if(h == i)
	{
		cout << root->data << "  ";
	}
	levelOrder(root->left,h-1,i,s);
	levelOrder(root->right,h-1,i,s);
}

void start(bstnode* root)
{
	int h = height(root);
	
	for(int i=h ; i>=0 ; i--)
	{
		int s = 0;
		levelOrder(root,h,i,s);
	//	cout << "Sum of level " << i << ": " << s << endl; 
	}
}

void uses(bst &b1,int arr[],int s,int e)
{
	if(s<=e)
	{
		int mid = (s+e)/2;
		
		b1.insert(arr[mid]);
		uses(b1,arr,s,mid-1);
		uses(b1,arr,mid+1,e);
	}
}

int main()
{	
	bst b1;
	int arr[6] = {1,5,8,11,14,17};
	uses(b1,arr,0,5);
	start(b1.root);
}