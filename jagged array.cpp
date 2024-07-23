#include<iostream>
#include<vector>
using namespace std;

float cgpa(const vector<int> &sumgpa)
{
	float sum = 0;
	for(int i=0 ; i<sumgpa.size() ; i++)
	{
		sum = sum + sumgpa[i];
	}
	return sum;
}
int main()
{
	int rows;
	cout << "Enter number of people : ";
	cin >> rows;
	string *names = new string[rows];
	for(int i=0 ; i<rows ; i++)
	{
		cout << "Enter name of student : " << i+1 << " : ";
		cin >> names[i];
	}
	int subject;
	cout << "\nEnter total number of subjects : ";
	cin >> subject;
	string *subs = new string[subject];
	for(int i=0 ; i<subject ; i++)
	{
		cin >> subs[i];
	}
	
	float **gpa = {new float*[rows]{}};
	vector<int> taken;
	vector<float> sumgpa;
	int temp;
	float sum=0;
	cout << endl;
	for(int i=0 ; i<rows ; i++)
	{
		sum=0;
		cout << "Enter number of subjects " << names[i] << " attempted : ";
		cin >> temp;
		cout << endl;
		taken.push_back(temp);
		for(int j=0 ; j<rows ; j++)
		{
			gpa[i] = new float[taken[i]];
		}
		for(int j=0 ; j<taken[i] ; j++)
		{ 
			cout << "Enter grade point avg of subject " << j+1 << " : ";
			cin >> gpa[i][j];	
			sum = sum + gpa[i][j];
		}
		float x = sum/taken[i];
		sumgpa.push_back(x);
		cout << endl;
	}
	cout << "\n\t   ";
	for(int i=0 ; i<subject ; i++)
	{
		cout << subs[i] << "     ";
	}
	cout << endl;
	for(int i=0 ; i<rows ; i++)
	{
		cout << names[i];
		for(int j=0 ; j<taken[i] ; j++)
		{
			cout << "   " << gpa[i][j] << "    ";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "CGPA of All Students : \n";
	for(int i=0 ; i<rows ; i++)
	{
		cout << names[i] << " : "<< sumgpa[i] << endl;
	}
	
	
	for(int i=0 ; i<rows ; i++)
	{
		delete[] gpa[i];
	}
	delete[] names;	
	delete[] subs;
	delete[] gpa;
		
}