// This file contains two solutions for Problem 7.
// The second builds everything into one function, 
// and the second requires two additional functions that it will call.
// 
// If you want to write additional functions on the exam that your functions can call,
// that is fine by me.


#include <iostream>
#include <vector>

using namespace std;


double max_min_diff_v_1(const vector<double> &x);
double max_min_diff_v_2(const vector<double> &x);


double get_max(const vector<double> &x);
double get_min(const vector<double> &x);


int main(){

	vector<double> test_vec = {3.0, 12.0, 5.0, 8.0, 6.0, 2.0, -2.0, 4.0};

	cout << endl << endl << "The test vector contains: " << endl;
	for (double elem : test_vec){
		cout << elem << endl;
	}

	// You can replace max_min_diff_v_1 by max_min_diff_v_2 in the following line to run the other function
	cout << endl << endl << "The difference between the max and the min is: " << max_min_diff_v_1(test_vec) << endl << endl;

	return 0;

}

// Solution begins here
double max_min_diff_v_1(const vector<double> &x){
	
	// Technique: keep track of a running max and a running min
	double max_found = x[0];
	double min_found = x[0];

	for (int i = 1; i < x.size(); i++){
		if( x[i] > max_found){
			max_found = x[i];
		}
		if( x[i] < min_found){
			min_found = x[i];
		}
	}
	
	return max_found - min_found;
}

// Alternate solution using additional functions begins here
double max_min_diff_v_2(const vector<double> &x){
	return get_max(x) - get_min(x);
}

double get_max(const vector<double> &x){

	double max_found = x[0];

	for (int i = 1; i < x.size(); i++){
		if (x[i] > max_found){
			max_found = x[i];
		}
	}
	
	return max_found;
}


double get_min(const vector<double> &x){

	double min_found = x[0];

	for (int i = 1; i < x.size(); i++){
		if (x[i] < min_found){
			min_found = x[i];
		}
	}
	
	return min_found;
}
