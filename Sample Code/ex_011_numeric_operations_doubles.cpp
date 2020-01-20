#include <iostream>

using namespace std;

int main() {
	
	double pi = 3.141592653589793;
	double e  = 2.718281828459045;

	cout << "pi == " << pi << endl;
	cout << "e  == " << e  << endl;
	cout << "pi + e == " << pi + e << endl;
	cout << "pi * e == " << pi * e << endl;
	cout << "pi / e == " << pi / e << endl;
	// Mod is not defined for doubles.
	// If you uncomment the following line, the program will not compile:
	// cout << "pi % e == " << pi % e << endl;

	return 0;
}
