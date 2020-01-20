#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve_primes(int N);

int main(){
	
	int N;
	cout << "Enter N: ";
	cin >> N;

	vector<bool> prime_sieve_vector = sieve_primes(N);
	
	for (int i = 0; i <= N; i++){
		if (prime_sieve_vector[i]){
			cout << i << " is prime." << endl;
		} else {
			cout << i << " is not prime." << endl;
		}
	}

	return 0;	

}
// Might be better to rewrite this using pass by reference to avoid returning
// a copy of a possibly large vector
// This function returns a vector of true/false of length N + 1,
// true for prime, false for not prime 
vector<bool> sieve_primes(int N) {

	vector<bool> prime_sieve_vector (N + 1, true);

	// both 0 and 1 are not prime numbers
	prime_sieve_vector[0] = false;
	prime_sieve_vector[1] = false;

	int i = 2;
	int composite_marker;
	
	// for efficiency, only need i up to sqrt(N)
	while (i * i <= N){
			
		// If i has still been marked composite, move on
		if (!prime_sieve_vector[i]){
			i++;
			continue;
		}

		// use composite_marker to set the values at composite indices in prime_sieve_vector to false
		composite_marker = i + i;
		while (composite_marker <= N) {
			prime_sieve_vector[composite_marker] = false;
			composite_marker += i;
		}
		
		i++;
	}

	return prime_sieve_vector;
}

	
