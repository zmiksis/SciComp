#include <iostream>

using namespace std;

int main(){

  int num_apples, num_oranges, num_bananas, num_lemons;

  cout << "Please enter the number of apples: ";
  cin >> num_apples;
  cout << "The total bill for " << num_apples << " apples is $" << num_apples*0.75 << endl;

  return 0;
}
