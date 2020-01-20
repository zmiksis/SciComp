#include <iostream>
#include <random>
#include <vector>

#include "hw_6_ex_2_f.h"

using namespace std;

int main(){

  // Take the following as command line
  double a = 0;
  double b = 1;
  int N = 10000; // Number of points in interval

  // Create random generator
  random_device rd;
  int seed_value = rd();
  mt19937 generator(seed_value);

  uniform_real_distribution<double> distribution(a,b);

  // Select N random points in [a,b]
  vector<double> x(N);
  for(int i = 0; i < N; ++i){
    x[i] = distribution(generator);
  }

  double I = 0;
  for(int i = 0; i < N; ++i){
    I += ((b-a)/N)*f(x[i]);
  }

  cout << I << endl;
}
