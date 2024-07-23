#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

void subset(int *arr, int s, int sum, int x, vector<int> &sets)
{
	if(sum == 0)	
	{
		for(int i=0 ; sets.size() ; i++)
		{
			cout << sets[i] << "  ";	
		}
		return;
	}
	subset(arr,s,sum,x+1,sets);
	if(sets[x]<=sum)
	{
		sets.push_back(arr[x]);
		subset(arr,s,sum-arr[x],x+1,sets);
		sets.pop_back();
	}
}
int count = 0;
void countOnes(int num) // 10
{
	if(num<=0)
	{
		cout << "Number of ones : " << count << endl;
		return;
	}
	if(num%2 == 1)
	{
		count++;
	}
	countOnes(num/2);
}

int d = 0;
void digits(int num)
{
	if(num<=0)
	{
		cout << "Digits : " << d << endl;
		return;
	}
	d++;
	digits(num/10);
}

void maxi(int *arr, int s, int cur, int max, int min)
{
	if(cur == s)
	{
		cout << "Maximum element : " <<  max << endl;
		cout << "Minimum element : " << min << endl;
		return;
	}
	if(arr[cur] > max)
	{
		max = arr[cur];
	}
	if(arr[cur] < min)
	{
		min = arr[cur];
	}
	maxi(arr,s,cur+1,max,min);
}

void escape(int n, int &count)
{
	if(n == 0)
	{
		count++;
		return;
	}
	if(n<0)
	{
		return;
	}
	escape(n-1,count);
	escape(n-2,count);
	escape(n-4,count);
//	return escape(n-4,total)+escape(n-2,total)+escape(n-1,total);
}
void sayDigits(vector<string> str,int num)
{
	if(num==0)
	{
		return;
	}
	int d = num%10;
	sayDigits(str,num/10);
	cout << str[d] << "  ";
}

void possible(string str, int k, string empty, int cur)
{
	if(cur == str.length())
	{
		cout << empty << endl;	
		return;
	}	
	possible(str,k,empty,cur+1);
	empty.push_back(str[cur]);
	possible(str,k,empty,cur+1);
}

void key(string a , int k, string empty)
{
	if(empty.size()== k)
	{
		for(int i=0 ; empty.size() ; i++)
		{
		cout << empty[i] << endl;
		}
		cout<<" ";
		return;
	}
	for(int i=0 ; i<a.length() ; i++)
	{
		key(a,k,empty+a[i]);
	}
}

void palindrome(string &str,int l,int cur)
{
    
    if(cur > l){
    	return;
	}
	 
     swap(str[cur],str[l]);
	 palindrome(str,l-1,cur+1);
    	
	
}
int main()
{
	int num = 155;
	int count = 0;
	countOnes(num);
	digits(num);
	int s = 10;
	int *arr = new int[s];
	srand(time(0));
	for(int i=0 ; i<s ; i++)
	{
		int r = rand() % 100;
		arr[i] = r;
	}
	for(int i=0 ; i<s ; i++)
	{
		cout << arr[i] << "  " ;
	}
	cout << endl;
	maxi(arr,s,0,0,9999999);
	
	delete[] arr;
	cout << endl;
	
	vector<string> str;
	str.push_back("Zero");
	str.push_back("One");
	str.push_back("Two");
	str.push_back("Three");
	str.push_back("Four");
	str.push_back("Five");
	str.push_back("Six");
	str.push_back("Seven");
	str.push_back("Eight");
	str.push_back("Nine");
	sayDigits(str,112);
	
	cout << endl << endl << "Raju\n";
	int cOunt = 0;
	escape(10,cOunt);
	cout << cOunt << endl << endl;
	
	string ch = "abc";
	string empty = "";
	key(ch,3,empty);
}
