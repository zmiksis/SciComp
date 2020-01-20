// Program introducing cin for requesting user input
#include <iostream>
// Must include the string library to create object with the string type
#include <string>


int main()
{
	// Define a string to hold a name
	std::string user_name;
	
	// Prompt the user for input
	std::cout << "Enter your name: ";
	std::getline(std::cin, user_name);
	std::cout << "Your name is: " << user_name << std::endl;

	return 0;
}
