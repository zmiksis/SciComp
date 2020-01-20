// This program requests the user input an integer,  
// and, if the value is greater than 0, tells the user the value was positive.
// Nothing is done if the value entered is negative.
#include <iostream>

using namespace std;

int main()
{
	int user_int;
	cout << "Please enter an integer: ";
	cin >> user_int;
	
	// The expression user_int > 0 evaluates to a boolean
	if (user_int > 0) {
		cout << "You entered a positive integer!" << endl;
	}

	return 0;
}
