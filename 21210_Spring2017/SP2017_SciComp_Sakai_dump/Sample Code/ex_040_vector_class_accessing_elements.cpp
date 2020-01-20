#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void print_double_vec(const vector<double> &a, bool print_newline = true);

int main(){

	// Let's create a vector of doubles with a specified size of N;
	// The entries are default initialized to 0

	int N = 5;

	vector<double> my_double_vec(N);
	
	cout << endl << "The contents of my_double_vec after initialization are: " << endl;
	print_double_vec(my_double_vec);
	cout << endl;

	// Let's change the first three elements.
	// Indexing in C++ (and most programming languages) starts at 0,
	// so the indices of the first three elements are 0, 1, and 2.

	my_double_vec[0] = acos(-1.0);
	my_double_vec[1] = exp(1.0);
	my_double_vec[2] = sqrt(2.0);


	cout << "The contents of my_double_vec after assigning to the first three indices are: " << endl;
	print_double_vec(my_double_vec);
	cout << endl;

	// Now let's fill in the last two	

	my_double_vec[3] = (1.0 + sqrt(5.0))/2.0;
	my_double_vec[4] = log(2.0);

	cout << "After assigning to the last two elements, the contents of my_double_vec are: " << endl;
	print_double_vec(my_double_vec);
	cout << endl;

	// You will get a run time error if you uncomment 
	// the statement following, which tries to assign beyond the last element of my_double_vec: 
	// my_double_vec[N] = 2.1;

	// You may get unexpected behavior if you uncomment the following line:
	// cout << "An element beyond the last is " << my_double_vec[N] << endl;

	
	// You can also remove the last element of a vector:
	my_double_vec.pop_back();
	cout << "After removing the last element, my_double_vec is now: " << endl;
	print_double_vec(my_double_vec);
	cout << endl;
	cout << "The size of my_double_vec is now " << my_double_vec.size() << endl << endl;	

	return 0;
}

// This function takes a vector<double> and a boolean, and prints the vector (optionally with a newline afterwards)
void print_double_vec(const vector<double> &a, bool print_newline){

	// Don't print anything if the vector has size 0
	if (a.size() == 0){
		return;
	}

	// This loop iterates through all the elements except the last, and accesses and prints the element
	// and a comma.
	for (int i = 0; i < a.size() - 1; i++){
		cout << a[i] << ", ";
	}
	
	// Print the last element without a comma
	cout << a[a.size() - 1];
	
	// Optionally print a newline
	if (print_newline) {
		cout << endl;
	}

	return;	
}
