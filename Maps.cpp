#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
	unordered_map<string,int> marks;
	marks["Hassan"] = 88;
	marks["David"] = 66;
	marks["Rohan"] = 45;
	marks.insert({{"Kusume",121},{"Kuroo",231}});
	
	unordered_map<string,int> :: iterator iter;
	for(iter = marks.begin() ; iter!=marks.end() ; iter++)
	{
		cout << (*iter).first << "  " << (*iter).second << endl;
	}
	
	return 0;
}