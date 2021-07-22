#include <iostream>
#include "Shared_Ptr.h"
using namespace std;

class ClassB;	// class forward declaration

class ClassA
{
public:
	Shared_Ptr<ClassB> m_data;
	ClassA() { cout << "A constructor" << endl; }
	~ClassA() { cout << "A destructor" << endl; }
};

class ClassB
{
public:
	Shared_Ptr<ClassA> m_data;
	ClassB() { cout << "B constructor" << endl; }
	~ClassB() { cout << "B destructor" << endl; }
};

int main()
{
    Shared_Ptr<ClassA> sharedA(new ClassA());
	Shared_Ptr<ClassB> sharedB(new ClassB());

	cout << "ref count A: " << sharedA.use_Count() << endl;
	cout << "ref count B: " << sharedB.use_Count() << endl;

	sharedA->m_data = sharedB;
	sharedB->m_data = sharedA;
	
	cout << "ref count A: " << sharedA.use_Count() << endl;
	cout << "ref count B: " << sharedB.use_Count() << endl;
	
	cout << "At the end of the main ..." << endl;
	cout << "--------------------------" << endl; 
	return 0;
}
