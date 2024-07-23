#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int value) : data(value),next(NULL){}	
};

class LinkedList
{
	private:
		Node* head;
		
	public:
		LinkedList() : head(NULL){}

		void insert(int x)
		{
			Node* temp = new Node(x);
			temp->next = head;           // since head stores null, now temp->next i.e , next node will store null
			head = temp;	
		}		
		void print()
		{
			Node* temp = head;
			while(temp != NULL)
			{
				cout << "Current Data : " << temp->data << "   address : " << temp->next << endl;
				temp = temp->next;
			}
		}
};

 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> temp;
        int flag = 0;
        for(int i=0 ; i<nums2.size() ; i++)
        {
            for(int j=0 ; j<nums1.size() ; j++)
            {
                if(nums1[i] == nums2[j])
                {
                    for(int k=0 ; k<temp.size() && temp.size() != 0; k++)
                    {
                        if(nums1[i] == temp[k])
                        {
                            flag = 1;
                        }
                        if(flag!=1)
                        {
                            temp.push_back(nums1[i]);
                        }
                        flag = 0;
                    }
                }  
            }
        }
        return temp;
    }

int main()
{
//	LinkedList l;
//	l.insert(5);
//	l.insert(34);
//	l.insert(432);
//	l.print();

	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(2);
	nums1.push_back(1);
	
	vector<int> nums2;
	nums2.push_back(2);
	nums2.push_back(2);	
	
	vector<int> temp = intersection(nums1,nums2);
	for(int i=0 ; i<temp.size() ; i++)
	{
		cout << temp[i] << endl;
	}
}