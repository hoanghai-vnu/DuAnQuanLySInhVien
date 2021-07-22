#include <iostream>
#include <sstream>
using namespace std;

string Encrypt(char letter);
string stringEncryption(string s);

int main()
{
	string str("");
	int n;
	char c;
	
	cout << "Enter an positive integer N = ";
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> c;
		str += c;
	}
	
	cout << stringEncryption(str) << endl;
	
	return 0;
}

string Encrypt(char letter)
{
	int code = (int) letter;
	int last = code % 10;
	int first = code;
	while(first > 9) // exit while, remain number is the first number;
		first /= 10;
	
	stringstream ss;
	ss << char(code + last) << first << last << char(code - first);
	return ss.str();
}

string stringEncryption(string s)
{
	stringstream ss;
	
	for(int i=0; i<s.size(); i++)
	{
		ss << Encrypt(s[i]);
	}
	
	return ss.str();
}
