#include <iostream>

using namespace std;

int main(){

  int N;
  cout << "Please enter an integer N: ";
  cin >> N;

  int sum = 0;
  for(int i = 1; i <= N; ++i){
    if((i % 2 == 0 && i % 5 != 0) || (i % 2 != 0 && i % 5 == 0)){
      sum += i;
    }
  }

  int sum2 = 0;
  for(int i = 1; i <= N; ++i){
    if(i % 2 == 0 || i % 5 == 0){
      if(i % 2 == 0 && i % 5 == 0){

      }else{
        sum2 += i;
      }
    }
  }

  cout << "Sum: " << sum << endl;
  cout << "Sum: " << sum2 << endl;

}
