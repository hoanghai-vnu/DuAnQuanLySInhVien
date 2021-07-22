#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
	Point A;
	Point B(2,2);
	Point C(B);
	C.setY(3);
	
	cout << "A" << A.info() << endl;
	cout << "B" << B.info() << endl;
	cout << "C" << C.info() << endl;
	cout << "distance(A, B) = " << distance(A, B) << endl;
	cout << "distance(B, C) = " << distance(B, C) << endl;
	cout << "Dotproduct A.C = " << dotProduct(B, C) << endl;	

    return 0;
}
