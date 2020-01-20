// We can use double indirection by having a pointer to a pointer.
// This can be useful for ragged arrays (different number of columns in each row), 
// but I would try to avoid it

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double x = 12.5;

	double* my_double_pointer = &x;
	
	double** pointer_to_double_pointer = &my_double_pointer;
	
	cout << endl;
	cout << "x holds the value " << x << " and its address is " << &x << endl << endl;
	cout << "my_double_pointer points to the value " << *my_double_pointer << " and holds the address " << my_double_pointer 
				<< " and its own address is " << & my_double_pointer << endl << endl;
	cout << "pointer_to_double_pointer points to " << *pointer_to_double_pointer << " and holds the address " << pointer_to_double_pointer << endl << endl;

	return 0;
}
