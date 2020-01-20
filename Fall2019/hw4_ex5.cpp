#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<bool> sieve_primes(int N);

int main(){

  int N;
  cout << "Enter N: ";
  cin >> N;

  vector<bool> prime_sieve_vector = sieve_primes(N);
  vector<int> prime_numbers;
  for(int i = 0; i < prime_sieve_vector.size(); i++){
    if(prime_sieve_vector[i]){
      prime_numbers.push_back(i);
    }
  }

  int n;
  double phi;
  double sum;
  for(int i = 1; i <= N; i++){
    vector<int> exponents;
    n = i;
    // Compute prime factorization of n
    for(int j = 0; j < prime_numbers.size(); j++){
      exponents.push_back(0); // Start exponent at 0
      while(n % prime_numbers[j] == 0){
        n /= prime_numbers[j]; // Divide n by p
        ++exponents[j]; // Add one to the exponent
      }
    }

    // Compute phi(n)
    phi = 1;
    for(int j = 0; j < exponents.size(); j++){
      if(exponents[j] > 0){
        phi *= pow(prime_numbers[j],exponents[j]) - pow(prime_numbers[j],exponents[j]-1);
      }
    }

    sum += phi;
  }

  cout << "Sum is: " << sum << endl;

}

vector<bool> sieve_primes(int N) {

        // Mark initially all indices with true, crossing out the indices
        // which are not prime by marking them false later on
        vector<bool> prime_sieve_vector (N + 1, true);

        // both 0 and 1 are not prime numbers
        prime_sieve_vector[0] = false;
        prime_sieve_vector[1] = false;

        int i = 2;
        int composite_marker;

        // for efficiency, only need i up to sqrt(N)
        // proceed through the integers
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
