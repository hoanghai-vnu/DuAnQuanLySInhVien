#include "DouLinkedList.h"
using namespace std;

DouLinkedList::~DouLinkedList()
{
	Node *index = m_head;
    while(index != NULL)
    {
        delete index->data;
        Node *temp = index->next;
        delete index;
        index = temp;
    }
}
//------------------------------------------------------------------------------
void DouLinkedList::add_head(Student* student)
{
	Node *newElement = new Node;
    newElement->data = student;
    newElement->prev = NULL;
    newElement->next = NULL;
    
    Node *temp = m_head;
    if(m_head == NULL)
    {
        m_head = newElement;
        m_tail = newElement;
    }
    else
    {
        newElement->next = temp;
        temp->prev = newElement;
        m_head = newElement;
    }
}

void DouLinkedList::add_tail(Student* student)
{
	Node *newElement = new Node;
    newElement->data = student;
    newElement->prev = NULL;
    newElement->next = NULL;
    
    Node *temp = m_tail;
    if(m_tail == NULL)
    {
        m_head = newElement;
        m_tail = newElement;
    }
    else
    {
        temp->next = newElement;
        newElement->prev = temp;
        m_tail = newElement;
    }
}

void DouLinkedList::add_tail(Student const& student)
{
	Node *newElement = new Node;
    newElement->data = new Student(student);
    newElement->prev = NULL;
    newElement->next = NULL;
    
    Node *temp = m_tail;
    if(m_tail == NULL)
    {
        m_head = newElement;
        m_tail = newElement;
    }
    else
    {
        temp->next = newElement;
        newElement->prev = temp;
        m_tail = newElement;
    }
}

void DouLinkedList::add_middle(Student* student, int mssv)
{
	Node *newElement = new Node;
    newElement->data = student;
    newElement->prev = NULL;
    newElement->next = NULL;
    
    Node *temp = m_head;
    if(m_head == NULL)
    {
        m_head = newElement;
        m_tail = newElement;
    }
    else
    {
    	while(temp->next != NULL && temp->data->get_mssv() != mssv)
        {
            temp = temp->next;
        } // exit while: temp is previous or tail
        if(temp->next == NULL)	// add to tail
	   	{
	   		temp->next = newElement;
		    newElement->prev = temp;
		    m_tail = newElement;
		    return;
	   	}
	   	else	// add after previous
	   	{
		    newElement->next = temp->next;
			temp->next->prev = newElement;
		    newElement->prev = temp;
		    temp->next = newElement;
		}
    }
}
//------------------------------------------------------------------------------
void DouLinkedList::remove(int mssv)
{
	Node *temp = m_head;
    if(m_head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    // the student have MSSV equal mssv is at the begin of list
    else if (temp->data->get_mssv() == mssv) 
    {
        m_head = m_head->next;
        m_head->prev = NULL;
        delete temp->data;
        delete temp;
    }
    else // middle and end
    {
        // find the it's previous item
        while(temp->next != NULL && temp->next->data->get_mssv() != mssv)
        {
            temp = temp->next;
        } 
        if( temp->next != NULL )
        {
		    Node *needToDel = temp->next;
		    temp->next = needToDel->next;
		    if(needToDel->next == NULL)
				m_tail = temp;
		    else
				needToDel->next->prev = temp;
		    delete needToDel->data;
			delete needToDel;
		}
		else
			cout << "=> Cannot remove! Not found for mssv: " << mssv << endl;
    }
}
//------------------------------------------------------------------------------
void DouLinkedList::print_down() const
{
	Node *index = m_head;
    while(index != NULL)
    {
        index->data->print_info();
        index = index->next;
    }
}

void DouLinkedList::print_up() const
{
	Node *index = m_tail;
    while(index != NULL)
    {
        index->data->print_info();
        index = index->prev;
    }
}
//------------------------------------------------------------------------------
const Node* DouLinkedList::find_mssv(int mssv) const
{
	Node *index = m_head;
    while(index != NULL)
    {
        if(index->data->get_mssv() == mssv)
        	return index;
        index = index->next;
    }
    return NULL;
}

DouLinkedList& DouLinkedList::find_fullname(DouLinkedList const& list, std::string const& fullname)
{
	Node *index = list.m_head;
    while(index != NULL)
    {
        if(index->data->get_fullname() == fullname)
        	add_tail( *(index->data) );	// Copy data version of add_tail
        index = index->next;
    }
    return *this;
}

DouLinkedList& DouLinkedList::find_name(DouLinkedList const& list, std::string const& name)
{
	Node *index = list.m_head;
    while(index != NULL)
    {
        if(index->data->get_name() == name)
        	add_tail( *(index->data) );	// Copy data version of add_tail
        index = index->next;
    }
    return *this;
}
//------------------------------------------------------------------------------
void DouLinkedList::swap_data(Node *A, Node *B)
{
	Student *temp = A->data;
	A->data = B->data;
	B->data = temp;
}
//------------------------------------------------------------------------------
void DouLinkedList::sort_mssv()
{
	Node *index = m_head;
    while(index->next != NULL)
    {
    	Node *inner = index->next;
        while(inner != NULL)
        {
        	if( index->data->get_mssv() > inner->data->get_mssv() )
        	{
        		swap_data(index, inner);
        	}
        	inner = inner->next;
        }
        index = index->next;
    }
}

void DouLinkedList::sort_fullname()
{
	Node *index = m_head;
    while(index->next != NULL)
    {
    	Node *inner = index->next;
        while(inner != NULL)
        {
        	if( index->data->get_fullname()  >  inner->data->get_fullname() )
        	{
        		swap_data(index, inner);
        	}
        	inner = inner->next;
        }
        index = index->next;
    }
}

void DouLinkedList::sort_name()
{
	Node *index = m_head;
    while(index->next != NULL)
    {
    	Node *inner = index->next;
        while(inner != NULL)
        {
        	if( index->data->get_name() > inner->data->get_name() )
        	{
        		swap_data(index, inner);
        	}
        	inner = inner->next;
        }
        index = index->next;
    }
}

