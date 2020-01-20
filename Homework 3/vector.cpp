/*
In this program, we take user input on the number of apples the user
would like, and output the word for the number (which has been stored
in a vector) as well as the numeral.
Example: Please enter how many apples you would like, 1-5: 4
         You would like four (4) apples.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void output(vector<string>number, int num_apples){
  // We input the vector and the number of apples, and display
  // the ouput statement.
  cout << "You would like " << number[num_apples] << " (" << num_apples << ") apples" << endl;
  return;
}

int main(){

  int num_apples;
  cout << "Please enter how many apples you would like, 1-5: ";
  cin >> num_apples;

  vector <string> number;     // Create an empty vector of strings.
  number.push_back("zero");   // Push an entry into the end of the vector.
  number.push_back("one");    // Example: If the vector is [1,2,3], the
  number.push_back("two");    // command push_back(4) will give the vector
  number.push_back("three");  // [1,2,3,4].
  number.push_back("four");
  number.push_back("five");

  output(number, num_apples); // Pass our vector and value to the output function.

}
