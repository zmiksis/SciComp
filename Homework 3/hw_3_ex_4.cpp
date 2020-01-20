#include <iostream>

using namespace std;

int f_func(int n){
    int f;
    if(n%2 == 0){
        f = n/2;
//        cout << f << endl;
    } else {
        f = 3*n + 1;
//        cout << f << endl;
    }
    return f;
}

int H_func(int n){
    int H = 0;
    while(n != 1){
        n = f_func(n);
        cout << n << endl;
        ++H;
        cout << H << endl;
    }
    return H;
}

int main(){

  int N;
  cout<< "Please enter an integer N:";
  cin >> N;

  int S = 0;
  for(int i = 0; i <= N; i++){
      S += H_func(i);
  }

  cout<< "The sum S(" << N << ") is " << S << endl;

  return 0;
}
