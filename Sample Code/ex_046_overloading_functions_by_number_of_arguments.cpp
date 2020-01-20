#include <iostream>

// The cmath library contains many helpful mathematical functions
#include <cmath>

// iomanip allows us to use manipulators to set precision for displaying doubles
#include <iomanip>

using namespace std;


double euclidean_norm(double x, double y);
double euclidean_norm(double x, double y, double z);


// There is actually a function in the math library to compute the Euclidean norm of the pair (x,y)
// called hypot.
// This version is designed to avoid some potential problems with our implementation, such as the possibility
// of the squares of x and y exceeding the maximum representable double values
// even if the result of the calculation is within the range of available double values.

// Later, we will see how to write a function to compute the norm of a vector with
// any number of components using the vector class.

int main(void){

	double a = 3.0;
	double b = 4.0;
	double c = 12.0;
	
	// First, set the display style to fixed with precision 2
	cout << fixed << setprecision(2);

	cout << "The euclidean_norm of a vector with components " << a << " and " << b << " is " << euclidean_norm(a, b) << endl;
	cout << "The euclidean_norm of a vector with components " << a << ", " << b << " and " << c << " is " << euclidean_norm(a, b, c) << endl;

	return 0;
}


double euclidean_norm(double x, double y){
	return pow( pow(x, 2) + pow(y, 2), .5);
}


double euclidean_norm(double x, double y, double z){
	return pow( pow(x, 2) + pow(y, 2) + pow(z, 2) , .5);
}

