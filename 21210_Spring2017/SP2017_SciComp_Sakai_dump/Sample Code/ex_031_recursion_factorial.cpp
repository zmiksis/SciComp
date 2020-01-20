// This program calls two functions evaluating approximate factorials.
// One of the functions is recursive, and the other is iterative.
// In C++, generally (though not always), if it is possible to rewrite a function
// using iteration in place of recursion, then one should do so.
// However, in some other languages, recursion may be preferred.
// Theoretical computer science uses recursion frequently.

#include <iostream>

using namespace std;

double approximate_factorial_recursive(double n);
double approximate_factorial_iterative(double n);

int main(){

	double n = 100;

	cout << "Computed by recursion, the approximate factorial of " 
				<< n << " is " << approximate_factorial_recursive(n) << endl;
	cout << "Computed by iteration, the approximate factorial of " 
				<< n << " is " << approximate_factorial_iterative(n) << endl;
	
	return 0;
}

double approximate_factorial_recursive(double n){
	// 1.0 (and 0.0) are base cases for recursion
	// If you have no base case, the recursion will eventually fail with an error indicating that
	// the maximum stack size has been exceeded.
	if (n == 1.0 || n == 0.0){
		return 1.0;
	} else {
		return n * approximate_factorial_recursive(n - 1.0);
	}
}

double approximate_factorial_iterative(double n){
	// Can be dangerous to test inequality between ints and doubles if you do not know
	// in advance that the double is in fact an integer.
	double product = 1.0;
	for (int i = 1; i <= n; i++){
		product *= i;
	}
	return product;
}
	
