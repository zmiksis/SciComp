// Find the largest integer power of the golden ratio less than a specified bound.
// Note that it is possible (though very unlikely) that
// there could be issues with rounding error.
#include <iostream>

using namespace std;

int main()
{
	
	// The golden ratio is (1 + sqrt(5))/2
	constexpr double phi = 1.6180339887498948482;

	// phi_n is phi to the nth power
	double phi_n = 1.0;
	int n = 0;
	
	double user_bound;
	cout << "Enter the desired upper bound: ";
	cin >> user_bound;

	while (phi_n * phi < user_bound) {
		phi_n *= phi;
		n += 1;
	}

	cout << "The largest value of n such that (phi)^n < " << user_bound << " is n == " << n <<"." << endl;
	cout << "For n == " << n << ", (phi)^n == " << phi_n << "." << endl;


	return 0;
}
