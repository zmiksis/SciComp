#include <iostream>

using namespace std;

int f_func(int n){
  int f;
  if(n%2 == 0){
    f = n/2;
  } else {
    f = 3*n + 1;
  }
  return f;
}

int H_func(int n){
  int H = 0;
  while(n != 1){
    n = f_func(n);
    ++H;
  }
  return H;
}

int main(){

  cout << "Please enter an integer N: ";
  int N;
  cin >> N;
  int S = 0;
  for(int i = 1; i <= N; ++i){
    S += H_func(i);
  }

  cout << "The sum S(" << N << ") is: " << S << endl;

}
