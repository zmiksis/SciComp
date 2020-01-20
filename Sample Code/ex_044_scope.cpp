#include <iostream>

using namespace std;

int main(){

	// The scope of a variable is determined by the innermost block of code (separated off by { } )
 	// in which the variable is defined.
	//
	// When the end of the block is reached, any variable defined in that scope is destroyed and
	// the memory allotted to the variable itself is returned to the operating system.
	//
	// (However, if the variable points to dynamically allocated memory, discussed later, this might
	// not be freed automatically, potentially causing a memory leak!)

	{
		// a is valid inside this block
		int a = 3;
		cout << "Inside this scope, the value of a is: " << a << endl;
	}

	// If I uncomment the following line, the program will not compile because the variable a will have
	// gone out of scope.
	
	// cout << "Trying to refer to a outside of the scope in which it was defined. The value of a is: " << a << endl;



	// Additionally, names in inner scopes can mask names in outer scopes.
	int x = 2;
	cout << "In the outer scope, the value of x is: " << x << endl;
	{
		int x = 5;
		// Using x in the inner scope refers to the variable x of the same name defined in the inner scope
		cout << "In the inner scope, the value of the inner scope x is: " << x << endl;
		// The inner scope x goes out of scope after the next line
	}
	cout << "Returning to the outerscope, the value of the outer scope x is: " << x << endl;

	// It is probably best not to use two variables of the same name in different scopes
	// inside of the same function, because it can be very confusing trying to read code that
	// does this if you are not reading line by line carefully.
	
	return 0;
}
