#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Define three strings. Note that we have defined three variables specifying the
	// string type for all three at once.
	// My preferred style is to define each on a separate line, specifying the type
	// each time, but you might see this sometimes.
  string first_name, last_name, full_name; 
	cout << "Enter your first name: "; 
	cin >> first_name; 
	cout << "Enter your last name: "; 
	cin >> last_name;
	
	// Concatenate three strings (two string objects and one string literal) to form full_name
	full_name = first_name + " " + last_name;
	cout << "Your full name is: " << full_name << endl;
	
	return 0;
}
