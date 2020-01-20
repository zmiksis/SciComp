#include <iostream>
#include <string>
#include <vector>

using namespace std;

void output(vector<string>number, int num_apples){

  cout << "You would like " << number[num_apples] << " (" << num_apples << ") apples" << endl;
  return;
}

int main(){
// This program will output the number of apples someone would like to buy, 1-5

  int num_apples;
  cout << "Please enter how many apples you would like, 1-5: ";
  cin >> num_apples;
  // You would like four (4) apples.

  vector <string> number(6) = {"zero", "one", "two", "three", "four", "five"};

  output(number, num_apples);

}
