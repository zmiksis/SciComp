#include <iostream>

// The cmath library contains many helpful mathematical functions
#include <cmath>

// iomanip allows us to use manipulators to set precision for displaying doubles
#include <iomanip>

using namespace std;


double hypoteneuse(double x, double y);
double hypoteneuse(double x, double y, double z);

int main(void){

	double a = 3.0;
	double b = 4.0;
	double c = 12.0;
	
	// First, set the display style to fixed with precision 2
	cout << fixed << setprecision(2);

	cout << "The hypoteneuse of a triangle with sides " << a << " and " << b << " is " << hypoteneuse(a, b) << endl;
	cout << "The hypoteneuse of a triangle with sides " << a << ", " << b << " and " << c << " is " << hypoteneuse(a, b, c) << endl;

	return 0;
}


double hypoteneuse(double x, double y){
	return pow( pow(x, 2) + pow(y, 2), .5);
}


double hypoteneuse(double x, double y, double z){
	return pow( pow(x, 2) + pow(y, 2) + pow(z, 2) , .5);
}

