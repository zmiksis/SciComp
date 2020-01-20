#include <iostream>
#include <cmath>
using namespace std;

bool primetest(long N)
{
    if(N <= 1) return false;
    if(N == 2) return true;
    if(N % 2 == 0) return false;

    for(long i= 3; i*i <= N; i+=2){
      if(N % i == 0) return false;
    }
    return true;
}

/*
void tester(long i)
{
  bool isprime = primetest(i);
  if (isprime){
    cout << i << " is prime" << endl;
  }else{
    cout << i << " is not prime" << endl;
  }
}
*/

int main()
{
  /*
  tester(pow(2,31) - 1);  // Euler (1772): 2,147,483,647 (2.1e9)
  tester((pow(2,59) - 1)/179951); // Landry (1867): 3,203,431,780,337 (3.2e12)
  tester(pow(2,127)-1); // Lucas (1876): 170,141,183,460,469,231,731,687,303,715,884,105,727 (1.7e38)
  */
  bool isprime;
  cout << "Enter a positive integer up to which to test primality." << endl;
  cin >> num;
  for(int i=1; i<=num; i++){
      isprime = primetest(i);
      if (isprime){
        cout << i << " is prime" << endl;
      }else{
        cout << i << " is not prime" << endl;
      }
  }
  return 0;
}