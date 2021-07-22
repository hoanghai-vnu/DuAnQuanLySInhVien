#include <iostream>
#include <cmath>
#include <ctime>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

void input_integer(int &x)
{
	while(!(cin >> x))
	{
		cout << "Error: Please enter an integer number: ";
		cin.clear();
		cin.ignore(100, '\n');
	}
}

void isPrime(int n);
void findPrime(int a, int b);
void serial(int a, int b);
void serial2(int a, int b);
void multi_thread(int a, int b, int n);
	
int main()
{
	int a(0), b(0), n(0);
	do{
		cout << "Enter 3 number a, b, n greater than 1:" << endl;
		cout << "a = "; input_integer(a);
		cout << "b = "; input_integer(b);
		cout << "n = "; input_integer(n);
	} while (!(a>1 && b>1 && n>1));
	
	serial(a, b);
//	serial2(a, b);
//	multi_thread(a, b, n);

    return 0;
}

void serial(int a, int b)
{
	cout << "Begin calculate serial... " << endl;
	clock_t begin = clock(); // record start time
	findPrime(a, b);	
	clock_t end = clock(); // record end time
	cout << "\nDone serial." << endl;
	cout << "\nTime run serial: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
}

void serial2(int a, int b)
{
	cout << "Begin calculate serial2... " << endl;
	clock_t begin = clock(); // record start time
	for(int number = a; number <= b; number++)
		isPrime(number);
	clock_t end = clock(); // record end time
	cout << "\nDone serial2." << endl;
	cout << "\nTime run serial: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
}

void multi_thread(int a, int b, int n)
{
	thread t[n];
	cout << "Begin calculate multi-thread... " << endl;
	clock_t begin = clock(); // record start time
	int interval = (b - a + 1) / n;
	int beginLast = a + (n-1) * interval;
	for(int i=0; i<n-1; i++){	
		t[i] = thread(&findPrime, a + i * interval, a + (i+1) * interval - 1); 
	}
	for(int i=0; i<n-1; i++)
		t[i].join();
	// khoảng cuối cùng kéo dài đến b;
		t[(n-1)] = thread(&findPrime, beginLast, b); 
		t[(n-1)].join();
	clock_t end = clock(); // record end time
	cout << "\nDone multi-thread." << endl;
	cout << "\nTime run multi-thread: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
}

void isPrime(int n)
{
	if(n<2) 
		return;
	else{
		if(n % 2 == 0)
			return;
        for (int i = 3; i <= sqrt(n); i += 2)
            if (n % i == 0)
                return;
    }
	cout << n << '\n';
}

void findPrime(int a, int b)
{
	bool next;	// for continue out for
	for(int n = a; n <= b; n++){
		next = false;
		if(n % 2 == 0)
			continue;
        for (int i = 3; i <= sqrt(n); i += 2)
            if (n % i == 0){
                next = true;
                break;
            }
       	if(next) continue;
		cout << n << '\n';
	}
}
