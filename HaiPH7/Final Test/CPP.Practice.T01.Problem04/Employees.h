#ifndef DEF_EMPLOYEES
#define DEF_EMPLOYEES
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employees
{
protected:
	string m_account;	// Account e.x TuanNV
	string m_name;		// Name e.x Nguyen Van Tuan
	string m_department; // Department e.x FA.G0
	string m_title;	// job title e.x Developer
public:	
	Employees():m_account(""), m_name(""), m_department(""), m_title("")
	{
		amount++;
	}
	Employees(string account, string name, string department, string title):
		m_account(account), m_name(name), m_department(department), m_title(title)
	{
		amount++;
	}
	~Employees()
	{
		amount--;
	}
	
	static int amount;	// The number of developer employees
	virtual void ShowInformation();	// Show all info of employees
	virtual void DisplayDailyWork() = 0;	// pure virtual function - force override in subclass
};

int Employees::amount = 0;

void Employees::ShowInformation()
{
	cout << left << " " << setw(12) << m_account << setw(25) << m_name;
	cout << setw(20) << m_department << setw(10) << m_title << endl;
}

#endif // DEF_EMPLOYEES
