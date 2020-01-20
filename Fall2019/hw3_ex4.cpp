#include <iostream>

using namespace std;

int func(int n);
int Hfunc(int n);

int main(){

  int N;
  cout << "Please enter an integer N: ";
  cin >> N;

  int sum = 0;

  // Summation loop
  for(int i = 1; i <= N; ++i){
    sum += Hfunc(i);
  }

  cout << "Sum of values is " << sum << "." << endl;

}

int func(int n){

  int f;

  if(n % 2 == 0){
    // If n is even
    f = n/2;
  }else{
    // If n is odd
    f = 3*n + 1;
  }

  return f;

}

int Hfunc(int n){

    int H = 0;

    // Keep applying f(n) until f(n) = 1
    while(n != 1){
      // Evaluate f(n)
      n = func(n);
      // Count how many evaluations
      H++;
    }

    // Report number of evaluations
    return H;
}
