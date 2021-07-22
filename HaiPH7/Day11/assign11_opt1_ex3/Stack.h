#ifndef DEF_STACK
#define DEF_STACK
#include <cassert>
#include <iostream>
#include <iomanip>
#include "Student.h"

template <class T>
class Stack		// LIFO
{
private:
	int m_max;
	int m_size;
	T *m_stack;	
public:	
	Stack(): m_max(0), m_size(0), m_stack(nullptr) {}
	Stack(int max): m_max(max), m_size(0), m_stack(new T[max]) {}
	~Stack(){
		delete[] m_stack;
	}
	
	void push(const T& student){
		assert(m_size < m_max);
		m_stack[m_size] = student;
		++m_size;
	}
	
	void pop(){
		assert(m_size > 0);
		--m_size;
	}
	
	T& peek(){
		return m_stack[m_size-1];
	}
	
	bool isEmpty(){
		return (m_size == 0);
	}
	
	bool isFull(){
		return (m_size == m_max);
	}
	
	void show(){
		for(int i=0; i<m_max; i++)
			cout << m_stack[i] << ' ';
		cout << '\n';
	}
	
};

// function template specialization for Student object
template<>
void Stack<Student>::show(){
	Student::print_header();
	for(int i=0; i<m_max; i++)
		m_stack[i].print_row();
}

// function template specialization for print double number
template<>
void Stack<double>::show(){
	for(int i=0; i<m_max; i++)
		cout << setprecision(3) << m_stack[i] << '\t';
	cout << '\n';
}

#endif // DEF_STACK
