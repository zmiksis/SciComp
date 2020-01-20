#include <iostream>
#include <vector>

using namespace std;

int main(){

  int n;
  cout << "Please enter the number of values to sort: ";
  cin >> n;
  vector<int> vals(n);
  for(int i = 0; i < n; ++i){
    cout << "Please enter an interger: ";
    cin >> vals[i];
  }

  int temp;
  for(int i = 0; i < n-1; ++i){
    for(int j = i+1; j < n; ++j){
      if(vals[i] > vals[j]){
        temp = vals[i];
        vals[i] = vals[j];
        vals[j] = temp;
      }
    }
  }

  for(int i = 0; i < n; ++i){
    cout << vals[i] << endl;
  }
}
