// The solution to this problem is just the function, defined near the bottom of the file

#include <iostream>

// Needed for pow
#include <cmath>

using namespace std;


double calculate_S(int m, int n);

int main()
{
	
	int m;
	int n;

	cout << "Please enter a value for m: ";
	cin >> m;
	cout << "Please enter a value for n: ";
	cin >> n;
	
	if (n < m){
		cout << "Make certain that m <= n." << endl;
		return 0;
	}

	cout << "The value of S(" << m << ", " << n << ") is: " << calculate_S(m, n) << endl;	

	return 0;
}

// Solution begins here
double calculate_S(int m, int n){
	double total = 0.0;
	// Must use <= in order to include the upper bounds in the summation
	for (int i = m; i <= n; i++){
		for (int j = i; j<= n; j++){
			// I have used the pow function to make certain the RHS is computed as a double
			// so that there is no integer division
			total += pow(i, 2.0)/j;
		}
	}
	return total;
}
	
