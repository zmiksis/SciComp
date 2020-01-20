#include <iostream>

using namespace std;

// The return type of example_function is 'void'
// This indicates that the function does not return a value.
void example_function(int a, int b);


int main() {
	int a = 1;
	int b = 2;
	int c = 3;


	cout << "Before calling example_function:" << endl;
	cout << "\t The value of a is: " << a << endl;
	cout << "\t The value of b is: " << b << endl;
	cout << "\t The value of c is: " << c << endl;

	// Call example_function with the values of a, b in main.
	example_function(a, b);


	cout << "After calling example_function:" << endl;
	cout << "\t The value of a is: " << a << endl;
	cout << "\t The value of b is: " << b << endl;
	cout << "\t The value of c is: " << c << endl;
	cout << "Note that the values of a, b, c in the main routine have not changed!" << endl;

	return 0;
}

// The variable names a, b, c are local to the function.
// Changes to a, b, and c in the function do not change
// the values of a, b, and c in the main routine.
void example_function(int a, int b){
	int c = 5;
	
	a = a + b;
	b = b * c;
	
	cout << "Inside the function: " << endl;
	cout << "\t The value of a is: " << a << endl;
	cout << "\t The value of b is: " << b << endl;
	cout << "\t The value of c is: " << c << endl;

	// For a function with return type void, use 'return' without a value
	return;
}

	

