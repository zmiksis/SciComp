#include <iostream>
using namespace std;

int factorial(int n)
{
    int val = 1;
    for(int i=1; i<=n; i++)
        val *= i;
    return val;
}

int main()
{
  int num = 10, nCk;
  for (int n=1; n<=num; n++){
      for (int k=0; k<=n; k++){
        nCk = 1.0*factorial(n)/(factorial (k)*factorial(n-k));
        cout << "n = " << n << ", k = " << k << ", nCk = " << nCk << endl;
      }
  }
  return 0;
}