#include<bits/stdc++.h>
using namespace std;

int mid(stack<int> s)
{
	int si = s.size();
	if(si%2 == 0)
	{
		return (s.size()/2);
	}
	else
	{
		return (s.size()+1)/2;
	}
}

void deletemid(stack<int> &s,int m,int t)
{
	if(m == t)
	{
		s.pop();
		return;
	}
	int top = s.top();
	s.pop();
	t--;
	deletemid(s,m,t);
	s.push(top);
}

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	int t = s.size();
	int m = mid(s);
	deletemid(s,m,t);
	while(!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}