// This program requests the user input an integer,  
// and then tells the user if the input was positive, negative, or zero
#include <iostream>

using namespace std;

int main() {
	int user_int;
	cout << "Please enter an integer: ";
	cin >> user_int;

	// Three possibilities considered - positive, negative, or zero
	if (user_int > 0){
		cout << "You entered a positive integer!" << endl;
	} else if (user_int < 0){
		cout << "You entered a negative integer!" << endl;
	} else {
		cout << "You entered zero!" << endl;
	}
	
	cout << "Thank you!" << endl;	

	return 0;
}
