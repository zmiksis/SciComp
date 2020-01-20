#include <iostream>
#include <cmath>

using namespace std;

int main(){

  double tol;
  cout << "Please input tolerance: ";
  cin >> tol; // Should be small

  double sum = 0; // Initialize sum
  double error = 1; // Initialize error

  int k = 0;
  double ak;
  while (error >= tol){
    ak = pow(-1,k)/(k+1+log(pow(k,2)+4));
    sum += ak; // Compute partial sum
    error = abs(pow(-1,k+1)/((k+1)+1+log(pow(k+1,2)+4))); // Compute error with
                                                  // alternating series test
    ++k;
  }
  cout << sum << endl;
  cout << error << endl;
}
