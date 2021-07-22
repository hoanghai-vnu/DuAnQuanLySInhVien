#ifndef DEF_SHARED_PTR
#define DEF_SHARED_PTR
#include <iostream>
using namespace std;

template <class T>
class Shared_Ptr {
    T* m_ptr;		// Shallow copy to shared between Shared_Ptr pointers
    int *m_refs;	// Reference count - shallow copy to shared between Shared_Ptr pointers
    int m_ins;		// Count number of real object INStances, Which is owner? (value = 1)
public:
    // Constructor
    explicit Shared_Ptr(T* p = NULL): m_ptr(p), m_refs(NULL), m_ins(0) { 
		cout << "Shared Pointer Constructor" << endl;
    	if(p != NULL){
    		m_refs = new int(1);
    		++m_ins;
    	}
	}	
		
    // Destructor
    ~Shared_Ptr() { 
		cout << "Shared Pointer Destructor" << endl;
    	if( *m_refs > 0){
			--(*m_refs);
			if(*m_refs == 0){
				cout << "The last hit" << endl;
				delete m_refs;
				delete m_ptr; 
			}
		}
    }
    
    Shared_Ptr(Shared_Ptr &other): m_ptr(other.m_ptr), m_refs(other.m_refs), m_ins(0){
    	(*m_refs)++;
    	
    	if(other.m_ins == 1){
			m_ins = 1;
			other.m_ins = 0;
		}
    }
    
    Shared_Ptr& operator=(Shared_Ptr &other) {
    	if(this == &other)
    		return *this;
    		
    	m_refs = other.m_refs;
    	(*m_refs)++;
    	
    	if(m_ptr != other.m_ptr){
    		m_ins = 0;
			delete m_ptr;    	
			m_ptr = other.m_ptr;
    	}
    	
    	if(other.m_ins == 1){
			m_ins = 1;
			other.m_ins = 0;
		} else 
			m_ins = 0;
    	
    	return *this;
    }
    
    int use_Count() const { return *m_refs; }
    int ins_Count() const { return m_ins; }
  
    // Overloading dereferncing operator
    T& operator*() { return *m_ptr; }
  
    // Overloading arrow operator useful if T represents
    // a class or struct or union type
    T* operator->() { return m_ptr; }
};

#endif // DEF_SHARED_PTR
