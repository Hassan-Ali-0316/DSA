#include<iostream>
using namespace std;
int main()
{
	// pointers : variables that store address of another variable.
	int a;  // integerr variable
	int *p; // pointer vairable  -> pointer to an integer;
	char *ptr; // > pointer to a character
	p = &a;   // '&' (ampersand) gives us the address of vairable.
	// if we print 'p' it will give address of 'a' , if we print '*p' , it will give value of a;
	// for e.g;
	a = 5;
	cout << p << "  " << &a << endl;   // same output
	cout << *p << endl; // output : 5
	
	*p = 12;  // this is called de-referencing  --> now value of a will become 12
	
	
	// suppose address of 'p' is 2002, if we increment in p , then what will be the output?
	p++; // ??
	// a) 2003 , b) 2006 , c) 13
	
	// Ans : output will be 2006 cuz if p is an int pointer, 
	//it will take us to another int pointer variable, as one int = 4byte
	cout << p << endl;
	
	cout << sizeof(int);
	
	char *charp;
	charp = reinterpret_cast<char*>(p); // typecasting
	cout << "\nsize of char : " << sizeof(charp) << endl;
	cout << "value : " << *charp << endl;
	cout << "value (charp +1) : " << *(charp+1) << endl << endl;
	
	
	//  								pointer to pointers 
	int b = 12;
	int *x = &b;
	int **q = &x;  // current value of p = 12
	int ***r = &q;   // pointer to pointer to pointer
	
	cout << *x << endl;  				// ouput : 12
	cout << x << "  " << &b << endl;   	// output : address of b
	cout << *q << endl;  				// output : address of p;
	cout << *(*q) << endl << endl; 				// output : value at x / of x
	cout << r << endl;					// output : value
	cout << **r << endl;
	cout << ***r << endl;
		
	
}