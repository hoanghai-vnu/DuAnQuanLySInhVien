#include <iostream>
#include "MaTran.h"
using namespace std;

int main()
{
	int n, m;
	int choice = 0;
	cout << "Enter the number of rows: "; cin >> n;
	cout << "Enter the number of columns: "; cin >> m;
	MaTran A(n, m), B(n,m), C;
	
	cout << "Enter the element of the first matrix: " << endl;
	A.input();
	cout << "The matrix A you just enterd: " << endl;
	A.output();

	cout << "Enter the element of the second matrix: " << endl;
	B.input();
	cout << "The matrix B you just entered: " << endl;
	B.output();
	
	cout << "Select the calculation you want to perform:" << endl;
	cout << "\t1. Add" << endl;
	cout << "\t2. Sub" << endl;
	cout << "\t3. Multiple" << endl;
	cout << "\t4. Divide" << endl;
	cout << "Enter the number at the beginning of the operation you want (1, 2, 3 or 4): ";
	cin >> choice;
	
	switch(choice){
		case 1:
			cout << "Sum of two matrices A and B is: " << endl;
			C = A + B;
			C.output();
			break;
		case 2:
			cout << "Sub of two matrices A and B is: " << endl;
			C = A - B;
			C.output();
			break;
		case 3:
			cout << "Multiply of two matrices A and B is: " << endl;
			C = A * B;
			C.output();				
			break;
		case 4:
			cout << "Divide of two matrices A and B is: " << endl;
			C = A / B;
			C.output();				
			break;
		default:
			cout << "The number you entered not valid!" << endl;
			break;
	}
	
    return 0;
}
