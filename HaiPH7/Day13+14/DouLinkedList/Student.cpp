#include "Student.h"
using namespace std;

string Student::get_name() const
{
	int i=m_fullname.size()-1;
	// phòng trường hợp tên không có dấu cách thì trả về fullname
	while(m_fullname[i] != ' ' && i > -1)	
		i--;
	return m_fullname.substr(i+1);
}

void Student::input_info()
{
	input_mssv();
	
	string s;
	cout << "Enter student's full name: ";
	getline(cin, s);
	
	// trim whitespace at both ends of the string
	int begin=0;
	while(s[begin] == ' ')
		begin++;
	int end=s.size()-1;
	while(s[end] == ' ')
		end--;
		
	m_fullname = s.substr(begin, end-begin+1);
}

void Student::input_mssv()
{
	do
	{
		cout << "Enter mssv (1000 - 9999): ";
		input_integer(m_mssv);
	} while( !(1000 <= m_mssv && m_mssv <= 9999));
}

void Student::print_info() const
{
	cout << left << setw(8) << m_mssv << setw(30) << m_fullname << endl;
}

void Student::print_header()
{
	cout << left << setw(8) << "MSSV" << setw(30) << "Full Name" << endl;
	cout << left << setw(30) << setfill('-') << '-' << endl << setfill(' ');
}

void input_integer(int &x)
{
	while(!(cin >> x))
	{
		cout << "Not valid. Please enter an integer number: ";
		cin.clear();
		cin.ignore(100, '\n');
	}
	 cin.ignore(100, '\n');	// to enter a string
}
