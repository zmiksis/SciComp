#include <iostream>

using namespace std;

int main()
{

	// We can initialize the value of b to depend on the value of a
	// Note that the result of integer division is still an integer
	int a = 3;
	int b = a/2;
	cout << "The value of a is " << a << " and the value of b is " << b << endl;
	
	// Reassigning a now does NOT change b
	a = 5;
	cout << "The value of a is now " << a << " and the value of b is still " << b << endl;	
	
	return 0;
}
