#include <iostream>
#include <list>
#include "ShapeFactory.h"
using namespace std;

int main()
{
	ShapeFactory::introduction();	
	
	ShapeFactory shapeFac;
	list<Shape*> shapes = shapeFac.readShapesFromFile("data_file.txt");
	shapeFac.saveShapesToFile("result_file.txt", shapes);
	
	// Free
	for (auto it = shapes.begin(); it != shapes.end(); ++it)
		delete *it;
	
    return 0;
}
