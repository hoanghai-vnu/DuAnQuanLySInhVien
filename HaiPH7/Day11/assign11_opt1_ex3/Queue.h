#ifndef DEF_QUEUE
#define DEF_QUEUE
#include <cassert>
#include <iostream>
#include <iomanip>
#include "Student.h"

template <class T>
class Queue		// FIFO
{
private:
	int m_max;
	int m_size;
	T *m_queue;	
public:	
	Queue(): m_max(0), m_size(0), m_queue(nullptr) {}
	Queue(int max): m_max(max), m_size(0), m_queue(new T[max]) {}
	~Queue(){
		delete[] m_queue;
	}
	
	void push(const T& student){
		assert(m_size < m_max);
		m_queue[m_size] = student;
		++m_size;
	}
	
	void pop(){
		assert(m_size > 0);
		for(int i=0; i<m_size-1; i++)
			m_queue[i] = m_queue[i+1];
		--m_size;
	}
	
	void pop(int number){
		assert(m_size >= number);
		for(int i=0; i<m_size-number; i++)
			m_queue[i] = m_queue[i+number];
		m_size -= number;
	}
	
	T& peek(){
		return m_queue[0];
	}
	
	bool isEmpty(){
		return (m_size == 0);
	}
	
	bool isFull(){
		return (m_size == m_max);
	}
	
	int getMax() const{
		return m_max;
	}
	
	int getSize() const{
		return m_size;
	}
	
	void copy(const Queue &other){
		assert(m_max >= other.m_size);
		for(int i=0; i<other.m_size; i++)
			m_queue[i] = other.m_queue[i];
			m_size = other.m_size;
	}
	
	void show(){
		for(int i=0; i<m_max; i++)
			cout << m_queue[i] << ' ';
		cout << '\n';
	}
};

// function template specialization for Student object
template<>
void Queue<Student>::show(){
	Student::print_header();
	for(int i=0; i<m_max; i++)
		m_queue[i].print_row();
}

// function template specialization for print double number
template<>
void Queue<double>::show(){
	for(int i=0; i<m_max; i++)
		cout << setprecision(3) << m_queue[i] << '\t';
	cout << '\n';
}


#endif // DEF_QUEUE
