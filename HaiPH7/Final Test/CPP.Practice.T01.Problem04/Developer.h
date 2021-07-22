#ifndef DEF_DEVELOPER
#define DEF_DEVELOPER
#include "Employees.h"
using namespace std;

class Developer : public Employees
{
protected:
	string m_project;	// Project name
public:	
	Developer(): Employees(), m_project("")
	{
		amount++;
	}
	Developer(string account, string name, string department, string title, string project):
		Employees(account, name, department, title), m_project(project)
	{
		amount++;
	}
	~Developer()
	{
		amount--;
	}

	static int amount;	// The number of employees
	virtual void ShowInformation();	// Show all info of developer employees
	virtual void DisplayDailyWork();
};

int Developer::amount = 0;

void Developer::ShowInformation()
{
	cout << left << " " << setw(12) << m_account << setw(25) << m_name;
	cout << setw(20) << m_department << setw(10) << m_title;
	cout << setw(30) << m_project << endl;
}
void Developer::DisplayDailyWork()
{
	cout << " " << "Coding in project: " << m_project << endl;
}

#endif // DEF_DEVELOPER
