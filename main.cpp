#include <iostream>
#include <cmath>

using namespace std;

class Point {

private:
	double x;
	double y;

public:

	Point(double xIn, double yIn) { //creates point (x,y)
		x = xIn;
		y = yIn;
	}

	double get_x() const {
		return x;
	}

	double get_y() const {
		return y;
	}

	//distance
	double operator-(Point p2) {  //this points to p1 
		double d = sqrt(pow((p2.x) - (this->x), 2) + pow((p2.y) - (this->y), 2));
		return d;
}
	//equal?
	int operator==(Point p2) {
		if ((this->x == p2.x) && (this->y == p2.y)) {
			return 1;
		}
		return 0;
	}
	//not equal
	int operator!=(Point p2) {
		if ((this->x != p2.x) || (this->y != p2.y)) {
			return 1;
		}
		return 0;
	}
	//midpoint
	Point operator/(Point p2) {
		return Point((this->x + p2.x) / 2, (this->y + p2.y) / 2);
	}
	//increment x
	Point operator++() {
		x++;
		return *this;
	}
	//increment y
	Point operator++(int) {
		Point num = *this;
		++y;
		return num;
	}

	//decrement x
	Point operator--() {
		x--;
		return *this;
	}
	//decrement y
	Point operator--(int) { //differentiate using "int"
		Point num = *this;
		--y;
		return num;
	}
	//access
	double operator[] (int i) {
		if (i == 0) {
			return x;
		}
		else if (i == 1) {
			return y;
		}
		return 0;
	}

	//point from input
	friend istream& operator>>(istream& in, Point& p);
};

istream& operator>>(istream& in, Point& p) {
	in >> p.x >> p.y;
	return in;
}

ostream& operator<<(ostream& out, const Point& p) {
	out << "(" << p.get_x() << "," << p.get_y() << ")"; 
	return out;
}


int main() {

	Point p1 = Point(3, 7);
	Point p2 = Point(2, 4);

	cout << "Point 1: " << p1 << endl;
	cout << "Point 2: " << p2 << endl;

	cout << "Distance between points is: " << p1 - p2 << endl;

	cout << "Are they the same? (1 if true, 0 if false) " << (p1 == p2) << endl;

	cout << "Are they different? " << (p1 != p2) << endl;

	cout << "The midpoint is: " << p1 / p2 << endl;

	++p1; //prefix to increment x
	cout << "Point 1 is now: " << p1 << endl;

	p2++; //postfix to increment y
	cout << "Point 2 is now: " << p2 << endl;

	--p1; //prefix to decrement x
	cout << "Point 1 is now: " << p1 << endl;

	p2--; //postfix to decrement y
	cout << "Point 2 is now: " << p2 << endl;

	cout << "Point 1's x value is: " << p1[0] << endl;
	cout << "Point 1's y value is: " << p1[1] << endl;

	cout << "Point 2's x value is: " << p2[0] << endl;
	cout << "Point 2's y value is: " << p2[1] << endl;

	//take in a point 
	Point p3(0,0);
	cout << "Enter a point (in form: x y): ";
	cin >> p3;
	cout << "Point 3: " << p3 << endl;
}