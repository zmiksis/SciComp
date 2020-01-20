#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  double tol;
  cout << "Please enter a tolerance: ";
  cin >> tol;

  int k = 0;
  double sum = 0;
  double error = 1;
  double Sk, Sk_old;
  while(error > tol){
    Sk = pow(-1,k)/(k+1+log(pow(k,2)+4));
    sum += Sk;
    if (k > 0){
      error = abs(Sk-Sk_old);
    }
    Sk_old = Sk;
    ++k;
  }
  cout << "Sum = " << sum << endl;
  cout << "Error = " << error << endl;

}
