// This program builds a vector of Fibonacci numbers, using the fact that we know how many
// that we would like to compute and store in advance.

// We then use the Fibonacci numbers to approximate the golden ratio.
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// In this version of the program, we do not need to specify the length of
// the vector of Fibonacci numbers, because we can use the fact that
// a vector knows its own length, and we want to 
void build_fibonacci(vector<double> &fibonacci_numbers);
void print_fibonacci(const vector<double> &fibonacci_numbers);
void print_approximations_to_golden_ratio(const vector<double> &fibonacci_numbers);

int main(){
	
	int N;

	cout << setprecision(16);

	cout << "How many Fibonacci numbers would you like to calculate? ";
	cin >> N;
	
	// Use doubles for approximate Fibonacci numbers, which grow large quickly.
	// We specify how many Fibonacci numbers that we would like to compute here in advance
	// so that there is no chance of the vector needing to allocate more memory afterwards.
	vector<double> fibonacci_numbers(N);

	build_fibonacci(fibonacci_numbers);

	print_fibonacci(fibonacci_numbers);
	
	print_approximations_to_golden_ratio(fibonacci_numbers);

	return 0;
}

void build_fibonacci(vector<double> &fibonacci_numbers){
	
	if (fibonacci_numbers.size() == 0){
		return;
	}	

	fibonacci_numbers[0] = 1.0;

	

	if (fibonacci_numbers.size() < 2){
		return;
	}

	fibonacci_numbers[1] = 1.0;

	// In this implementation, we just write into the ith slot, and do not have to add
	// to the end of the vector.
	for (int i = 2; i < fibonacci_numbers.size(); i++){
		fibonacci_numbers[i] = fibonacci_numbers[i-2] + fibonacci_numbers[i-1];
	}
	
	return;
}	

// Use a constant reference because we are not changing the values
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
		cout << "The approximation to the golden ratio using f_" << i << "/f_" << (i - 1) << " is " <<
							fibonacci_numbers[i]/fibonacci_numbers[i-1] << endl;
	}
	return;
}

