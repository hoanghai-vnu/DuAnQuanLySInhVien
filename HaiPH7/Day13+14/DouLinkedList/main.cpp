#include <iostream>
#include <string>
#include "Student.h"
#include "DouLinkedList.h"
using namespace std;

void print_help();
// Demo data to test other features if you don't want to type input
void demo_input_data(DouLinkedList &list);
// Nhap thong tin sinh vien, ma so sinh vien phai la duy nhat
void input_data(DouLinkedList &list);
void search_student(DouLinkedList const& list);
void remove_by_mssv(DouLinkedList &list);
void sort_student_list(DouLinkedList &list);

int main()
{
	DouLinkedList listStudents;
	int choice = 0;
	bool loop = false;
		
	// Nhap thong tin sinh vien
//	demo_input_data(listStudents);
	
	cout << "------------------------------------------------------\n";
	print_help();
	
	do
	{
		cout << "\n=> The feature you choice: ";
		input_integer(choice);	// in header Student.h file
		
		switch(choice)
		{
			case 0:
				print_help();
				loop = true;
				break;
				
			case 1:
				input_data(listStudents);
				cout << "------------------------------------------------------\n";
				loop = true;
				break;
				
			case 2: // In ra danh sach sinh vien vua nhap: head -> tail
				cout << "The list of students is:" << endl;
				Student::print_header();
				listStudents.print_down();
				cout << "------------------------------------------------------\n";
				loop = true;
				break;
			
			case 3:// Tim kiem sinh vien
				search_student(listStudents);
				cout << "------------------------------------------------------\n";
				loop = true;
				break;
				
			case 4:// Xoa sinh vien khoi danh sach
				remove_by_mssv(listStudents);
				cout << "\nAfter remove, list of students is:" << endl;
				listStudents.print_down();
				cout << "------------------------------------------------------\n";
				loop = true;
				break;
				
			case 5:	// Sap xep danh sach sinh vien
				sort_student_list(listStudents);
				cout << "------------------------------------------------------\n";
				loop = true;
				break;
			default:
				loop = false;
				break;
		}	
	} while (loop);

    return 0;
}

void print_help()
{
	cout << "Please choose the feature you want to do:" << endl;
	cout << "\t. 0 - to print this list\n";
	cout << "\t. 1 - add student to list\n";
	cout << "\t. 2 - print student's list\n";
	cout << "\t. 3 - search student\n";
	cout << "\t. 4 - remove student\n";
	cout << "\t. 5 - sort student's list\n";
	cout << "\t. other integer number to exit!\n";
}

void demo_input_data(DouLinkedList &list)
{
	Student *s1 = new Student(1006, "Nguyen Duc Thinh");
	Student *s2 = new Student(1003, "Nguyen Van Tuan");
	Student *s3 = new Student(1004, "Tran The Hung");
	Student *s4 = new Student(1002, "Nguyen Anh Tuan");
	Student *s5 = new Student(1005, "Nguyen Anh Tuan");
	Student *s6 = new Student(1001, "Duong Hoang Quan");
	Student *s7 = new Student(1007, "Tran Ngoc Toan");
	list.add_tail(s1);
	list.add_tail(s2);
	list.add_tail(s3);
	list.add_tail(s4);
	list.add_tail(s5);
	list.add_tail(s6);
	list.add_tail(s7);
}

void input_data(DouLinkedList &list)
{
	int amount = 0;
	cout << "Enter the number of students you want to add to the list: ";
	cin >> amount;
	cin.ignore(100, '\n');
	
	for(int i=0; i<amount; i++)
	{
		// Input
		cout << "\nStudent " << i+1 << ":\n";
		Student *st = new Student;
		st->input_info();
			
		// Add to list
		while( const Node *temp = list.find_mssv(st->get_mssv()) )
		{
			cout << "\n=> The student information you just entered\n"; 
			cout << "   has the same MSSV as the following student:\n\t";
			temp->data->print_info();
			cout << "\nPlease re-enter mssv for: " << st->get_fullname() << endl;
			st->input_mssv();
		}
		// Add to the end of list
		list.add_tail(st);		// Using no-copy data version of add tail
	}
}

// To use switch and clear - declare variable
void search_mssv(DouLinkedList const& list);
void search_fullname(DouLinkedList const& list);
void search_name(DouLinkedList const& list);

void search_student(DouLinkedList const& list)
{
	int choice = 0;
	bool loop = false;
	
	cout << "Please choose how to search for students:" << endl;
	cout << "\t. 1 - search by mssv\n";
	cout << "\t. 2 - search by full name\n";
	cout << "\t. 3 - search by name\n";
	cout << "\t. other integer number to exit!\n";
	do
	{
		cout << "\n=> The criteria you choice to search: ";
		input_integer(choice);	// in header Student.h file
		
		switch(choice)
		{
			case 1:
				search_mssv(list);	
				loop = true;
				break;
			case 2:
				search_fullname(list);					
				loop = true;
				break;
			case 3:
				search_name(list);				
				loop = true;
				break;
			default:
				loop = false;
				break;
		}
	} while (loop);
}

void remove_by_mssv(DouLinkedList &list)
{
	int mssv;
	cout << "Enter the mssv of the student you want to delete: " << endl;
	do
	{
		cout << "Enter mssv (1000 - 9999 | other number to exit!): ";
		input_integer(mssv);
		if(1000 <= mssv && mssv <= 9999)
			list.remove(mssv);
	} while( 1000 <= mssv && mssv <= 9999 );
}

void sort_student_list(DouLinkedList &list)
{
	int choice = 0;
	bool loop = false;
	
	cout << "Please choose how to sort you want for students list:" << endl;
	cout << "\t. 1 - sort by mssv\n";
	cout << "\t. 2 - sort by full name\n";
	cout << "\t. 3 - sort by name\n";
	cout << "\t. other integer number to exit!\n";
	
	do
	{
		cout << "\n=> The criteria you choice to sort: ";
		input_integer(choice);	// in header Student.h file
		
		switch(choice)
		{
			case 1:
				list.sort_mssv();
				cout << "=> Result: \n";
				list.print_down();
				loop = true;
				break;
			case 2:
				list.sort_fullname();
				cout << "=> Result: \n";
				list.print_down();
				loop = true;
				break;
			case 3:
				list.sort_name();
				cout << "=> Result: \n";
				list.print_down();
				loop = true;
				break;
			default:
				loop = false;
				break;
		}
	} while (loop);
}

void search_mssv(DouLinkedList const& list)
{
	int mssv;
	cout << "Enter a mssv: "; input_integer(mssv);
	const Node *res = list.find_mssv(mssv);
						
	cout << "=> Result: \n";
	if(res == NULL)
		cout << "\tNo results found for mssv: " << mssv << endl;
	else
		res->data->print_info();
}

void search_fullname(DouLinkedList const& list)
{
	string fullname;
	DouLinkedList res;
				
	cout << "Enter a full name: "; 
	getline(cin, fullname);
	res.find_fullname(list, fullname);
				
	cout << "=> Result: \n";
	if(res.get_head() == NULL)
		cout << "\tNo results found for full name: " << fullname << endl;
	else
		res.print_down();
}

void search_name(DouLinkedList const& list)
{
	string name;
	DouLinkedList res;
			
	cout << "Enter a name: "; cin >> name;
	res.find_name(list, name);
				
	cout << "=> Result: \n";
	if(res.get_head() == NULL)
		cout << "\tNo results found for name: " << name << endl;
	else
		res.print_down();
}
