// This program computes the approximate nth Fibonacci number,
// but the algorithm is badly designed.
// There is a way to fix this, but it would be better to rewrite this program
// to use iteration instead of recursion.

#include <iostream>

using namespace std;

double bad_recursive_fibonacci(int n);

int main(){
	int n = 48;
	cout << "The " << n << "th Fibonacci number is approximately: " << bad_recursive_fibonacci(n) << endl;
	return 0;
}

double bad_recursive_fibonacci(int n){
	if (n == 1 || n == 2) {
		return 1.0;
	} else {
		return bad_recursive_fibonacci(n-1) + bad_recursive_fibonacci(n-2);
	}
}
