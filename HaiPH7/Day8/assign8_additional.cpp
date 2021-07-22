#include<iostream>
using namespace std;

class Killer{
	int *m_YOB;		// year of birth
	string m_addr;	// address
public:
	Killer(): m_YOB(new int(0)), m_addr("") 
	{}
	Killer(int yob, string addr): m_YOB(new int(yob)), m_addr(addr)
	{}
	
	void setYOB(int year){
		*m_YOB = year;
	}
	
	void setAddr(string addr){
		m_addr = addr;
	}
	void info(int now) const{
		cout << "Address: " << m_addr << "," << "\tTuoi: " << (now - *m_YOB);
	}
};

void task1(Killer const& real, Killer const* copies)
{
	int n=0;
	bool check = false;
	do{
		cout << "Enter the year you want to know info about Killer (2001~2007): ";
		cin >> n;
		if(2001>n || n>2007){
			cout << "==> The year you just entered not satisfied. Please re-enter:" << endl;
			check = true;
		} else
			check = false;
	}while(check);
	cout << "Killernd83: "; real.info(n); cout << endl;
	cout << "Killernd2k: "; copies[n-2001].info(n); cout << endl;
}

int main()
{
	string addr[7] = {"Hà Nội", "Thanh Hóa", "Đà Nẵng", "Vinh", "Huế", "Tp.Hồ Chí Minh", "Phú Quốc"};
	Killer Copies[7]; // mảng info theo năm của bản sao Killer

	Killer Killernd83(1983, "Nam Định");
	for(int i=0; i<7; i++){
		Copies[i] = Killernd83;
		Copies[i].setAddr(addr[i]);
	}
	
	// task 1
	cout << "Task 1:" << endl;
	task1(Killernd83, Copies);

	// task 2	
	cout << "\nTask 2:" << endl;
	int correctYear = 0;
	cout << "Enter the correct year of birth: ";
	cin >> correctYear;
	
	Killernd83.setYOB(correctYear);
	task1(Killernd83, Copies);
	
	
    return 0;
}
