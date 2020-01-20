// This program requests the user input an integer,  
// and, if the value is greater than 0, tells the user the value was positive,
// otherwise, it tells the user the value was non-positive.
#include <iostream>

using namespace std;

int main()
{
	int user_int;
	cout << "Please enter an integer: ";
	cin >> user_int;

	// Two possibilities considered - positive or non-positive
	if (user_int > 0){
		cout << "You entered a positive integer!" << endl;
	} else {
		cout << "You entered a non-positive integer!" << endl;
	}

	cout << "Thank you." << endl;

	return 0;
}
