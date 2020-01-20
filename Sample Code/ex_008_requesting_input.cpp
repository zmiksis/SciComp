// Program introducing cin for requesting user input
#include <iostream>
// Must include the string library to create objects with the string type
#include <string>


using namespace std;

int main() {
	// Define a string to hold a name
	string user_name;
	
	// Prompt the user for input
	cout << "Enter your name: ";
	cin >> user_name;
	cout << "Your name is: " << user_name << endl;

	return 0;
}
