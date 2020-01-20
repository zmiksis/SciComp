// This program shows the use of the logical and, given in C++ by &&
// The program requests a user to enter an integer.
// The program then informs the user whether or not the integer is BOTH positive AND even.
#include <iostream>

using namespace std;

int main() {
	int user_int;
	cout << "Please enter an integer: ";
	cin >> user_int;

	if ( (user_int > 0) && (user_int % 2 == 0) ) {
		cout << "The integer that you entered is BOTH positive AND even!" << endl;
	} else {
		cout << "The integer that you entered is either not positive or not even!" << endl;
	}

	cout << "Thank you!" << endl;

	return 0;
}
