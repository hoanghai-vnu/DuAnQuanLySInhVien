#ifndef DEF_STUENT
#define DEF_STUENT
#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
private:
	string m_fullname;
	int m_mssv;
	float m_cpa;
public:	
	Student(string fullname="Nguyen Van A", int mssv=20150000, float cpa=0.0):
		m_fullname(fullname), m_mssv(mssv), m_cpa(cpa)
	{}
	
	static void print_header(){
		cout << endl;
		cout << left << setw(25) << "Full name" << setw(12) << "MSSV" << setw(5) << "CPA" << endl;
		cout << setw(42) << setfill('-') << '-' << endl << setfill(' ');
	}
	
	void print_row(){
		cout << left << setw(25) << m_fullname << setw(12) << m_mssv << setw(5) << setprecision(3) << m_cpa << endl;
	}
};

#endif // DEF_STUENT
