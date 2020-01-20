// Introduction to pointers

#include <iostream>


using namespace std;

int main(){

	// If you do not initialize these variables, their values are not guaranteed.
	// Try this example without initilizing and see what happens on your compiler.
	int a = 4;
	int b = 10;

	// Use the keyword nullptr for a pointer that does not point to anything
	int* user_int_ptr = nullptr;


	cout << "The value of a is: " << a << endl;
	cout << "The value of b is: " << b << endl;


	cout << "user_int_ptr points to the address: " << user_int_ptr << endl;

	// Now, we will make user_int_ptr point to a using the address of operator &
	
	user_int_ptr = &a;
		
	cout << endl << endl << "Now, user_int_ptr points to a:" << endl;
	cout << "The address of a is: " << &a << endl;
	cout << "The address of b is: " << &b << endl;
	cout << "user_int_ptr points to " << user_int_ptr << endl;


	// Now, make user_int_ptr point to b

	user_int_ptr = &b;

	cout << endl << endl << "Now, user_int_ptr points to b" << endl;
	cout << "The address of a is: " << &a << endl;
	cout << "The address of b is: " << &b << endl;
	cout << "user_int_ptr points to " << user_int_ptr << endl;

	return 0;
}
