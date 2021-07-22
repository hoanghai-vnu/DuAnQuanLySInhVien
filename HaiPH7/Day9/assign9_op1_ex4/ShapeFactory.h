#ifndef DEF_SHAPEFACTORY
#define DEF_SHAPEFACTORY
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <list>
#include "Shape.h"
#include "InheritedShape.h"

class ShapeFactory
{
public:	
	Shape* createShape(int type, const std::string &s);
	std::list<Shape*> readShapesFromFile(const std::string &filename);
	void saveShapesToFile(const std::string &filename, const std::list<Shape*> &shapes);
	
	static void introduction();
};

#endif // DEF_SHAPEFACTORY
