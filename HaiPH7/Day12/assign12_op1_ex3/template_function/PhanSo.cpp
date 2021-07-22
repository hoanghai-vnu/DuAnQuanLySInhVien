#include "PhanSo.h"

PhanSo::PhanSo(double num, double den): m_num(num), m_den(den) 
{}

PhanSo operator+(const PhanSo &a, const PhanSo &b)
{
	PhanSo res;
	res.m_num = a.m_num * b.m_den + b.m_num * a.m_den;
	res.m_den = a.m_den * b.m_den;
	return res;
}

PhanSo operator*(const PhanSo &a, const PhanSo &b)
{
	PhanSo res;
	res.m_num = a.m_num * b.m_num;
	res.m_den = a.m_den * b.m_den;
	return res;
}

std::ostream& operator<<(std::ostream &out, const PhanSo &ps)
{
	out << ps.m_num << "/" << ps.m_den;
	return out;
}

