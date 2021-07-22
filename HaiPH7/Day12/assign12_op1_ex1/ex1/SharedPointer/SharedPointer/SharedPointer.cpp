#include<iostream>
#include <memory>

using namespace std;

//SharedPointer.h
template <typename T>
class SharedPointer
{
private:
	int* m_count;
	T* m_pointer;

public:
	SharedPointer();
	explicit SharedPointer(T* sp);
	~SharedPointer();
	void operator =(const SharedPointer& sp);
	T& operator*();
};

//SharedPointer.cpp
#define NULL 0

// overloading dereferencing operator
template<typename T>
T& SharedPointer<T>::operator*()
{
	return *m_pointer;
}


template<typename T>
SharedPointer<T>::SharedPointer()
{
}

template<typename T>
SharedPointer<T>::SharedPointer(T* sp)
{
	m_count = new int;
	*m_count = 1;
	m_pointer = sp;
}

template<typename T>
SharedPointer<T>::~SharedPointer()
{
	if (*m_count == 1) {
		delete m_count;
		delete m_pointer;
		m_count = NULL;
		m_pointer = NULL;
	}
	else {
		*m_count -= 1;
		this->m_count = NULL;
		this->m_pointer = NULL;
	}
}

template<typename T>
void SharedPointer<T>::operator=(const SharedPointer& sp)
{
	m_count = sp.m_count;
	m_pointer = sp.m_pointer;
	*m_count += 1;
}


class test {
public:
	test() {
		cout << "create\n";
	}
	~test() {
		cout << "delete\n";
	}
};

int main()
{
	cout << "defaul shared_ptr\n\n";
	{
		shared_ptr<test> e0;
		{
			shared_ptr<test> st(new test());
			e0 = st;
			cout << "khong lam gi\n";
		}
		cout << "chuan bi xoa\n";
	}
	cout << "\n\nMy Shared Pointer\n\n";
	{
		SharedPointer<test> e0;
		{
			SharedPointer<test> st(new test());
			e0 = st;
			cout << "khong lam gi\n";
		}
		cout << "chuan bi xoa\n";
	}

	cout << "\nhello";

}