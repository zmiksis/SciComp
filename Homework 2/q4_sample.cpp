#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int sum = 0;
  int N;
  cout << "Please enter a positive integer N: ";
  cin >> N;

  for(int i = 1; i <= N; ++i){
    // Check conditions:
    //  (1) Is i divisible by 2?
    // (2) Is i divisible by 3?
    // (3) Is i divisible by 2 and 3?
    cout << i%3 << endl;
    cout << i%2 << endl;
    if (i % 2 == 0 || i % 3 == 0){
      if (i % 2 == 0 && i % 3 == 0){

      }else {
        sum += i;
      }
    }
  }
  cout << sum << endl;

}
