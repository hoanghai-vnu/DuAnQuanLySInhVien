#ifndef DEF_MATRAN
#define DEF_MATRAN
#include <iostream>

class MaTran
{
	int m_nRows;
	int m_nCols;
	float **m_matrix;
public:	
	MaTran();
	MaTran(int n, int m);
	MaTran(int n, int m, int number);
	MaTran(MaTran const& other);
	MaTran& operator=(MaTran const& other);
	~MaTran();
	
	void input();
	void output() const;
	
	MaTran& operator*(int k);	// Only A*k
	friend MaTran operator+(MaTran const& a, MaTran const& b);
	friend MaTran operator-(MaTran const& a, MaTran const& b);
	friend MaTran operator*(MaTran const& a, MaTran const& b);
	friend MaTran operator/(MaTran const& a, MaTran const& b);
	
	MaTran& LL_transf();
	MaTran& RU_transf();
};

#endif // MATRAN
