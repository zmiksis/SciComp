// We can use double indirection by having a pointer to a pointer.
// This can be useful for ragged arrays (different number of columns in each row), 
// and may be needed for using certain libraries not included with C++,
// but I would try to avoid using pointers to pointers unless you have a compelling reason

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double x = 12.5;

	double* user_double_pointer = &x;
	
	double** pointer_to_double_pointer = &user_double_pointer;
	
	cout << endl;
	cout << "x holds the value " << x << " and its address is " << &x << endl << endl;
	cout << "user_double_pointer points to the value " << *user_double_pointer << " and holds the address " << user_double_pointer 
				<< " and its own address is " << &user_double_pointer << endl << endl;
	cout << "pointer_to_double_pointer points to the value " << *pointer_to_double_pointer << " and holds the address " << pointer_to_double_pointer << endl << endl;

	cout << "pointer_to_double_pointer points to a pointer which points to the value: " << **pointer_to_double_pointer << endl;

	return 0;
}
