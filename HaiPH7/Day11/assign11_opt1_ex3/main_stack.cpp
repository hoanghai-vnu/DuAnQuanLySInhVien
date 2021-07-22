#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Stack.h"
#include "Student.h"
using namespace std;

void readData(const string &filename, Stack<Student> &listSV);
void testStackStudent();
void testStackInteger();
void testStackDouble();

int main()
{
//	testStackStudent();
//	testStackInteger();
	testStackDouble();
	
    return 0;
}

void testStackStudent()
{
	Stack<Student> listSV(10);
	string filename("data.txt");
	
	readData(filename, listSV);
	
	cout << endl << "Print list of students using show() method of Stack (to check):" << endl;
	listSV.show();
	
	cout << endl << "Print list of students using peak() and pop() method of Stack:" << endl;
	Student::print_header();
	while(!listSV.isEmpty()){
		listSV.peek().print_row();
		listSV.pop();
	}
}

void testStackInteger()
{
	Stack<int> listInt(10);
	
	// Push data to Integer stack
	for(int i=0; i<11; i++)
		if( !listInt.isFull())
			listInt.push(i+1);
		else {
			cout << "List of integers is full." << endl;
			break;
		}
	
	cout << endl << "Print list of integers using show() method of Stack (to check):" << endl;
	listInt.show();
	
	cout << endl << "Print list of integers using peak() and pop() method of Stack:" << endl;
	while(!listInt.isEmpty()){
		cout << listInt.peek() << ' ';
		listInt.pop();
	}
	cout << endl;
}

void testStackDouble()
{
	Stack<double> listDouble(10);
	
	// Push data to Integer stack
	for(int i=0; i<11; i++)
		if( !listDouble.isFull())
			listDouble.push(i+ 0.12 + 0.123*i);
		else {
			cout << "List of doubles is full." << endl;
			break;
		}
	
	cout << endl << "Print list of doubles using show() method of Stack (to check):" << endl;
	listDouble.show();
	
	cout << endl << "Print list of doubles using peak() and pop() method of Stack:" << endl;
	while(!listDouble.isEmpty()){
		cout << setprecision(3) << listDouble.peek() << '\t';
		listDouble.pop();
	}
	cout << endl;
}

void readData(const string &filename, Stack<Student> &listSV)
{
	ifstream readFile(filename.c_str());	// to read data file

	if(readFile)
	{
		cout << "Open " << filename << " file successfull to read." << endl;
		string line(""), fullname("");
		int mssv(0), lineNum(0);
		float cpa(0.0);

		while(getline(readFile, line))	// read whole file by line
		{
			++lineNum;
			if(line == "")
				cout << "Empty line: " << lineNum << endl;
			else if( !listSV.isFull()){
				istringstream iss(line);
				auto &res1 = getline(iss, fullname, ';');
//				iss.ignore();	// not need
				auto &res2 = iss >> mssv;
				iss.ignore();	// ignore ';' character
				auto &res3 = iss >> cpa;
				if(res1 && res2 && res3 && 0<=cpa && cpa<=10)	// ensure all fields is valid
					listSV.push(Student(fullname, mssv, cpa));
				else
					cout << "Input number line: " << lineNum << " is not valid." << endl;
			} else {
				cout << "List is full. Line number: " << lineNum << endl;
				break;
			}
		}
	} 
	else
	{
		cout << "Could not open " << filename << " file to read." << endl;
	}	
	readFile.close();
}
