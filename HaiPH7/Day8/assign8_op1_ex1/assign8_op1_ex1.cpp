#include <iostream>
#include "String.h"
using namespace std;

void testBlock1();

int main()
{
	cout << "============> Begining the program" << endl;

	cout << "\nTest input/output and length of String" << endl;
	String s1;
	cout << "Enter a String s1: ";
	cin >> s1;
	cout << "\ts1 = " << s1 << endl;
	cout << "\tlength(s1) = " << s1.size() << endl;
	
	cout << "\nTest add, reverse and erase String" << endl;
	String s2;
	cout << "\tEnter a String s2 to add to s1: ";
	cin >> s2;
	// add
	cout << "\ts1 + " " + s2 = " << s1 + " " + s2 << endl;
	// reverse 
	s1.reverse();
	cout << "\tRevert string of s1: " << s1 << endl;
	// erase
	s1.erase();
	cout << "\ts1 after is ereased: " << s1 << ", ";
	cout << "\tlength(s1) = " << s1.size() << endl;
	cout << "\ts1 + " " + s2 = " << s1 + " " + s2 << endl;
	
	cout << "\nTest comparison" << endl;
	String str1("ABCd"), str2("ABCD"), str3("ABCD F"), str4("a"), str5("ABCXYZ");
	if(str2 == str2) cout << "\t\"" << str2 << "\" = \"" << str2 << "\"\n";
	if(str1 != str2) cout << "\t\"" << str1 << "\" != \"" << str2 << "\"\n";
	if(str2 != str3) cout << "\t\"" << str2 << "\" != \"" << str3 << "\"\n";
	if(str3 < str5) cout << "\t\"" << str3 << "\" < \"" << str5 << "\"\n";
	if(str4 > str5) cout << "\t\"" << str4 << "\" > \"" << str5 << "\"\n";
	
	cout << "\n============> At the end of program" << endl;
	
    return 0;
}

void testBlock1()
{
	cout << "Test default, parameterized, copy constructor and assignment operator" << endl;
	String s;
	cout << "\ts1 = " << s << ",";
	cout << "\tlength(s) = " << s.size() << endl;
	
	String s2("Nguyen Van Tuan");
	cout << "\ts2 = " << s2 << ",";
	cout << "\tlength(s2) = " << s2.size() << endl;
	
	String s3(s2);
	cout << "\ts3 = " << s3 << ",";
	cout << "\tlength(s3) = " << s3.size() << endl;
	
	String s4("haha");
	cout << "\ts4 = " << s4 << ",";
	cout << "\tlength(s4) = " << s4.size() << endl;
	
	String s5 = "12345";
	cout << "\ts5 = " << s5 << ",";
	cout << "\tlength(s5) = " << s5.size() << endl;
}
