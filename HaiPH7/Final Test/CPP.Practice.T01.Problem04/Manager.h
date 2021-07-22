#ifndef DEF_MANAGER
#define DEF_MANAGER
#include "Employees.h"
using namespace std;

class Manager: public Employees
{
protected:
	string 	m_customer;	// Customer name
public:	
	Manager(): Employees(), m_customer("")
	{
		amount++;
	}
	Manager(string account, string name, string department, string title, string customer):
		Employees(account, name, department, title), m_customer(customer)
	{
		amount++;
	}
	~Manager()
	{
		amount--;
	}

	static int amount;	// The number of manager employees
	virtual void ShowInformation();	// Show all info of manager employees
	virtual void DisplayDailyWork();
};

int Manager::amount = 0;

void Manager::ShowInformation()
{
	cout << left << " " << setw(12) << m_account << setw(25) << m_name;
	cout << setw(20) << m_department << setw(10) << m_title;
	cout << setw(30) << m_customer << endl;
}
void Manager::DisplayDailyWork()
{
	cout << " " << "Woking with customer: " << m_customer << endl;
}

#endif // DEF_MANAGER
