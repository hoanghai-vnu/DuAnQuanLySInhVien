#include <iostream>
#include <fstream>
#include <sstream>
#include "Queue.h"
#include "Student.h"
using namespace std;

void readData(const string &filename, Queue &listSV);
void task2(Queue &listSV);

int main()
{
	// Task 1
	Queue listSV(10);
	string filename("data.txt");
	
	readData(filename, listSV);
	
	// Task 2
//	task2(listSV);

	// Task 3+4
	// Xóa 5 sinh viên từ queue listSV
	listSV.pop(5);
	
	// Tạo queue mới để có thể chứa 15 sinh viên.
	Queue newListSV(15);
	if(newListSV.getMax() > listSV.getSize())
		newListSV.copy(listSV);		// copy data

	
	// Thêm 10 sinh vào queue mới từ file data2.txt
	filename = "data2.txt";
	readData(filename, newListSV);
	
	cout << endl << "Print list of students using peak() and pop() method of Queue:" << endl;
	Student::print_header();
	while(!newListSV.isEmpty()){
		newListSV.peek().print_row();
		newListSV.pop();
	}

    return 0;
}

void task2(Queue &listSV)
{
	cout << endl << "Print list of students using show() method of Queue (to check):" << endl;
	listSV.show();
	
	cout << endl << "Print list of students using peak() and pop() method of Queue:" << endl;
	Student::print_header();
	while( !listSV.isEmpty()){
		listSV.peek().print_row();
		listSV.pop();
	}
}

void readData(const string &filename, Queue &listSV)
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
