#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

  int num_apples;
  cout << "Input the number of apples, 1-5: ";
  cin >> num_apples;

  vector <string> numbers(6);
  numbers[0] = "zero";
  numbers[1] = "one";
  numbers[2] = "two";
  numbers[3] = "three";
  numbers[4] = "four";
  numbers[5] = "five";

  cout << "You would like " << numbers[num_apples] << "apples." << endl;
}
