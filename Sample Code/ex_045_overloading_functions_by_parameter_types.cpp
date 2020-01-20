#include <iostream>

using namespace std;

// The function simple_operation is overloaded based on what types appear as parameters.
// When the function is called, the compiler will try to find the definition that best matches the arguments passed.
// Note that you cannot overload a function based on return type alone.
int simple_operation(int a, int b);
double simple_operation(double x, double y);


int main(){

	// Note that int_res and double_res are probably bad names for variables
	// because they begin with keywords int and double and might be initially confusing to read.

	int a = 7;
	int b = 4;
	int int_res = simple_operation(a, b);

	double x = 7.0;
	double y = 4.0;
	double double_res = simple_operation(x,y);



	cout << "With ints, the result of simple_operation is " << int_res << endl;
	cout << "With doubles, the result of simple_operation is " << double_res << endl;


	// The compiler will complain about the next line being ambiguous
	// There is no simple_operation defined for parameters of type int, double
	// cout << simple_operation(7, 4.0) << endl;

	return 0;

}


int simple_operation(int a, int b){
	return a + 13/b;
}

double simple_operation(double x, double y){
	return x + 13.0/y;
}

