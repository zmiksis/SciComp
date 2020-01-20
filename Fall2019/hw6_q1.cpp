#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "hw_6_ex_1_f.h"

using namespace std;

int main(int argc, char * argv[]){

  double y = stod(argv[1]);
  double b = stod(argv[2]);
  int N = stoi(argv[3]);
  string outFILE  = argv[4];

  double x = 0;
  double h = b/N;

  ofstream ofs;
  ofs.open(outFILE);

  ofs << x << "  " << y << endl;

  for(int i = 0; i < N; i++){
    y += f(x,y)*h;
    x +=h;
    ofs << x << "  " << y << endl;
  }

  ofs << flush;
  ofs.close();

  return 0;

}
