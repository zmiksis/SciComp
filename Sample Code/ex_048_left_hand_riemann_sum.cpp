#include <iostream>
#include <cmath>

using namespace std;

// Make sure to declare f
double f(double x);

int main(){
	
	// Endpoints for the intervals
	double a;
	double b;

	// number of subintervals
	int n;

	// Keep a running total, initialize to 0.0
	double sum = 0.0;


	cout << "Please enter a lower bound for the interval: ";
	cin >> a;
	cout << "Please enter an upper bound for the interval: ";
	cin >> b;

	cout << "Please enter the number of subintervals: ";
	cin >> n;

	double delta_x = (b - a)/n;

	// Iterate over the terms in the Riemann sum from 0 to n-1 inclusive
	for(int i = 0; i < n; i++){
		// x_i = a + i * delta_x
		sum += f( a + i * delta_x );
	}

	sum *= delta_x;

	cout << "The Riemann sum for f over the interval [" << a << ", " << b << "] with "
				<< n << " subintervals is approximately " << sum << endl;


	return 0;
}


double f(double x){
	return exp(x) - 1.0;
}
