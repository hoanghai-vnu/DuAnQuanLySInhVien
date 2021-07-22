#ifndef DEF_STUDENT
#define DEF_STUDENT
#include <iostream>
#include <string>
#include <iomanip>

class Student
{
	int m_mssv;
	std::string m_fullname;
public:	
	Student(): m_mssv(0), m_fullname("") {}
	Student(int mssv, std::string fullname): m_mssv(mssv), m_fullname(fullname) {}
	
	int get_mssv() const { return m_mssv; }
	std::string get_fullname() const { return m_fullname; }

	std::string get_name() const;

	void input_info();
	void input_mssv();
	void print_info() const;
	static void print_header();
};

void input_integer(int &x);

#endif // DEF_STUDENT
