#ifndef DEF_STACK
#define DEF_STACK
#include <cassert>
#include "Student.h"

class Stack		// LIFO
{
private:
	int m_max;
	int m_size;
	Student *m_stack;	
public:	
	Stack(): m_max(0), m_size(0), m_stack(nullptr) {}
	Stack(int max): m_max(max), m_size(0), m_stack(new Student[max]) {}
	~Stack(){
		delete[] m_stack;
	}
	
	void push(const Student& student){
		assert(m_size < m_max);
		m_stack[m_size] = student;
		++m_size;
	}
	
	void pop(){
		assert(m_size > 0);
		--m_size;
	}
	
	Student& peek(){
		return m_stack[m_size-1];
	}
	
	bool isEmpty(){
		return (m_size == 0);
	}
	
	bool isFull(){
		return (m_size == m_max);
	}
	
	void show(){
		Student::print_header();
		for(int i=0; i<m_max; i++)
			m_stack[i].print_row();
	}
};

#endif // DEF_STACK
