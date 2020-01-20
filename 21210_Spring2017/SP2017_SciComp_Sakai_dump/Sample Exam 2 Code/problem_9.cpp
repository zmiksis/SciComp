#include <iostream>
#include <vector>

using namespace std;

int total_of_not_divisible(vector<int> numbers, vector<int> possible_divisors);


int main(){

	vector<int> test_numbers = {2, 14, 30, 65, 40, 36, 39, 17, 22};
	vector<int> test_divisors = {5, 7, 11};

	int total = total_of_not_divisible(test_numbers, test_divisors);
	
	cout << endl << endl << "Among the numbers: ";
	for (int i = 0; i < test_numbers.size(); i++){
		cout << test_numbers[i] << ", ";
	}
	
	cout << endl << "the sum of the numbers not divisible by any of ";
	for (int i = 0; i < test_divisors.size() - 1; i++){
		cout << test_divisors[i] << ", ";
	}
	cout << test_divisors[test_divisors.size() - 1] << " is ";
	cout << total << endl << endl;

	return 0;
}


// Solution begins here.
// You do not have to use this approach to this problem-there are others.
// This function returns 0 if there are no numbers satisfying the criteria,
// in accordance with the empty sum convention.
int total_of_not_divisible(vector<int> numbers, vector<int> possible_divisors){

	int total = 0;	
	for(int number : numbers){
		// For each number in the list of numbers to check,
		// assume initially that the number is not divisible by any of the numbers on the list of possible divisors.
		bool is_divisible = false;

		// Loop through the list of possible divisors, and, if any divides the number you are examining,
		// mark the number as being divisible by one of the possible divisors. 
		// This part might be clearer if you write a function to take care of the details.
		for (int d : possible_divisors){
			if (number % d == 0){
				is_divisible = true;
				// If the number is divisible by one of the possible divisors, you do not need to look at the rest,
				// so you can break the loop immediately.
				break;
			}
		}
		
		// The only way the variable is_divisible is still false is if we never encountered a possible divisor of n
		if (!is_divisible){
			total += number;
		}
	}

	return total;
}
