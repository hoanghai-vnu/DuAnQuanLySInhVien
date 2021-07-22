#include "MaTran.h"
using namespace std;

MaTran::MaTran(): m_nRows(0), m_nCols(0), m_matrix(NULL)
{}

MaTran::MaTran(int n, int m, int number): m_nRows(n), m_nCols(m), m_matrix(NULL)
{
	// Allocate
	m_matrix = new float*[n];
	for(int i=0; i<n; i++)
		m_matrix[i] = new float[m];
	// Assign
	for(int i=0; i<m_nRows; i++)
		for(int j=0; j<m_nCols; j++)
			m_matrix[i][j] = number;
}

MaTran::MaTran(int n, int m): m_nRows(n), m_nCols(m), m_matrix(NULL)
{
	// Allocate
	m_matrix = new float*[n];
	for(int i=0; i<n; i++)
		m_matrix[i] = new float[m];
}

MaTran::MaTran(MaTran const& other): m_nRows(other.m_nRows), m_nCols(other.m_nCols), m_matrix(NULL)
{
	// Allocate
	m_matrix = new float*[m_nRows];
	for(int i=0; i<m_nRows; i++)
		m_matrix[i] = new float[m_nCols];
	// Assign
	for(int i=0; i<m_nRows; i++)
		for(int j=0; j<m_nCols; j++)
			m_matrix[i][j] = other.m_matrix[i][j];
}

MaTran& MaTran::operator=(MaTran const& other)
{
	if(this == &other)
		return *this;
	// Free old value
	for(int i=0; i<m_nRows; i++)
		delete[] m_matrix[i];
	delete[] m_matrix;
	
	// Assign
	m_nRows = other.m_nRows;
	m_nCols = other.m_nCols;
	
	m_matrix = new float*[m_nRows];
	for(int i=0; i<m_nRows; i++)
		m_matrix[i] = new float[m_nCols];
		
	for(int i=0; i<m_nRows; i++)
		for(int j=0; j<m_nCols; j++)
			m_matrix[i][j] = other.m_matrix[i][j];
	
	return *this;
}

MaTran::~MaTran()
{
	for(int i=0; i<m_nRows; i++)
		delete[] m_matrix[i];
	delete[] m_matrix;
}	

// =============================================================================

void MaTran::input()
{
	if(m_matrix != NULL)
		for(int i=0; i<m_nRows; i++){
			for(int j=0; j<m_nCols; j++){
//				cout << "Nhap a[" << i << "][" << j << "] = ";
				cin >> m_matrix[i][j];
			}
		}
}

void MaTran::output() const
{	
	if(m_matrix != NULL)
		for(int i=0; i<m_nRows; i++){
			for(int j=0; j<m_nCols; j++){
				printf("%8.2f ", m_matrix[i][j]);
			}
			cout << endl;
		}
}

// =============================================================================

MaTran& MaTran::operator*(int k)
{
	for(int i=0; i<m_nRows; i++)
		for(int j=0; j<m_nCols; j++)
			m_matrix[i][j] *= k;
	return *this;
}

MaTran operator+(MaTran const& a, MaTran const& b)
{
	if(!(a.m_nRows == b.m_nRows && a.m_nCols == b.m_nCols))
	{
//		cout << "Sorry. Two matrices of different sizes, cannot add!" << endl;
		return MaTran(1,1,0);
	} 
	else 
	{
		int n = a.m_nRows, m = a.m_nCols;
		MaTran res(n, m);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				res.m_matrix[i][j] = a.m_matrix[i][j] + b.m_matrix[i][j];
		return res;
	}
}

MaTran operator-(MaTran const& a, MaTran const& b)
{
	if(!(a.m_nRows == b.m_nRows && a.m_nCols == b.m_nCols))
	{
//		cout << "Sorry. Two matrices of different sizes, cannot sub!" << endl;
		return MaTran(1,1,0);
	} 
	else 
	{
		int n = a.m_nRows, m = a.m_nCols;
		MaTran res(n, m);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				res.m_matrix[i][j] = a.m_matrix[i][j] - b.m_matrix[i][j];
		return res;
	}
}

MaTran operator*(MaTran const& a, MaTran const& b)
{
	if(!(a.m_nCols == b.m_nRows))
	{
//		cout << "Sorry. Two matrices cannot multiple!" << endl;
		return MaTran(1,1,0);
	} 
	else 
	{
		// (n x m) * (m x p) = (n x p)
		int n = a.m_nRows, m = a.m_nCols, p = b.m_nCols;
		MaTran res(n, p);
		for(int i=0; i<n; i++)
		{
			for(int k=0; k<p; k++)
			{
				res.m_matrix[i][k] = 0;
				for(int j=0; j<m; j++)
					res.m_matrix[i][k] += a.m_matrix[i][j] * b.m_matrix[j][k];
			}
		}

		return res;
	}
}

MaTran operator/(MaTran const& a, MaTran const& b)
{
	return MaTran(1,1,0);
}

MaTran& MaTran::LL_transf()
{
	
	return *this;
}

MaTran& MaTran::RU_transf()
{
	return *this;
}
