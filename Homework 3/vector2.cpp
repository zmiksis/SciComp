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

  vector <string> number(6); // Declare that the vector of strings will have 6 elements
  number[0] = "zero";        // REMEMBER THAT INDEXING STARTS AT 0!
  number[1] = "one";         // Store the entry "one" in the vector entry number[1].
  number[2] = "two";         // This entry can now be referenced later!
  number[3] = "three";
  number[4] = "four";
  number[5] = "five";

  output(number, num_apples); // Pass our vector and value to the output function.

}
