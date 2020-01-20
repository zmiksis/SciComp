#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double p_norm(const vector<double> &x, double p);

int main(){


	// Modify this vector if you want another vector's p-norm
	vector<double> x = {1.0, 2.0, 3.0, 4.0};

	double p;
	cout << "Enter a value for p of at least one: ";
	cin >> p;
	if (p < 1){
		cout << "The value " << p << " is not a valid value for a vector p-norm." << endl;
		return 0;
	}

	cout << "The vector x is ( ";
	for (int i = 0; i < x.size() - 1; i++){
		cout << x[i] << ", ";
	}
	cout << x[x.size() - 1] << ")." << endl << endl;

	cout << "The " << p << "-norm of x is: " << p_norm(x, p) << endl << endl;	

	return 0;
}


// Solution begins here
double p_norm(const vector<double> &x, double p){

	// Keep a running total for the sum
	double total = 0.0;

	// You could also iterate over indices instead of using a range for loop
	for (double elem : x){
		// Add the pth power of the entry to the running total
		total += pow( abs(elem), p);
	}

	// Return the pth root of the total	

	return pow(total, 1.0/p);
}	
