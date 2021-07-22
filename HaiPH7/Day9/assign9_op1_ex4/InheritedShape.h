#ifndef DEF_INHERITEDSHAPE
#define DEF_INHERITEDSHAPE
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include "Point.h"
#include "Shape.h"

#define PI 3.1416
#define PRECISION 2		// precision when print coordinates

class Triangle: public Shape
{
	Point m_p1;
	Point m_p2;
	Point m_p3;
public:	
	Triangle();
	// Có thể không cần từ khóa virtual
	virtual double getPerimeter();
	virtual double getArea();
	virtual bool fromString(const std::string &s);
	virtual std::string toString() const ;
	
	bool isTriangle();
	virtual ~Triangle();
};

// =============================================================================

class Rectangle: public Shape
{
	Point m_center;
	double m_width;
	double m_height;
public:
	Rectangle();
	// Có thể không cần từ khóa virtual
	virtual double getPerimeter();
	virtual double getArea();
	virtual bool fromString(const std::string &s);
	virtual std::string toString() const ;

	virtual ~Rectangle();
};

// =============================================================================

class Circle: public Shape
{
	Point m_center;
	double m_radius;
public:
	Circle();
	// Có thể không cần từ khóa virtual
	virtual double getPerimeter();
	virtual double getArea();
	virtual bool fromString(const std::string &s);
	virtual std::string toString() const ;
	
	virtual ~Circle();
};

// =============================================================================

class Ellipse: public Shape
{
	Point m_center;
	double m_rx;
	double m_ry;
public:
	Ellipse();
	// Có thể không cần từ khóa virtual
	virtual double getPerimeter();
	virtual double getArea();
	virtual bool fromString(const std::string &s);
	virtual std::string toString() const ;
	
	virtual ~Ellipse();
};

#endif // DEF_INHERITEDSHAPE
