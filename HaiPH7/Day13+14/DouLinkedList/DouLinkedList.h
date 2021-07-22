#ifndef DEF_STRING
#define DEF_STRING
#include <iostream>
#include <string>
#include "Student.h"

struct t_node
{
	Student *data;
	struct t_node *prev, *next;
};

typedef struct t_node Node;

class DouLinkedList
{
	Node *m_head;
	Node *m_tail;
public:
	DouLinkedList(): m_head(NULL), m_tail(NULL) {}
	~DouLinkedList();
	
	// method return const Node* to protect DouLinkedList from modify
	const Node* get_head() const {return m_head;}

	void add_head(Student* student);
	void add_tail(Student* student);	// directly point to input object
	
	void add_tail(Student const& student); // copy input object
	
	// Add vao sau Student co ma so sinh vien la mssv
	// Neu khong tim thay thi them vao cuoi list
	void add_middle(Student* student, int mssv);
	
	void remove(int mssv);
	
	void print_down() const;
	void print_up() const;
	
	// method return const Node* to protect DouLinkedList from modify
	const Node* find_mssv(int mssv) const;
	// Be carefull to use two following methods. Just using it for new DouLinkedList
	DouLinkedList& find_fullname(DouLinkedList const& list, std::string const& fullname);
	DouLinkedList& find_name(DouLinkedList const& list, std::string const& name);
	
	void swap_data(Node *A, Node *B);

	void sort_mssv();
	void sort_fullname();
	void sort_name();
};

#endif // DEF_STRING
