#include <iostream>
#include "Shared_Ptr.h"
using namespace std;

class Rectangle
{
	int m_width;
	int m_height;
public:
	Rectangle(int a=0, int b=0): m_width(a), m_height(b) {
		cout << "Rectangle Constructor" << endl;
	}
	int area() const { return m_width * m_height; }
	
	~Rectangle(){ cout << "Rectangle Destructor" << endl; }
};

int main()
{
    Shared_Ptr<Rectangle> P1(new Rectangle(10, 5));
	cout << P1->area() << endl; // This'll print 50
	cout << P1.use_Count() << " refs" << endl;
	cout << P1.ins_Count() << " ins" << endl;

	Shared_Ptr<Rectangle> P2;
	Shared_Ptr<Rectangle> P3(P1);

	P2 = P1;
	
	cout << P3->area() << endl;
	cout << P2->area() << endl;
	cout << P1->area() << endl;
	
	cout << P1.use_Count() << " refs" << endl;
	cout << P2.use_Count() << " refs" << endl;
	cout << P3.use_Count() << " refs" << endl;
	
	cout << P1.ins_Count() << " ins" << endl;
	cout << P2.ins_Count() << " ins" << endl;
	cout << P3.ins_Count() << " ins" << endl;
	
	cout << "At the end of the main ..." << endl;
	cout << "--------------------------" << endl; 
    
    return 0;
}
