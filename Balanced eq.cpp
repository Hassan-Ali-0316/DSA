#include<bits/stdc++.h>
using namespace std;


bool checksame(char c1,char c2)
{
	if(c1 == '(' && c2 == ')')
	{
		return true;
	}
	else if(c1 == '[' && c2 == ']')
	{
		return true;
	}
	else if(c1 == '{' && c2 == '}')
	{
		return true;
	}
	else
	{
		return false;
	}	
}

bool checkexp(string exp)
{
	stack<char> st;
	int l = exp.length();
	for(int i=0 ; i<l ; i++) 
	{
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
		{
			st.push(exp[i]);
		}	
		else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if(st.empty())
			{
				return false;
			}
			if(checksame(st.top(),exp[i]))
			{
				st.pop();
			}
		}
		else
		{
			return false;
		}
	}
	if(st.empty())
	{
		return true;
	}
	return false;
}

int main()
{
	string exp;
	cout << "Enter expression (only bracketts) : ";
	cin >> exp;
	if(checkexp(exp))
	{
		cout << "Expression is balanced!\n";
	}
	else
	{
		cout << "Expression not balanced!\n";
	}
}