#include <iostream>

using namespace std;

int main() {
	// Use constant expressions for values that will not change that are known at compile time.
	// The values are built directly into the compiled code, for greater efficiency.
	constexpr double pi = 3.14159265;

	
	// If you uncomment the following line, the program will not compile:
	// pi = 2.718281828459;
	
	double radius;
	
	cout << "Enter the radius of a circle: ";
	cin >> radius;
	
	// const can be used for values that will not change after initialization, but might not
	// be known at compile time because they might depend on user input or file i/o, etc.
	const double area = pi * radius * radius;

	cout << "The area of the circle is " << area << endl;

	
	// If you uncomment the following line, the program will not compile:
	// area = .5 * area;
	// cout << "The area of the half-circle is: " << area;
	
	return 0;
}
