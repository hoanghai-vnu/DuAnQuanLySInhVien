#include "Point.h"
using namespace std;

Point::Point(): m_x(0.0), m_y(0.0) 
{}
Point::Point(int x, int y): m_x(x), m_y(y) 
{}
Point::Point(Point const& other): m_x(other.m_x), m_y(other.m_y) 
{}

Point& Point::operator=(Point const& other)
{
	m_x = other.m_x;
	m_y = other.m_y;
}

Point::~Point()
{}

string Point::info() const
{
	ostringstream os;
	os << fixed << setprecision(PRECISION);
	os << "(" << m_x << ", " << m_y << ")";
	return os.str();
}
// =============================================================================
double distance(Point const& a, Point const& b)
{
	return sqrt(pow(a.m_x - b.m_x, 2) + pow(a.m_y - b.m_y, 2));
}

double dotProduct(Point const& a, Point const& b)
{
	return (a.m_x * b.m_x + a.m_y * b.m_y);
}

