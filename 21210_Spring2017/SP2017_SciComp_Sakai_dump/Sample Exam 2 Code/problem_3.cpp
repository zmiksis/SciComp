#include <iostream>
#include <vector>
// Use cmath for the abs function
#include <cmath>

using namespace std;

double sum_abs_difference(const vector<double> & x, const vector<double> &y);

int main(){
	vector<double> x = {1.0, 3.0, 1.0, 7.0};
	vector<double> y = {-2.0, 4.0, 6.0, 2.0};

	cout << endl << endl << "The sum of the absolute values of the differences of corresponding components of x and y is: "
							<< sum_abs_difference(x, y) << endl << endl;

	return 0;
}

// Solution to the problem begins here
double sum_abs_difference(const vector<double> &x, const vector<double> &y){
	// Keep a running total
	double total = 0.0; 
	for (int i = 0; i < x.size(); i++){
		total += abs(x[i] - y[i]);
	}
	return total;
}
