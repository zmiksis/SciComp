// This program implements interval bisection to find the root of a CONTINUOUS function 

// The program takes several command line arguments
// The required arguments are the interval end points: a and b

// The optional argument is the width of the subinterval in which to pin the root

// If an exact root is found, the program reports the root, otherwise it reports the endpoint or midpoint that
// gives the value nearer to zero as its approximation

// In an actual application, you might want to code something like this up
// as a function that takes four arguments: a function (passed by function pointer), a, b and the width
// and returns the best approximation to the root, or throws an exception (see chapter 5) if there
// is no evidence that the interval contains a root.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x);

double within(double x, double y, double tol);

double sign(double x);

int main(int argc, char * argv[]){

	double a;
	double b;
	double width = pow(10, -10);

	if (argc < 3) {
		cout << "Please enter at least two command line arguments!" << endl;
		return 0;
	} else if (argc == 3) {
		a = stod(argv[1]);
		b = stod(argv[2]);
	} else {
		a = stod(argv[1]);
		b = stod(argv[2]);
		width = stod(argv[3]);
	}

	// Some error checking to be courteous.
	if (a >= b || width <= 0.0){
		cout << "The command line arguments that you entered were not valid!" << endl;
	}
	

	double lower = a;
	double upper = b;

	// Note that, in floating point arithmetic, it is possible for the calculated midpoint using
	// the simpler formula (a+b)/2.0 to lie outside the interval [a, b]
	// This is rare, but the formula below avoid the problem. 
	double middle = a + (b-a)/2.0;

	// Exact checks for equality are ok here since we might get a better approximation
	// that is also within the tolerance if we iterate

	// This implementation stores the values of f(lower), f(upper) and f(middle) to avoid
	// recalculating them, which could take some time if f were a complicated function	

	cout << setprecision(12);

	double f_lower = f(a);
	if (f_lower == 0.0) {
		cout << "A root occurs at " << a << "." << endl;
		return 0;
	}

	double f_upper = f(b);
	if (f_upper == 0.0) {
		cout << "A root occurs at " << b << "." << endl;
		return 0;
	}

	if (sign(f_lower) == sign(f_upper) ){
		cout << "There is not enough evidence to suggest that the interval [" << a << ", " << b << "] contains a root." << endl;
		return 0;
	}

	double f_middle = f(middle);



	while (upper - lower > width){
		
		// In an actual application, the next line would be commented out.
		cout << "Examining the interval [" << lower << ", " << upper << "]." << endl;

		if (f_middle == 0.0) {
			cout << "The root occurs at " << middle << "." << endl;
			return 0;
		}

		if (sign(f_lower) == sign(f_middle)){
			lower = middle;
			f_lower = f_middle;
		} else {
			upper = middle;
			f_upper = f_middle;
		}

		middle = lower + (upper - lower)/2.0;
		f_middle = f(middle);
	}

	// If we have reached this point, we have not found an "exact" root.
	// We should probably report whichever of lower, middle, and upper
	// yields the smallest absolute value when we apply f to it.

	cout << "The root occurs within the interval [" << lower << ", " << upper << "]." << endl;
			
	if ( abs(f_lower) <= abs(f_middle) && abs(f_lower) <= abs(f_upper)){
		cout << "The best approximation to the root is " << lower << "." << endl;
	} else if ( abs(f_middle) <= abs(f_lower) && abs(f_middle) <= abs(f_upper) ){
		cout << "The best approximation to the root is " << middle << "." << endl;
	} else {
		cout << "The best approximation to the root is " << upper << "." << endl;
	}

	return 0;
}

// Check whether x and y are within a tolerance of one another
// by examining the absolute value of their difference
double within(double x, double y, double tol){
	if (abs(x-y) < tol) {
		return true;
	} else {
		return false;
	}
}


double sign(double x){
	if (x > 0.0) {
		return 1.0;
	} else if (x < 0.0) {
		return -1.0;
	} else {
		return 0.0;
	}
}



double f(double x){
	return pow(x, 5) + x + 1;
	// return tan(x/4.0) - 1.0;
}



