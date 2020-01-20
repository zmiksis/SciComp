// Introduction to pointers

#include <iostream>


using namespace std;

int main(){

	int a = 4;
	
	// Initialize user_int_ptr to point to a
	int* user_int_ptr = &a;	

	cout << endl;
	cout << "The address of a is: " << &a << endl;
	cout << "user_int_ptr points to: " << user_int_ptr << endl;
	cout << "The value of a is: " << a << endl;

	// Now, let's use the dereference operator * in order to use the value that user_int_ptr points to
	
	cout << "The value pointed to by user_int_ptr is: " << *user_int_ptr << endl;

	cout << endl << endl;

	cout << "Changing the value of a using the dereference operator." << endl;
		
	// We can assign to the object to which a pointer points using the dereference operator as well
	*user_int_ptr = 27;
	cout << "The address of a is: " << &a << endl;
	cout << "user_int_ptr points to: " << user_int_ptr << endl;
	cout << "The value of a is: " << a << endl;
	cout << "The value pointed to by user_int_ptr is: " << *user_int_ptr << endl << endl;

	return 0;
}
