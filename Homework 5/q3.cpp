#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

double fval(double &x);
double fpval(double &x);

int main(int argc, char * argv[]){

  double tol;
  int iter;
  vector<double> x_val;

  if(argc == 1){
    iter = 20;
    x_val.push_back(0);
    tol = pow(10,-7);
  } else if(argc == 2){
    iter = 20;
    x_val.push_back(argv[2]);
    tol = pow(10,-7);
  } else if(argc == 3){
    iter = 20;
    x_val.push_back(argv[2]);
    tol = argv[3];
  } else{
    iter = argv[4];
    x_val.push_back(argv[2]);
    tol = argv[3];
  }

  double f = fval(x_val[0]);
  int iter_count = 0;
  while(abs(f) >= tol && iter_count < iter){
    // Compute Newton's method here
  }

  ofstream ofs;

  ofs.open("hw_5_ex_3_output.dat");

  if(!ofs.is_open()){
		cout << "The file failed to open!" << endl;
		return 0;
	}

  for(int i = 0; i < x_val.size(); ++i){
    ofs << x_val[i] << '\n';
  }

  ofs << flush;
  ofs.close();

  return 0;

}

double fval(double &x){
    double fval = pow(x,5) - x +1.;
    return fval;
}

double fpval(double &x){
    double fpval = 5.*pow(x,4) - 1.;
    return fpval;
}
