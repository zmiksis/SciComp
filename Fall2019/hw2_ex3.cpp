#include <iostream>

#include <cmath>

using namespace std;

int main(){

  int N;
  cout << "Please enter an integer N: ";
  cin >> N;

  int sum, formula;

  formula = pow(N*(N+1)/2,2);
  cout << "Formula value: " << formula << endl;

  sum = 0;
  for(int i = 0; i <= N; i++){
      sum += pow(i,3);
  }
  cout << "Summation value: " << sum << endl;

}
