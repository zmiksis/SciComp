// This program builds a vector of Fibonacci numbers.
// The approach here is not the best (we will see a better one shortly).
// The disadvantage of this approach is that we repeatedly resize the vector
// that stores the Fibonacci numbers, when we actually know in advance
// how large that it should be.

// We then use the Fibonacci numbers to approximate the golden ratio.


#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


void build_fibonacci(vector<double> &fibonacci_numbers, int N);
void print_fibonacci(const vector<double> &fibonacci_numbers);
void print_approximations_to_golden_ratio(const vector<double> &fibonacci_numbers);

int main(){
	
	int N;

	cout << setprecision(16);

	cout << "How many Fibonacci numbers would you like to calculate? ";
	cin >> N;

	// Use doubles for approximate Fibonacci numbers, which grow large quickly
	vector<double> fibonacci_numbers;

	build_fibonacci(fibonacci_numbers, N);

	print_fibonacci(fibonacci_numbers);
	
	print_approximations_to_golden_ratio(fibonacci_numbers);

	return 0;
}

// Assumes the user enters a number N >= 1
void build_fibonacci(vector<double> &fibonacci_numbers, int N){
	// Clear the contents of the vector for storing the Fibonacci numbers
	// if there were any contents initially.
	fibonacci_numbers.clear();

	// Push back the first Fibonacci number
	fibonacci_numbers.push_back(1.0);
	// If the user wants only the first Fibonacci number, stop here
	if (N == 1) {
		return;
	}
	fibonacci_numbers.push_back(1.0);
	
	// Remember that indexing begins at 0, so the third element has index 2
	// and the last element has index (N-1)
	for (int i = 2; i < N; i++){
		fibonacci_numbers.push_back(fibonacci_numbers[i-2] + fibonacci_numbers[i-1]);
	}
	
	return;
}	

// Use pass by constant reference because we are not changing the values
// and want to avoid copying the vector.
void print_fibonacci(const vector<double> &fibonacci_numbers){

	// We can use the fact that a vector knows its own size.
	for (int i = 0; i < fibonacci_numbers.size(); i++){
		cout << "f_" << i << " == " << fibonacci_numbers[i] << endl;
	}

	return;
}

void print_approximations_to_golden_ratio(const vector<double> &fibonacci_numbers){
	for (int i = 1; i < fibonacci_numbers.size(); i++){
		cout << "The approximation to the golden ratio using f_" << i << "/f_" << (i - 1) << " is " <<	fibonacci_numbers[i]/fibonacci_numbers[i-1] << endl;
	}
	return;
}

