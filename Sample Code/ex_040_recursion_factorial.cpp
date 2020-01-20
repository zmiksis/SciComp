// This program calls two functions evaluating approximate factorials.
// One of the functions is recursive, and the other is iterative.
// In C++, generally (though not always), if it is possible to rewrite a function
// using iteration in place of recursion, then one should do so.
// However, in some other languages, recursion may be preferred.
// Mathematics and computer science use recursion frequently.

#include <iostream>

using namespace std;

double approximate_factorial_recursive(int n);
double approximate_factorial_iterative(int n);
double approximate_factorial_while_loop(int n);

int main(){

	int n = 0;
	cout << "Enter an integer: ";
	cin >> n;

	cout << "Computed by recursion, the approximate factorial of " 
				<< n << " is " << approximate_factorial_recursive(n) << endl;
	cout << "Computed by iteration (with a for loop), the approximate factorial of " 
				<< n << " is " << approximate_factorial_iterative(n) << endl;
	cout << "Computed by iteration (with a while loop), the approximate factorial of " 
				<< n << " is " << approximate_factorial_while_loop(n) << endl;
	
	return 0;
}

double approximate_factorial_recursive(int n){
	// 1 is a base case for recursion
	// If you have no base case, the recursion will eventually fail with an error indicating that
	// the maximum stack size has been exceeded.
	if (n == 1 || n == 0){
		return 1.0;
	} else {
		return n * approximate_factorial_recursive(n - 1);
	}
}

double approximate_factorial_iterative(int n){
	double product = 1.0;
	for (int i = 1; i <= n; i++){
		product *= i;
	}
	return product;
}

// This function uses a while loop instead of a for loop,
// but it essentially duplicates the behavior of the function
// approximate_factorial_iterative above.
double approximate_factorial_while_loop(int n){
	double product = 1.0;
	int i = 1;
	while (i <= n){
		product *= i;
		i++;
	}
	return product;
}
