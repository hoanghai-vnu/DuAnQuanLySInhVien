#include "InheritedShape.h"
using namespace std;

// =============================================================================
// Triangle

Triangle::Triangle(): m_p1(), m_p2(), m_p3() 
{}

double Triangle::getPerimeter()
{
	return distance(m_p1, m_p2) + distance(m_p2, m_p3) + distance(m_p3, m_p1);
}

double Triangle::getArea()
{
	double x1 = m_p1.getX(), x2 = m_p2.getX(), x3 = m_p3.getX();
	double y1 = m_p1.getY(), y2 = m_p2.getY(), y3 = m_p3.getY();
	// Nếu 3 điểm thẳng hàng thì diện tích tam giác sẽ bằng 0
	return 0.5 * abs( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
}

// Form: "3 4 5 3 22 11" -> (3,4) (5,3) (22,11) là 3 đỉnh của Triangle
bool Triangle::fromString(const string &s)
{
	double x1, y1, x2, y2, x3, y3;
	stringstream ss;
	ss << s;
	if(ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)	// only if all successfull
	{
		m_p1 = Point(x1, y1);
		m_p2 = Point(x2, y2);
		m_p3 = Point(x3, y3);
		return true;
	}
	else
	{
		cout << "Input: \"" << s << "\" is not valid to form a Triangle." << endl;
		return false;
	}
}

// Form: 0 3 4 5 3 22 11 -> 0 là type Triangle, (3,4) (5,3) (22,11) là 3 đỉnh
string Triangle::toString() const 
{
	ostringstream os;
	os << fixed << setprecision(PRECISION);
	os << 0 << " ";
	os << m_p1.getX() << " " << m_p1.getY() << " ";
	os << m_p2.getX() << " " << m_p2.getY() << " ";
	os << m_p3.getX() << " " << m_p3.getY();
	
	return os.str();
}

bool Triangle::isTriangle()
{
	double a = distance(m_p2, m_p3);
	double b = distance(m_p3, m_p1);
	double c = distance(m_p1, m_p2);
	
	return (a+b > c && b+c > a && c+a > b);
}

Triangle::~Triangle()
{}

// =============================================================================
// Rectangle

Rectangle::Rectangle(): m_center(), m_width(0.0), m_height(0.0)
{}

double Rectangle::getPerimeter()
{
	return 2 * (m_width + m_height);
}

double Rectangle::getArea()
{
	return m_width * m_height;
}

// Form: 3 4 10 20 -> (3,4) là tâm, 10 là width, 20 là height của Rectangle
bool Rectangle::fromString(const std::string &s)
{
	double x, y, width, height;
	stringstream ss;
	ss << s;
	if(ss >> x >> y >> width >> height)		// only if all successfull
	{
		m_center = Point(x, y);	
		m_width = width;
		m_height = height;
		return true;
	}
	else
	{
		cout << "Input: \"" << s << "\" is not valid to form a Rectangle" << endl;
		return false;
	}
}

// Form: 1 3 4 10 20 -> 1 là type Rectangle, (3,4) là tâm, 10 là width, 20 là height
std::string Rectangle::toString() const 
{
	ostringstream os;
	os << fixed << setprecision(PRECISION);
	os << 1 << " ";
	os << m_center.getX() << " " << m_center.getY() << " ";
	os << m_width << " " << m_height;
	
	return os.str();
}

Rectangle::~Rectangle()
{}

// =============================================================================
// Circle

Circle::Circle(): m_center(), m_radius(0.0)
{}

double Circle::getPerimeter()
{
	return 2 * PI * m_radius;
}

double Circle::getArea()
{
	return PI * m_radius * m_radius;
}

// Form: 3 4 15 -> (3,4) là tâm, 15 là bán kính của Circle
bool Circle::fromString(const std::string &s)
{
	double x, y, radius;
	stringstream ss;
	ss << s;
	if(ss >> x >> y >> radius)			// only if all successfull
	{
		m_center = Point(x, y);	
		m_radius = radius;
		return true;
	}
	else
	{
		cout << "Input: \"" << s << "\" is not valid to form a Circle" << endl;
		return false;
	}
}

// Form: 2 3 4 15 -> 2 là type Circle, (3,4) là tâm, 15 là bán kính
std::string Circle::toString() const 
{
	ostringstream os;
	os << fixed << setprecision(PRECISION);
	os << 2 << " ";
	os << m_center.getX() << " " << m_center.getY() << " " << m_radius;
	
	return os.str();
}

Circle::~Circle()
{}

// =============================================================================
// Ellipse

Ellipse::Ellipse(): m_center(), m_rx(0.0), m_ry(0.0)
{}

double Ellipse::getPerimeter()	// calculate by ellipse perimeter approx fomulla
{
	return PI * ( 3*(m_rx + m_ry) - sqrt((3*m_rx + m_ry) * (m_rx + 3*m_ry)) );	
}

double Ellipse::getArea()
{
	return PI * m_rx * m_ry;
}

// Form: 3 4 22 33 -> (3,4) là tâm, (22,33) là bán kính (rx,ry) của Ellipse
bool Ellipse::fromString(const std::string &s)
{
	double x, y, rx, ry;
	stringstream ss;
	ss << s;
	if(ss >> x >> y >> rx >> ry)
	{
		m_center = Point(x, y);	
		m_rx = rx;
		m_ry = ry;
		return true;
	}
	else
	{
		cout << "Input: \"" << s << "\" is not valid to form a Ellipse." << endl;
		return false;
	}
}

// Form: 3 3 4 22 33 -> 3 là type Ellipse, (3,4) là tâm, (22,33) là bán kính (rx,ry)
std::string Ellipse::toString() const 
{
	ostringstream os;
	os << fixed << setprecision(PRECISION);
	os << 3 << " ";
	os << m_center.getX() << " " << m_center.getY() << " ";
	os << m_rx << " " << m_ry;
	
	return os.str();
}

Ellipse::~Ellipse()
{}


