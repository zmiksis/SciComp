#include <iostream>

using namespace std;

int main() {
	
	int a = 65;
	
	// Promotes the value of a to be a double. Promotion does not (generally) lose information,
	// although it can with large integers.
	double f = a;
	
	// Downcasting, can be dangerous, although this time is not
	char c = a;

	cout << "a == " << a << endl;
	cout << "f == " << f << endl;
	cout << "c == " << c << endl;

	cout << endl << endl;
	cout << "Changing the value of a" << endl << endl;
	
	a = 1000001;
	// Downcasting a again, this time we lose information (characters are too small to hold the full value of a)
	c = a;
	cout << "a == " << a << endl;
	cout << "c == " << c << endl;
	
	// promote c back to an int, with the original value lost
	a = c;
	cout << "a == " << a << endl;

	

	return 0;
}
