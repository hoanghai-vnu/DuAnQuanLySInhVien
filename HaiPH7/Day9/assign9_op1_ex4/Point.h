#ifndef DEF_POINT
#define DEF_POINT
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

#define PRECISION 2		// precision when print coordinates

class Point
{
protected:
	double m_x;	// Tọa độ x
	double m_y; // Tọa độ y
public:	
	Point();
	Point(int x, int y);
	Point(Point const& other);
	Point& operator=(Point const& other);
	~Point();
	
	double getX() const { return m_x;};
	void setX(double x) { m_x = x;};
	double getY() const { return m_y;};
	void setY(double y) { m_y = y;};
	
	std::string info() const;
	
	// Mr. Dinh Quang Trung (GAM.VN.IVI) bỏ qua nạp chồng toán tử
	
	friend double distance(Point const& a, Point const& b);
	friend double dotProduct(Point const& a, Point const& b);
};

#endif // DEF_POINT
