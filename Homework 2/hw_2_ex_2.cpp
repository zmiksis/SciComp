#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

  double num_apples, num_bananas, num_oranges, num_lemons;
  cout << fixed;

  cout << endl << "Please enter the number of apples: ";
  cin >> num_apples;
  if (num_apples == 1){
    cout << "The total bill for " << num_apples << " apple is: $" << setprecision(2) << num_apples << endl;
  } else if (num_apples < 0){
    cout << "Oops! Please enter a non-negative number of apples: ";
    cin >> num_apples;
  } else {
    cout << "The total bill for " << num_apples << " apples is: $" << setprecision(2) << num_apples << endl;
  }
  cout << "Please enter the number of bunches of bananas: ";
  cin >> num_bananas;
  cout << "The total bill for " << num_bananas << " bunches of bananas is: $" << num_bananas*2.75 << endl;
  cout << "Please enter the number of oranges: ";
  cin >> num_oranges;
  cout << "The total bill for " << num_oranges << " oranges is: $" << num_oranges*1.25 << endl;
  cout << "Please enter the number of lemons: ";
  cin >> num_lemons;
  cout << "The total bill for " << num_lemons << " lemons is: $" << num_lemons*1.75 << endl;

  double total_item = num_apples+num_bananas+num_oranges+num_lemons;
  double total_cost = num_apples+num_bananas*2.75+num_oranges*1.25+num_lemons*1.75;

  cout << endl << endl << "The total number of items purchased is: " << total_item << endl;
  cout << "The total bill is: $" << total_cost << endl << endl;

  return 0;

}
