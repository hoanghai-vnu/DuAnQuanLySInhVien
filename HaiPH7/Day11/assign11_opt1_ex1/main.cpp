#include <iostream>
#include <fstream>
#include <sstream>
#include "Stack.h"
#include "Student.h"
using namespace std;

void readData(const string &filename, Stack &listSV);

int main()
{
	Stack listSV(10);
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
	
    return 0;
}

void readData(const string &filename, Stack &listSV)
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
