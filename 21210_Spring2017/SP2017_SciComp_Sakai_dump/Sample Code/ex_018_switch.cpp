// This program demonstrates the use of the switch statement.
// It requests that the user input a menu option, and then displays the menu option requested,
// or tells the user that their entry was not valid.
#include <iostream>

using namespace std;

int main()
{
	int user_option;

	cout << "Please enter a menu choice: (1)Water (2)Soup (3)Salad: ";
	cin >> user_option;

	// The switch statement can accept an integer, character, or enumeration (perhaps discussed later).
	// It cannot accept other types, like strings or doubles.
	// This switch statement prints the user's order depending on the integer that they entered.
	switch(user_option){
		case 1: 
			cout << "You have ordered water." << endl;
			break;
		case 2:
			cout << "You have ordered soup." << endl;
			break;
		case 3:
			cout << "You have ordered salad." << endl;
			break;
		default:
			cout << "That option is not valid." << endl;
			break;
	} 

	return 0;
}
