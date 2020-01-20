// This program requests that the user enter two integers
// If the first integer is positive OR the second integer is NOT divisible by three,
// the program reports this fact.
#include <iostream>

using namespace std;

int main()
{

	int user_int_1;
	int user_int_2;

	cout << "Enter a positive integer: ";
	cin >> user_int_1;
	
	cout << "Enter an integer that is divisible by 3: ";
	cin >> user_int_2;

	// Test if the input is incorrect using logical or, logical not
	if ( (user_int_1 <= 0) || !(user_int_2 % 3 == 0) ) {
		cout << "Incorrect-- either the first integer is nonpositive or the second integer is not divisible by three!" << endl;
	} else {
		cout << "Correct, the first integer is positive and the second integer is divisible by three!" << endl;
	}

	return 0;
}
