// Computes the sum of a two dimensional mathematical array using nested for loops.
// The array looks like:
// 
// 			1	2	3	4	5	...	N
//				2	3	4	5	... N
//					3 4 5 ... N
//						4 5	... N
//							5 ... N
//								 ..	N
//									.	N
//										N

#include <iostream>

using namespace std;

int main(){
	// long ints are integers that may have a larger maximum size.
	// There is a trade off in that they may require more memory to store.
	// constexpr long int N = 1000;
	constexpr long int N = 100000;
		
	long int total = 0;
	for(long int i = 1; i <= N; i++){
		for (long int j = i; j <= N; j++){
			total += j;
		}
	}
	
	cout << "The total of the mathematical array with N == " << N << " is " << total << endl;
	
	long int formula_total = (N * (N + 1) * (2 * N + 1))/6;

	cout << "The total according to the formula with N == " << N << " is " << formula_total << endl;	

	return 0;
}
