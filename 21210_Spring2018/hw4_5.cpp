#include <iostream>
#include <cmath>

using namespace std;

long int totient(int k);

int main()
{
  int N;
  long int sum = 0;
  cout << "Enter a positive integer N to compute the summatory totient function" << endl;
  cin >> N;
  for (int k=1; k<=N; k++){
    cout << totient(k) << endl;
    sum += totient(k); // add totient to sum
  }
  cout << "The summatory totient function is " << sum << endl;
  return 0;                                 
}

long int totient(int k){
  int tot=1;
  for (int i=2; i<=k; i++){ // Start at 2 because 1 is not a prime factor
    if (k % i == 0){ // Only bother to do this if i is a factor of k
      int count = 0; // Reset count to zero for this factor i
      while (k % i == 0){ // Repeat for this factor i
        count += 1; // Increase count
        k = k / i; // Divide as much as possible to ensure prime factorization
      }
      tot *= pow(i, count) - pow(i, count - 1); // Update totient product
    }
  }
  return tot;
}