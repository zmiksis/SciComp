#include <iostream>
#include <cmath>

using namespace std;

int main(){

  double tol;
  cout << "Please enter a non-negative error tolerance: ";
  cin >> tol;
  while(tol <= 0.){
    cout << "Please enter a non-negative error tolerance: ";
    cin >> tol;
  }

  int num_terms = 0;
  double error = abs(1./(num_terms + 1 + 2. + log(pow(num_terms + 1,2.5) + 1.)));
  double sum = 0.;
  while(error >= tol){
    sum += pow(-1,num_terms)/(num_terms + 2. + log(pow(num_terms,2.5) + 1.));
    error = abs(1./(num_terms + 1 + 2. + log(pow(num_terms + 1,2.5) + 1.)));
    num_terms++;
  }

  cout << "Sum: " << sum << endl;
  cout << "Number of terms: " << num_terms << endl;

}
