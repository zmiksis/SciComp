// Program introducing cin for requesting user input
#include <iostream>
// Must include the string library to create objects with the string type
#include <string>

using namespace std;

int main() {
	// Define two integers a and b
	// Can define multiple variables of the same type using a comma,
	// but I generally prefer not to do this
	int a, b;

	cout << "Please enter two integers, a and b, separated by a space: ";
	cin >> a >> b;
	
	cout << "The value of a that you entered is: " << a 
				<< " and the value of b that you entered is: " << b << endl;

	// Add some additional linebreaks to make output easier to read
	cout << endl << endl;

	// You can also obtain variables of different types on the same line

	int favorite_integer;
	string first_name;
	 
	cout << "Please enter your first name, followed by your favorite integer: ";
	cin >> first_name >> favorite_integer;
	
	cout << first_name << "'s favorite integer is " << favorite_integer << endl << endl;

	return 0;

}
