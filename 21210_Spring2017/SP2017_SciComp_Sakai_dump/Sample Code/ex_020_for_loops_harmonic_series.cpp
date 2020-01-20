// Compute the sum of the first N terms of the harmonic series using a for loop.
// It might actually be better for the purpose of accuracy to sum this series in the reverse order
// (starting with small terms first). We might discuss why this is the case later.
#include <iostream>

using namespace std;

int main()
{
	
	constexpr int N = 10000000;

	
	// Use a variable to keep track of a running total
	double total = 0.0;	

	for(int i = 1; i < N + 1; i++){
		// Must use 1.0/i to avoid an easy to overlook problem
		total += 1.0/i;
	}
	
	cout << "The sum of the first " << N << " terms of the harmonic series is " << total << endl;

	return 0;
}
