#include <iostream>

using namespace std;

int f_func(int n){

   int f;
   if(n <= 1){
     f = n;
   } else if(n == 2){
     f = 3;
   } else if(n%2 == 0 && n > 2){
     f = 2*f_func(n/2) + 3;
   } else if(n%2 != 0 && n >1){
     f = f_func((n+1)/2) + f_func((n-1)/2);
   }

   return f;
}

int main(){

  int N;
  cout << "Please enter an integer N: ";
  cin >> N;

  int S = 0;
  for(int i = 1; i <= N; ++i){
    if(f_func(i)%2 != 0){
      S += f_func(i);
    }
  }

  cout << "The sum S(" << N << ") is: " << S << endl;

}

/*
f(1) = 1
f(2) = 3
f(3) = f(2) + f(1) = 4
f(4) = 2*f(2) + 3 = 9
f(5) = f(3) + f(2) = 7
S(5) = 1 + 3 + 9 + 7 = 20
*/
