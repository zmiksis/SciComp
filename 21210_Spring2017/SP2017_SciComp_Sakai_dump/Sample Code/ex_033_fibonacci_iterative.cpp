// This program computes the approximate nth Fibonacci number using an iterative approach.
// It does not save a complete list of previous Fibonacci numbers.
// (We will see how to save the previous ones in the near future.

#include <iostream>

using namespace std;

double fibonacci_iterative(int n);

int main(){
	int n = 100;
	cout << "The " << n << "th Fibonacci number is approximately: " << fibonacci_iterative(n) << endl;
	return 0;
}

double fibonacci_iterative(int n){
	if (n == 1 || n == 2){
		return 1;
	} else {
		double f_n_minus_two = 1.0;
		double f_n_minus_one = 1.0;
		double f_n;
		for(int i = 3; i <= n; i++){
			f_n = f_n_minus_two + f_n_minus_one;
			f_n_minus_two = f_n_minus_one;
			f_n_minus_one = f_n;
		}

		return f_n;
	}
}


