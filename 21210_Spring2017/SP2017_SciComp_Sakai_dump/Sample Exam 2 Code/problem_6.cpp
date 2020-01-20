#include <iostream>
#include <vector>

using namespace std;

double real_inner_product(const vector<double> &x, const vector<double> &y);

int main(){

	// Replace these with your own vectors of the same size to calculate their inner product
	vector<double> x = {1.0, -3.0, 4.0, 5.0, 2.0};
	vector<double> y = {0.0, 2.0, 3.0, -4.0, 1.0};

	cout << endl << endl;
	cout << "The inner product of x and y is: " << real_inner_product(x, y) << endl << endl;

	return 0;
}


// Solution begins here.
// This gives the real inner product of the vectors x and y.
// There is a different definition for inner products for vectors of complex numbers
double real_inner_product(const vector<double> &x, const vector<double> &y){
	
	// Keep a running total
	double total = 0.0;
	for (int i = 0; i < x.size(); i++){
		total += x[i] * y[i];
	}
	
	return total;
}
