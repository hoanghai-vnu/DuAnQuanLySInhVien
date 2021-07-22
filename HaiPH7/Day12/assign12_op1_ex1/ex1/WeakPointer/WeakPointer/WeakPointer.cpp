#include<iostream>
#include <memory>

using namespace std;

//WeakPointer.h
template <typename T>
class WeakPointer
{
private:
	T* m_pointer;
	T** m_alive;

public:
	WeakPointer();
	explicit WeakPointer(T* sp);
	~WeakPointer();
	void operator =(const WeakPointer& sp);
	T& operator*();
};

//WeakPointer.cpp
#define NULL 0

template<typename T>
T& WeakPointer<T>::operator*()
{
	return *m_pointer;
}


template<typename T>
WeakPointer<T>::WeakPointer()
{
}

template<typename T>
WeakPointer<T>::WeakPointer(T* sp)
{
	m_pointer = sp;
	m_alive = &m_pointer;
}

template<typename T>
WeakPointer<T>::~WeakPointer()
{
	if (*m_alive != NULL)
	{
		delete m_pointer;
		m_pointer = NULL;
	}
}

template<typename T>
void WeakPointer<T>::operator=(const WeakPointer& sp)
{
	m_pointer = m_pointer;
	m_alive = sp.m_alive;
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
	cout << "defaul weak_ptr\n\n";
	{
		weak_ptr<test> e0;
		{
			shared_ptr<test> st(new test());
			e0 = st;
			cout << "chuan bi xoa\n";
		}
		cout << "xoa xong\n";
	}
	cout << "\n\nMy Weak Pointer\n\n";
	{
		WeakPointer<test> e0;
		{
			WeakPointer<test> st(new test());
			e0 = st;
			cout << "chuan bi xoa\n";
		}
		cout << "xoa xong\n";
	}

	cout << "\nhello";

}