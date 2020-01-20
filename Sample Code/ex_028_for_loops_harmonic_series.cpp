// Compute the sum of the first N terms of the harmonic series using a for loop.
// It might actually be better for the purpose of accuracy to sum this series in the reverse order
// (starting with small terms first). We will discuss why later in the course.
#include <iostream>

// Use iomanip library to gain access to setprecision, which allows you to control the
// number of digits displayed
#include <iomanip>

using namespace std;

int main() {
	
	constexpr long long int N = 1000000000;

	
	// Use a variable to keep track of a running total
	double total = 0.0;	

	for(int k = 1; k <= N; k++){
		// Must use 1.0/k to avoid an easy to overlook problem
		total += 1.0/k;
	}
	
	// Use setprecision to control the number of digits displayed
	cout << setprecision(12) << "The sum of the first " << N << " terms of the harmonic series is " << total << endl;

	return 0;
}
