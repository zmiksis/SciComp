#include <iostream>

using namespace std;

int main()
{
	constexpr long int N = 1000;
	// constexpr long int N = 200000;
		
	long int total = 0;
	for(long int i = 1; i < N + 1; i++){
		for (long int j = i; j < N + 1; j++){
			total += j;
		}
	}
	
	cout << "The total of the array with N == " << N << " is " << total << endl;
	
	long int formula_total = (N * (N + 1) * (2 * N + 1))/6;

	cout << "The total according to the formula with N == " << N << " is " << formula_total << endl;	

	return 0;
}
