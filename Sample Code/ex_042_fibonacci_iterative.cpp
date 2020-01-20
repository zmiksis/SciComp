// This program computes the approximate nth Fibonacci number using an iterative approach.
// It does not save a complete list of previous Fibonacci numbers.
// (We will see how to save the previous ones in the near future.)
// There are faster ways for calculating Fibonacci numbers based on more clever
// techniques than just computing them in sequence, which you might see in other courses.


#include <iostream>

using namespace std;

double fibonacci_iterative(int n);

int main(){
	int n;
	
	cout << "Enter a positive integer: ";
	cin >> n;

	cout << "The " << n << "th Fibonacci number is approximately: " << fibonacci_iterative(n) << endl;
	return 0;
}

double fibonacci_iterative(int n){
	if (n == 1 || n == 2){
		return 1.0;
	} else {
		// Start by defining the initial two terms
		double f_i_minus_two = 1.0;
		double f_i_minus_one = 1.0;

		// f_i will store the ith term at the completion of the loop with index i
		double f_i;

		// Iterate until the desired (nth) term
		for(int i = 3; i <= n; i++){
			// Set the ith term to be the sum of the previous two terms
			f_i = f_i_minus_two + f_i_minus_one;

			// The next two assignments prepare for the next iteration.
			f_i_minus_two = f_i_minus_one;
			f_i_minus_one = f_i;
		}

		return f_i;
	}
}
