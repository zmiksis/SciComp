#include <iostream>
using namespace std;

int main()
{
  int N, count, sum=0;

  cout << "Enter a positive integer:" << endl;
  cin >> N;

  for (long k=1; k<=N; k++){
    count = 0; int num=k;
    while (num != 1){
      if(num % 2 == 0){
        num = num/2;
      }else{
        num = (3*num + 1);
      }
      count++;
    }
    cout << "H(" << k << ") = " << count << endl;
    sum += count;  
  }
  cout << "---------------------7" << endl;
  cout << "S(N) is sum of all H(k) =" << sum << endl;

  return 0;
}