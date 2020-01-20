#include <iostream>
#include <cmath>

using namespace std;

int main(){

  double tol;
  cout << "Please enter a non-negative tolerance: ";
  cin >> tol;

  double error = 1;
  double sum = 0;
  double Sk, sum_1;
  int k = 0;
  while(error >= tol){
    // Sumation loop
    Sk = pow(-1,k)/(k+1+log(pow(k,2)+4)); // New term in the series
    sum += Sk; // Increase the sum
    if (k>0){
      error = abs(sum-sum_1); // Error using alternating series test
    }
    sum_1 = sum; // Store new sum into old sum before continuing
    ++k;
  }
  cout << "Sum = " << sum << endl;
  cout << "Error = " << error << endl;

}
