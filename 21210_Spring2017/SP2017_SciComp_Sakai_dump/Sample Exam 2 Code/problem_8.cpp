#include <iostream>
#include <vector>

using namespace std;

double sum_pos_entries(const vector<double> &x);
double sum_pos_entries_v_2(const vector<double> &x);


int main(){

	vector<double> test_vec = {3.0, 12.0, -5.0, 8.0, 6.0, 2.0, -2.0, 4.0, -3.0, -2.0, 1.0};

	cout << endl << endl << "The test vector contains: " << endl;
	for (double elem : test_vec){
		cout << elem << endl;
	}

	// You can replace max_min_diff_v_1 by max_min_diff_v_2 in the following line to run the other function
	cout << endl << endl << "The sum of the positive entries of the test vector is: " << sum_pos_entries(test_vec) << endl << endl;

	return 0;

}

// Solution begins here. 
// This solution returns 0 if there are no positive entries 
// (0 is taken as the result of computing an empty sum by convention)
double sum_pos_entries(const vector<double> &x){
	// Keep a running total
	double total = 0.0;

	for (double elem : x){
		if (elem > 0){
			total += elem;
		}
	}
	
	return total;
}


// Alternate solution returning NaN if there are no positive entries
// NaN stands for not a number, and results from 0.0/0.0 or other calculations
// with doubles that cannot return a double.
// The solution above this one is the better one from a mathematical perspective,
// but this one might be more appropriate depending on context.
double sum_pos_entries_v_2(const vector<double> &x){
	
	// You need to keep track of whether or not there are positive entries
	int pos_count = 0;
	double total = 0.0;	
	
	for (double elem : x){
		if (elem > 0){
			pos_count += 1;
			total += elem;
		}
	}

	// If there are positive numbers, return the sum of them
	if (pos_count > 0){
		return total;
	// Otherwise, return nan
	} else {
		return nan("");
	}
}
