// This program illustrates the technique of memoization.
// Memoization is the storing of the results of previous function calls
// so that you can retrieve them from a map (or table of some sort)
// rather than recalculate them.


// We will calculate a function defined by a recursive formula using memoization

// The function (for non-negative integers n) is:

// 					{ 1 											if n == 0
//	f(n) =	{ 3 											if n == 1
//          { f(n - 2) + f(n/2) 			if n is even otherwise
//          { f(n + 1) + f((n+1)/2) 	if n is odd otherwise

// Using memoization, you do not have to recalculate previous values, just look them up

#include <iostream>
#include <map>
#include <string>
#include <utility>


using namespace std;

long long int recursive_f(long long int n);
long long int memoized_f(long long int n, map<long long int, long long int> &memoization_f);

int main(){
	
	// Map of key-value pairs, where keys are inputs to the function and values are outputs
	map<long long int, long long int> memoization_f;
	memoization_f[0] = 1;
	memoization_f[1] = 3;

	


	long long int n;
	cout << "Please enter an integer n: ";
	cin >> n;
	
	cout << "Using memoization, the value of f(n) is: " << memoized_f(n, memoization_f) << endl;
	cout << "Using recursion, the value of f(n) is: " << recursive_f(n) << endl;

	return 0;
}



long long int recursive_f(long long int n){
	if (n == 0){
		return 1;
	} else if (n == 1) {
		return 3;
	} else if (n % 2 == 0){
		return recursive_f(n - 2) + recursive_f(n/2);
	} else {
		return recursive_f(n + 1) + recursive_f( (n+1)/2 );
	}
}



// pass the memoization map by reference and update it when you calculate f for
// a value of n that you haven't encountered before
long long int memoized_f(long long int n, map<long long int, long long int> &memoization_f){
	// First check to see if the output value for the input n has already been calculated,
	// and, if it has, just return the corresponding output without recalculating
	if(memoization_f.count(n) == 1){
		return memoization_f[n];
	} else {
		if (n % 2 == 0){
			long long int res = memoized_f(n - 2, memoization_f) + memoized_f(n/2, memoization_f);
			// Store the calculated value of f for future use
			memoization_f[n] = res;
			return res;
		} else {
			long long int res = memoized_f(n + 1, memoization_f) + memoized_f( (n+1)/2, memoization_f );
			// Store the calculated value of f for future use
			memoization_f[n] = res;
			return res;
		}
	}
}

