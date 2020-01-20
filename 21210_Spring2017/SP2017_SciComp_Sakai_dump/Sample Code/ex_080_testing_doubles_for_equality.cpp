// It is dangerous to test doubles for equality using ==
// Usually instead it is preferable to test that the difference 
// of the doubles is within some prespecified tolerance, and treat any two doubles within that tolerance as equal.

// The exact nature of this check will probably depend on your application

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double sqrt_two = sqrt(2.0);
	
	cout << endl << endl;
	cout << "Testing the square of sqrt_two for equality with 2.0 using == check: " << endl;

	if (sqrt_two * sqrt_two == 2.0){
		cout << "Success! sqrt_two * sqrt_two is exactly 2.0" << endl;
	} else {
		cout << "Failure! sqrt_two * sqrt_two is not exactly 2.0" << endl;
	}

	cout << "The difference between the square of sqrt_two and 2.0 is: " << sqrt_two * sqrt_two - 2.0 << endl;

	cout << endl << endl;

	cout << "Using a tolerance based check: " << endl;

	double tolerance = 1.0e-8;	

	if ( abs(sqrt_two * sqrt_two - 2.0)  < tolerance) {
		cout << "Success! The values of sqrt_two * sqrt_two and 2.0 are (close enough to) equal." << endl;
	} else {
		cout << "Failure! The values of sqrt_two * sqrt_two and 2.0 are not (close enough to) equal." << endl;
	}

	cout << endl;

	return 0;
}
