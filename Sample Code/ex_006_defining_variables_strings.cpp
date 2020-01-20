// Program introducing defining variables
#include <iostream>
// Use the following include to work with string objects
#include <string>

int main() {
	// Define and initialize a string named test_string
	std::string test_string = "This is a string";
	
	std::cout << "test_string contains: " << test_string << std::endl;

	// Assign a new value to test_string
	
	test_string = "the new value for test_string";
	
	std::cout << "test_string now contains: " << test_string << std::endl;
	
	return 0;
}
