#ifndef DEF_SHAPE
#define DEF_SHAPE

class Shape
{
public:	
	virtual double getPerimeter() = 0;
	virtual double getArea() = 0;
	virtual bool fromString(const std::string &s) = 0;
	virtual std::string toString() const = 0;
	
	virtual ~Shape() = default;
};

#endif // DEF_SHAPE
