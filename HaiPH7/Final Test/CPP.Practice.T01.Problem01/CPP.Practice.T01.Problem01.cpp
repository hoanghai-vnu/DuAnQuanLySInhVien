#include <iostream>
#include <cmath>
using namespace std;

// Bởi vì tính khoảng cách có làm tròn, nên không dùng so sánh bằng với khoảng cách trực tiếp được
// a - b  < epsilon thì coi như a == b
#define epsilon 0.00001 	

void typeOfTriangle(float threePofloatsCoordinates[]);
void input_data(float &x){
	while( !(cin >> x && x >= 0) ){
		cout << "Please enter a non-negative float number: ";
		cin.clear();	// Xóa error flag
		cin.ignore(100, '\n'); // bỏ 100 ký tự tiếp theo hoặc đến ký tự xuống dòng
	}
}

class Pofloat
{
	float mx;
	float my;
public:
	Pofloat(): mx(0), my(0) 
	{}
	Pofloat(float x, float y): mx(x), my(y) 
	{}
	
	friend double distance(Pofloat const& A, Pofloat const& B){
		return sqrt( pow(A.mx - B.mx, 2) + pow(A.my - B.my, 2) );
	}
};

class Triangle
{
	Pofloat A, B, C;
	double a, b, c;
public:
	Triangle(): A(), B(), C() { a = b = c = 0;}
	Triangle(float x1, float y1, float x2, float y2, float x3, float y3):
		A(x1, y1), B(x2, y2), C(x3, y3) 
	{
		a = distance (B, C); // Cạnh a = BC đối diện đỉnh A
		b = distance (A, C);
		c = distance (A, B);
	}
	
	bool isTri(){
		// Là tam giác khi tổng 2 cạnh bất kỳ lớn hơn cạnh còn lại
		return (a+b - c > epsilon && b+c - a > epsilon && c+a - b > epsilon);
	}
	
	// Tam giác vuông theo định lý Pitago
	bool isRightTri(){
		double a2 = a*a, b2 = b*b, c2 = c*c;
		return ( abs(a2 + b2 - c2) < epsilon || abs(b2 + c2 - a2)  < epsilon || abs(c2 + a2 - b2)  < epsilon);
	}
	
	// Tam giác cân khi có 1 cặp cạnh bằng nhau
	bool isIsoTri(){
		return (abs(a - b) < epsilon || abs(b - c) < epsilon || abs(c - a) < epsilon);
	}
	
	// Tam giác vuông cân khi vừa vuông vừa cân.
	bool isRight_IsoTri(){
		return ( isRightTri() && isIsoTri() );
	}
	
	// Tam giác đều khi cả 3 cạnh bằng nhau
	bool isEquilTri(){
		return (abs(a - b) < epsilon && abs(b - c) < epsilon);
	}
};

int main()
{
	cout << "Input:" << endl;
	cout << "Enter the coordinates of three points: " << endl;
	float coordinates[6] {};
	for(int i=0; i<3; i++){
		cout << "Point " << i+1 << ":\n";
		cout << "\t The 1st coordinate: ";
		input_data(coordinates[2*i]);
		cout << "\t The 2nd coordinate: ";
		input_data(coordinates[2*i+1]);
	}
	cout << "Output:" << endl;
	typeOfTriangle(coordinates);
	
	return 0;
}

void typeOfTriangle(float c[])
{
	Triangle tri(c[0], c[1], c[2], c[3], c[4], c[5]);
	if( !tri.isTri() ){
		cout << "\tNot a Triangle" << endl;
	} else if ( tri.isEquilTri() ){
		cout << "\tEquilateral Triangle" << endl;
	} else if ( tri.isRight_IsoTri() ){
		cout << "\tRight-Isosceles Triangle" << endl;
	} else if ( tri.isRightTri() ){
		cout << "\tRight Triangle" << endl;
	} else if ( tri.isIsoTri() ){
		cout << "\tIsosceles Triange" << endl;
	} else {
		cout << "\tNormal Triangle" << endl;
	} 
}
