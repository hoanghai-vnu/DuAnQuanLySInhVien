#include "ShapeFactory.h"
using namespace std;

Shape* ShapeFactory::createShape(int type, const string &s)
{
	Shape *shape;
	
	switch(type)
	{
		case 0:
			shape = new Triangle();
			if(!shape->fromString(s))	// if fail to create Triangle, return NULL pointer
			{
				delete shape;
				shape = NULL;	
			}
			break;
		case 1:
			shape = new Rectangle();
			if(!shape->fromString(s))	// if fail to create Rectangle, return NULL pointer
			{
				delete shape;
				shape = NULL;	
			}
			break;
		case 2:
			shape = new Circle();
			if(!shape->fromString(s))	// if fail to create Circle, return NULL pointer
			{
				delete shape;
				shape = NULL;	
			}
			break;
		case 3:
			shape = new Ellipse();		
			if(!shape->fromString(s))	// if fail to create Ellipse, return NULL pointer
			{
				delete shape;
				shape = NULL;	
			}
			break;
		default:		// if type is not valid, return NULL pointer
			cout << "Input type: " << type << " is not valid." << endl;
			shape = NULL;	
			break;
	}
	
	return shape;
}

list<Shape*> ShapeFactory::readShapesFromFile(const string &filename)
{
	list<Shape*> listShapes;
	ifstream readFile(filename.c_str());
	if(readFile)
	{
		int type = -1;
		string line(""), inputString("");

		while(getline(readFile, line))	// read whole file by line
		{
			stringstream ss;
			if(line != "")
				ss << line;
			else{	// if line is empty
				listShapes.push_back(NULL);
				continue;
			}
			ss >> type;
			getline(ss, inputString);
			listShapes.push_back(createShape(type, inputString));
		}
	} 
	else
	{
		cout << "Could not open " << filename << " file to read." << endl;
	}	
	readFile.close();
	
	return listShapes;
}

void ShapeFactory::saveShapesToFile(const string &filename, const list<Shape*> &shapes)
{
	ofstream writeFile(filename.c_str());
	
	if(writeFile)
	{
		for (auto it = shapes.begin(); it != shapes.end(); ++it)
		{
			if(*it)
			{
				writeFile << left << setw(35) << (*it)->toString();
				writeFile << "\tArea: " << (*it)->getArea();
				writeFile << "\tPerimeter: " << (*it)->getPerimeter() << endl;
			}
			else
				writeFile << "Not in form of any Shapes" << endl;
		}
	} 
	else
	{
		cout << "Could not open/create " << filename << " file to write." << endl;
	}
	writeFile.close();
}

void ShapeFactory::introduction()
{
	cout << "This is a Shape Factory, the input data file is formatted as following, be careful:" << endl;
	cout << "\t(Note: After removing the first integer (type), we get the format to form the shapes)" << endl;
	cout << "---------------------------------" << endl;
	cout << left << setw(16) << "0 3 4 5 3 22 11 " << " -> 0 is type Triangle, (3,4) (5,3) (22,11) is 3 vertices." << endl;
	cout << left << setw(16) << "1 3 4 10 20 " << " -> 1 is type Rectangle, (3,4) is center, 10 is width, 20 is height." << endl;
	cout << left << setw(16) << "2 3 4 15 " << " -> 2 is type Circle, (3,4) is center, 15 is radius." << endl;
	cout << left << setw(16) << "3 3 4 22 33 " << " -> 3 is type Ellipse, (3,4) is center, (22,33) are radius (rx,ry)." << endl;
	cout << left << setw(16) << "---------------------------------" << endl;
	cout << "If there is any defect during production, it will be shown below:" << endl;
	cout << "\t(Note: In the result file, that defect is shown as: Not in form of any Shapes)" << endl << endl;
}
