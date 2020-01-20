#include <iostream>
#include <string>
#include <random>
#include <functional>

#include "hw_6_ex_2_f.h"

using namespace std;

int main(int argc, char * argv[]){

  double a = stod(argv[1]);
  double b = stod(argv[2]);
  int N = stoi(argv[3]);
  double x;
  double I = 0;

  random_device rd;
  int seed_value = rd();
  uniform_real_distribution<double> distribution(a,b);
  mt19937 generator(seed_value);
  auto draw = bind(distribution,generator);

  for(int i = 0; i < N; i++){
    x = draw();
    I += f(x);
  }

  I *= (b-a)/N;

  cout << "Approximate integral of f(x) over [" << a << ", " << b << "]: " << I << endl;

  return 0;

}
