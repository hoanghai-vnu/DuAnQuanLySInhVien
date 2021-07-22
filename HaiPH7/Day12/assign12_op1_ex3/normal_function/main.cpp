#include <iostream>
#include "tuan.h"
using namespace std;
int main()
{
	int a(3), b(5);
	double c(2.2), d(2.5);
	
	cout << "add(a, b) = " << add(a, b) << endl;
	cout << "add(c, d) = " << add(c, d) << endl;
	
	cout << "multiple(a, b) = " << multiple(a, b) << endl;
	cout << "multiple(c, d) = " << multiple(c, d) << endl;
	
    return 0;
}
