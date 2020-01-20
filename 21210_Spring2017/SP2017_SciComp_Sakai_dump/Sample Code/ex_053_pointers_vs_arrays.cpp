// Introduction to pointers and arrays

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double user_double_array[6] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
	
	double x = .5772;	
	double y = 1.6449;
	
	double* user_double_ptr = nullptr;



	user_double_ptr = &x;
	// First, user_double_ptr points to the address of the variable x
	cout << endl << "The value pointed to by user_double_ptr is originally: " << *user_double_ptr << endl;

	// Now, let's reassign user_double_ptr to point to the beginning of the array user_double_array
	user_double_ptr = user_double_array;
	
	cout << endl << "We have now made user_double_ptr point to the start of user_double_array." << endl;
	// We can now use the [] operator to print out the values at an offset of i from the address of user_double_ptr
	for(int i = 0; i < 6; i++){
		cout << "The value at an offset of " << i << " from the address user_double_ptr points to is: " << user_double_ptr[i] << endl;
	}
	cout << endl;	
	
	// Now, change the pointer to point to y
	user_double_ptr = &y;
	
	// We can even use the [] operator when the pointer to points to a single value, with an offset of 0 to access that value
	cout << "We have now changed user_double_ptr to point to y.\nIt now points to the value: " << user_double_ptr[0] << endl;
	cout << endl;


	// Arrays and pointers behave similarly with indexing
	// The key difference is that you can reassign a pointer, 
	// but you cannot reassign an array.
	// If you uncomment the following lines of code, your compiler will complain
	
	// user_double_array = &y;

	return 0;
}
