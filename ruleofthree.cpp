// RULE OF THREE : If a class defines any of the special member functions 
// i.e destructor,copy constructor,copy assignment operator , then it should define all three of them ( best practice)

// -> Rule of three ensures that your code does not misbehave especially when you are working with dynamically allocated
//    memory.
#include <iostream>
using namespace std;

class ruleofthree
{
	private:
		int size;
		int* val;
	public:
		ruleofthree()
		{
			val = new int(0);
			this->size = 0;
		}
		~ruleofthree()       // 1/3  (destructor)
		{
			delete val;
		}		
		ruleofthree(const ruleofthree& other)  // 2/3 (copy constructor)
		{
			this->size = other.size;
			val = new int(*other.val);
		}
		ruleofthree operator =(const ruleofthree &other)
		{
			if(this!=&other)
			{
				val = new int(*other.val);
				size = other.size;
			}
			return *this;
		}
		void setval(int *v,int s)
		{
			*val = *v;
			this->size = s;
		}
		int getval()
		{
			return *val;
		}
		int getsize()
		{
			return size;
		}
};

int main()
{
	ruleofthree r1;
	int v1 = 4;
	r1.setval(&v1,5);
	cout << "r1 val before update : " << r1.getval() << endl;
	cout << "Size of r1 before update : " << r1.getsize() << endl << endl;
	
	ruleofthree r2(r1);   // though copy constructor is not defined , compiler creates its own 
	//(program will crash if we donot create copy constructor)
	
	int v2 = 10;																						
	r1.setval(&v2,11);  // r1 updated
	
	cout << "r1 updated val : " << r1.getval() << endl;
	cout << "r1 updated size : " << r1.getsize() << endl << endl;
	cout << "r2 val (after updating r1) : " << r2.getval() << endl;   
	// since we have created a  copy constructor, the value of 'r2' will not be changed i.e it will be 4
	cout << "Size of r2 : " << r2.getsize() << endl;
	
	// if we do not create copy constructor and change value in 'r1' then value of 'r2' will also be changed because it 
	// points to the same memory address as r1 does, but if we create a copy constructor then the value in 'r2' would not be
	// changed as now we explicitly define that it points to other memory address.	
	
	
	
	// now lets see copy assignment operator : 
	
	// it is used when an obj is already defined and then it gets updated using other object.
	
	ruleofthree r3;
	r3 = r1;
	int v3 = 45;
	r1.setval(&v3,44);
	cout << "\nval of r3 : " << r3.getval() << endl;
	
	// if we donot define assignment operator then it will again point to the same memory address as of 'r1' and thus if we
	// change val of r1 , r3 also changes which we dont want. to solve this we use copy assignment operator.
}