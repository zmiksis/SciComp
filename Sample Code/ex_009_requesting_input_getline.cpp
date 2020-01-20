// Program introducing getline for requesting user input
#include <iostream>
// Must include the string library to create objects with the string type
#include <string>

// Remember that you can incorporate using namespace std; here to avoid having
// to type std:: before cout, cin, endl, getline, etc.

int main() {
	// Define a string to hold a name
	std::string user_name;
	
	// Prompt the user for input
	std::cout << "Enter your name: ";
	// getline obtains an entire line at a time, allowing it to obtain spaces
	std::getline(std::cin, user_name);
	std::cout << "Your name is: " << user_name << std::endl;

	return 0;
}
