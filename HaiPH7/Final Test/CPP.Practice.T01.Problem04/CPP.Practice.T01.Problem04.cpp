#include <iostream>
#include <vector>
#include "Employees.h"
#include "Developer.h"
#include "Manager.h"
using namespace std;

int main()
{
	vector<Employees*> list;
	Developer dev1("TuanNV01", "Nguyen Van Tuan", "FA.G0.FRCPP03", "Developer", "FRCPP");
	Developer dev2("ToanNV01", "Nguyen Van Toan", "FA.G0.FRCPP03", "Developer", "FRJAVA");
	Developer dev3("HungNV01", "Nguyen Van Hung", "FA.G0.FRCPP03", "Developer", "FRPYTHON");
	Manager man1("KienNV01", "Nguyen Van Kien", "MA.G3", "Manager", "Donald Trump");
	Manager man2("ManhNV01", "Nguyen Van Manh", "MA.G3", "Manager", "Google");
	Manager man3("ThinhNV01", "Nguyen Van Thinh", "MA.G3", "Manager", "Microsoft");
	
	list.push_back(&dev1);
	list.push_back(&dev2);
	list.push_back(&dev3);
	list.push_back(&man1);
	list.push_back(&man2);
	list.push_back(&man3);
	
	cout << "\nList of all employees:" << endl;
	for(int i=0; i<list.size(); i++)
	{
		list[i]->ShowInformation();
	}
	
	cout << "\nDaily work of all employees:" << endl;
	for(int i=0; i<list.size(); i++)
	{
		list[i]->DisplayDailyWork();
	}
	
	return 0;
}
