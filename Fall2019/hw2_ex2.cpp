#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){

  /*
  Notice the use of "fixed". This sets EXACTLY the number of digits shown
  after the decimal point. Play around with it! For more info:
  http://www.cplusplus.com/reference/ios/fixed/
  */
  cout << fixed << setprecision(2);

  int num_apples;
  // Using a string, and storing the exact phrasing you need later on, will
  // prevent the use of more if-else statements than needed in the code.
  string apples_plur;

  // Prompting the user to enter the number of apples.
  cout << "Please enter the number of apples: ";
  cin >> num_apples;

  // A while loop to continuously ask the user to enter a positive number, if
  // the number entered is less than zero.
  while (num_apples < 0){
    cout << "Please enter a postive number of apples: ";
    cin >> num_apples;
  }

  // Store the correct phrasing in a string.
  if(num_apples == 1){
    apples_plur = "apple";
  } else{
    apples_plur = "apples";
  }

  // Notice the use of spacing in quotation marks, and the period at the end of
  // the sentence!
  cout << "The total bill for " << num_apples << " " << apples_plur << " is $" << num_apples*0.75 << "." << endl;

  return 0;
}
