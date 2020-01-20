// This program requests that the user enter a positive even integer.
// It will keep requesting until the user does enter such an integer.
// This program will terminate early if the user enters a string that
// cannot be interpreted as an integer.

#include <iostream>

using namespace std;

int main(){
	int user_int;
	
	// Another approach. This one is a little more sophisticated.
	// The loop will terminate at the condition if the user enters something
	// that cannot be converted automatically to an integer.
	// Otherwise, the loop will terminate once the user enters a positive even integer,
	// but this termination occurs at the break statement.
	cout << "Please enter a positive even integer: "; 
	while (cin >> user_int) {

		
		// Break the loop if the conditions are met.
		// 'break' only breaks the innermost loop if you
		// have nested loops.
		if (user_int > 0 && user_int % 2 == 0) {
			break;
		} else {
			cout << "Sorry, " << user_int << " is not a positive even integer. " << endl;
			cout << "Please enter a positive even integer: ";
		}
	}

	// Check to see if cin is still in a "good" state.
	// If the user entered something that was not an integer,
	// cin will be in a "not good" state
	if (!cin.good()){
		cout << "Error: that was not an integer!" << endl;
		return 0;
	}

	cout << "The positive even integer that you entered was: " << user_int << endl;

	return 0;
}
