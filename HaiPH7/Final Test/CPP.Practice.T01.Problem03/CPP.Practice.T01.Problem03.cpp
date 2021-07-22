#include <iostream>
using namespace std;

bool friendNumber(int a, int b);	// Check two positive integers are friend or not
void input_integer(int &x){
	while( !(cin >> x && 1 <= x && x <= 10000) ){
		cout << "=> Please enter a positive integer (1-10000): ";
		cin.clear();	// Xóa error flag
		cin.ignore(100, '\n'); // bỏ 100 ký tự tiếp theo hoặc đến ký tự xuống dòng
	}
}

int main()
{
	int a=0, b=0;
	
	cout << "Enter two postive integers (1-10000):" << endl;
	cout << "a = "; 
	input_integer(a);
	cout << "b = "; 
	input_integer(b);
	
	if( friendNumber(a,b) )
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
	return 0;
}

bool friendNumber(int a, int b)
{
	int sum1=0;	// sum of divisors of a
	int sum2=0; // sum of divisors of a
	
	for(int i=1; i <= a/2; i++)
		if(0 == a % i)
			sum1 += i;
	if(sum1 != b)	// Nếu không thỏa mãn thì kết thúc ngay
		return false;

	// Tiếp tục check
	for(int i=1; i <= b/2; i++)
		if(0 == b % i)
			sum2 += i;
	if(sum2 == a)
		return true;
}
