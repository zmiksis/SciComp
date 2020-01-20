#include <iostream>

using namespace std;

int func(int n);

int main(){

  int N;
  cout << "Please enter an integer N: ";
  cin >> N;

  int sum = 0;

  // Summation loop
  for(int i = 1; i <= N; ++i){
    // Check if f(n) is odd
    if(func(i) % 2 != 0){
      sum += func(i);
    }
  }

  cout << "Sum of values is " << sum << "." << endl;

}

int func(int n){

  int f;

  if(n <= 2){
    f = n;
  }else if(n > 2 && n % 2 == 0){
    f = 5*func(n/2) + 1;
  }else{
    f = func((n-1)/2) + 2;
  }

  return f;

}
