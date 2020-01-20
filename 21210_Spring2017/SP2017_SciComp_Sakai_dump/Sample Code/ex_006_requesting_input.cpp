// Program introducing cin for requesting user input
#include <iostream>

int main()
{
	// Define an integer for the user to enter
	int user_integer;
	
	std::cout << "Please enter an integer: ";
	std::cin >> user_integer;
	std::cout << "The integer that you entered was: " << user_integer << std::endl;
	return 0;
}
