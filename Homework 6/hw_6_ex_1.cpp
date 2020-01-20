#include <iostream>
#include <vector>

using namespace std;

#include "hw_6_ex_1_f.h"

int main(){

  // Take these values as command line input arguments
  double y0 = 1;
  double b = 10;
  int N = 1000;
  double h = b/N;

  // Generate x-values (grid)
  vector<double> x(N+1);
  for(int i = 0; i < N+1; ++i){
    x[i] = i*h;
  }

  // Generate empty vector for y-values
  vector<double> y(N+1);
  y[0] = y0;

  // Compute Euler's method
  for(int i = 0; i < N; ++i){
    y[i+1] = y[i] + f(x[i],y[i])*h;
  }

  // Output values
  for(int i = 0; i < N+1; ++i){
    cout << x[i] << " " << y[i] << endl;
  }

  return 0;
}
