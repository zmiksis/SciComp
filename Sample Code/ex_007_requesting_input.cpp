// Program introducing cin for requesting user input
#include <iostream>

int main() {
	// Define an integer for the user to enter
	int a;
	
	// Incorporate a prompt to tell the user what they are entering
	std::cout << "Please enter an integer: ";
	std::cin >> a;
	std::cout << "The integer that you entered was: " << a << std::endl;
	return 0;
}
