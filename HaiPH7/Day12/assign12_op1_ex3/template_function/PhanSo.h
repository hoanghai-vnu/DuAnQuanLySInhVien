#include <iostream>

class PhanSo
{
	double m_num;
	double m_den;
public:
	PhanSo(double num = 0, double den = 1);
	friend PhanSo operator+(const PhanSo &a, const PhanSo &b);
	friend PhanSo operator*(const PhanSo &a, const PhanSo &b);
	friend std::ostream& operator<<(std::ostream &out, const PhanSo &ps);
};
