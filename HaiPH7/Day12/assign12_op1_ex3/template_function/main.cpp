#include <iostream>
#include "PhanSo.h"
#include "tuan.h"
using namespace std;

int main()
{
	PhanSo ps1(1, 2), ps2(3, 4);
	cout << "ps1 = " << ps1 << endl;	
	cout << "ps2 = " << ps2 << endl;	
	cout << "ps1 + ps2 = " << ps1+ps2 << endl;	
	cout << "ps1 * ps2 = " << ps1*ps2 << endl;	
	cout << "add(ps1, ps2) = " << add(ps1, ps2) << endl;	
	cout << "multiple(ps1, ps2) = " << multiple(ps1, ps2) << endl;	
/*	
	cout << "--------------------------------------\n";
	int a(3), b(5);
	double c(2.2), d(2.5);
	
	cout << "add(a, b) = " << add(a, b) << endl;
	cout << "add(c, d) = " << add(c, d) << endl;
	
	cout << "multiple(a, b) = " << multiple(a, b) << endl;
	cout << "multiple(c, d) = " << multiple(c, d) << endl;
*/
    return 0;
}
