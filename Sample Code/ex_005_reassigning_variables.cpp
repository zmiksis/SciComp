#include <iostream>


// Use the following to avoid typing std:: for cout, endl, etc.
// I encourage using this for most programs in this course.
// Place this before the start of the main routine
using namespace std;

int main() {
	
	int a = 3;
	int b = 4;

	cout << "The value of a is " << a << " and the value of b is " << b << endl;
	
	// Assign new values to a and b using the assignment operator = 
	a = 2;
	b = 3;
	b = a; //b and a should now both be 2
	a = 4; //b should still be 2 and a should now be 4

	cout <<	"The value of a is now " << a << " and the value of b is now " << b << endl;
	
	return 0;
}
