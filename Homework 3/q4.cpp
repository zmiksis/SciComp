#include <iostream>

using namespace std;

double f_func(int n){
  double f;
  if(n%2 == 0){
    f = n/2;
  } else {
    f = 3*n + 1;
  }

  return f;
}

double H_func(double n){

  double f = f_func(n);
  int H = 1;
  while(f != 1){
    f = f_func(f);
    ++H;
  }

  return H;
}

int main(){

  int N;
  cout << "Please input an integer N: ";
  cin >> N;
  double S = 0;
  double H;
  for(int i = 2; i <= N; ++i){
    H = H_func(i);
    S += H;
  }
  cout << "The value for S(" << N << ") is: " << S << endl;

}
