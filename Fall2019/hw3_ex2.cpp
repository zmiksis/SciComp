#include <iostream>

using namespace std;

int nchoosek(int n, int k);

int main(){

  for(int n = 0; n <= 10; n++){
    for(int k = 0; k <= n; k++){
      cout << "(" << n << ", " << k << ") = " << nchoosek(n,k) << endl;
    }
  }

}

int nchoosek(int n, int k){

  int NK;

  int nfact = 1;
  int kfact = 1;
  int nmkfact = 1;


  if(n != 0 && k != 0){
    for(int i = 1; i <= n; i++){
      nfact *= i;
    }
    for(int i = 1; i <= k; i++){
      kfact *= i;
    }
    for(int i = 1; i <= n-k; i++){
      nmkfact *= i;
    }
  }

  if(n == 0 || k == 0){
    NK = 1;
  }else{
    NK = nfact/(kfact*nmkfact);
  }

  return NK;
}
