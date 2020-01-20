#include <iostream>

using namespace std;

int main()
{
	
	int a = 100;
	
	// promotes the value of a to be a double. Promotion does not (generally) lose information,
	// although it might with large integers.
	double f = a;
	
	// Downcasting, can be dangerous
	char c = a;

	cout << "a == " << a << endl;
	cout << "f == " << f << endl;
	cout << "c == " << c << endl;

	a = 1000000;
	c = a;
	cout << "a == " << a << endl;
	cout << "c == " << c << endl;
	
	// promote c back to an int, with the original value lost
	a = c;
	cout << "a == " << a << endl;

	

	return 0;
}
