#include <iostream>

// Vector is a template container class, allowing you to store a (finite) sequence of values
#include <vector>

using namespace std;

int main(){
	// Without namespace std, you need to use std::vector<int> for the type.
	// The type of my_int_vec is vector<int>, i.e. a vector of integers.
	// vector is a template container class, so you have to specify what
	// type the vector holds in < >.
	// All elements of vector must be of the same type.

	// You can initialize a vector with some values 
	vector<int> my_int_vec = {5, 7, 2, 4};


	// A vector knows its own size.
	// size() is a member function to the vector class.
	// Note the calling syntax for a member function with . following the variable name
	cout << endl << "The size of my_int_vec is " << my_int_vec.size() << endl;


	// You can iterate over a vector using a 'range for loop'
	// This will iterate from front to back.
	// If you want to change the elements in the actual vector, use 
	// for (int &elem : my_int_vec) instead.
	
	cout << endl << "Printing the elements of my_int_vec:" << endl;
	for (int elem : my_int_vec) {
		cout << elem << endl;
	}	
	


	// You can add to the back of a vector with push_back
	// push_back is a member_function of the vector class.
	// Let's add 21 to the back of the vector.

	cout << endl << "Adding 21 to the back of my_int_vec" << endl;
	my_int_vec.push_back(21);
	cout << endl << "The size of my_int_vec is now " << my_int_vec.size() << endl;

	// Let's print out the values in the vector again
	
	cout << endl << "Printing the elements of my_int_vec again: " << endl;
	for (int elem :  my_int_vec) {
		cout << elem << endl;
	}
	
	cout << endl;

	return 0;
}
