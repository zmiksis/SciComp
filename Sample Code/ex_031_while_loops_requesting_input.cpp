// This program requests that the user enter a positive even integer.
// It will keep requesting until the user does enter such an integer.
// This program may not work correctly if the user enters a string.
// There are ways of dealing with this possibility, though.

// The next example program is probably a better way of obtaining user input.
#include <iostream>

using namespace std;

int main(){
	int user_int;
	
	// Some people dislike while(true)
	while (true) {
		cout << "Please enter a positive even integer: ";
		cin >> user_int;
		
		// Break the loop if the conditions are met.
		// 'break' only breaks the innermost loop if you
		// have nested loops.
		if (user_int > 0 && user_int % 2 == 0) {
			break;
		} else {
			cout << "Sorry, " << user_int << " is not a positive even integer. " << endl;
		}
	}

	cout << "The positive even integer that you entered was: " << user_int << endl;

	return 0;
}
