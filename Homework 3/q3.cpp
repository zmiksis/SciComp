#include <iostream>

using namespace std;

int test(int n){

  int boo = 0;
  for(int i = 2; i < n; ++i){
    if(n%i == 0){
      ++boo;
    }
  }
  if(boo == 0){
    return 0;
  } else {
    return 1;
  }
}

int main(){

  int N;
  cout << "Please input an integer N: ";
  cin >> N;
  int boo;
  cout << "1 is NOT prime." << endl;
  if(N > 1){
    for(int i = 2; i <= N; ++i){
      boo = test(i);
      if(boo == 0){
        cout << i << " is prime." << endl;
      } else {
        cout << i << " is NOT prime." << endl;
      }
    }
  }

}
