// This program computes the approximate nth Fibonacci number,
// but the algorithm is badly designed because it recomputes many values.
// There is a way to fix this by storing previously calculated values
// (a technique called memoization that we will see later),
// but it would be better to rewrite this program
// to use iteration instead of recursion.

#include <iostream>

using namespace std;

double bad_recursive_fibonacci(int n);

int main(){

	int n = 0;
	cout << "Enter a positive integer: ";
	cin >> n;

	cout << "The " << n << "th Fibonacci number is approximately: " << bad_recursive_fibonacci(n) << endl;
	return 0;
}

double bad_recursive_fibonacci(int n){
	// n == 1 or n == 2 are the base cases for recursion
	if (n == 1 || n == 2) {
		return 1.0;
	} else {
		return bad_recursive_fibonacci(n-1) + bad_recursive_fibonacci(n-2);
	}
}
