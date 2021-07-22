#ifndef DEF_QUEUE
#define DEF_QUEUE
#include <cassert>
#include "Student.h"

class Queue		// FIFO
{
private:
	int m_max;
	int m_size;
	Student *m_queue;	
public:	
	Queue(): m_max(0), m_size(0), m_queue(nullptr) {}
	Queue(int max): m_max(max), m_size(0), m_queue(new Student[max]) {}
	~Queue(){
		delete[] m_queue;
	}
	
	void push(const Student& student){
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
	
	Student& peek(){
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
		Student::print_header();
		for(int i=0; i<m_max; i++)
			m_queue[i].print_row();
	}
};

#endif // DEF_QUEUE
