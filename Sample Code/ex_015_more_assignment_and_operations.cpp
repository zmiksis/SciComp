#include <iostream>

using namespace std;

int main() {
	double x = 5.0;
	double y = 2.0;
	
	
	cout << "The value of x is " << x << " and the value of y is " << y << endl;

	// Increase x by the value of y
	x += y;

	cout << "The new value of x is " << x << " and the value of y is still " << y << endl;

	// The right hand side is evaluated before the assignment is performed
	x = 3*x + 6;
	
	cout << "The new value of x is " << x << endl;
	
	return 0;
}
