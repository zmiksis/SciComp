#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "hw5_ex2_f.h"

int main(int argc, char * argv){

  double tol;
  int iter;
  vector<double> x_val;

  if(argc == 1){
    tol = .0000001;
    iter = 20;
    x_val.push_back(0);
  }else if(argc == 2){
    tol = .0000001;
    iter = 20;
    x_val.push_back(argv[1]);
  }else if(argc == 3){
    tol = argv[2];
    iter = 20;
    x_val.push_back(argv[1]);
  }else if(argc == 4){
    tol = argv[2];
    iter = argv[3];
    x_val.push_back(argv[1]);
  }

  double f = fval(x_val[0]);
  double fp = fpval(x_val[0]);
  int iter_count = 0;
  while(abs(f) >= tol && iter_count < iter){
    // Implement Newton's method
    if(fp == 0){
      cout << "ZERO DERIVATIVE" << '\n';
      return 0;
    }
  }

  // Write the iterations of x to a file

  return 0;

}
