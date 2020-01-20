// Introduction to C-style strings

#include <iostream>
#include <string>

using namespace std;

int main(){

	// C-style strings are arrays of characters
	// This initialization is equivalent to
	// char my_c_string[] = {'H', 'e', 'l', 'l', 'o', '\0'};	
	char my_c_string[] = "Hello";

	// You can also use pointers to implement C-style strings.
	// We will discuss pointers later.

	// This behavior of printing an array is peculiar to C-style strings.
	// If you try to print an array of a type other than char, it will print the address
	// rather than the contents.
	cout << "The C-style string my_c_string is " << my_c_string << endl;


	// Avoid using this technique to find the length of an array in general, 
	// it will not work for arrays passed as parameters to functions, for instance.
	// Note that the length of this string is six, due to the null termination character.
	cout << "The length of my_c_string is " << sizeof(my_c_string)/sizeof(my_c_string[0]) << endl;


	// Let's convert a C-style string to a C++ string

	string s = my_c_string;
	
	cout << "The string s is " << s << endl;	

	// Call the size member function to get the length of a string
	cout << "The length of s is: " << s.size() << endl;
	// Note the reduction in length by one due to the removal of the null termination character

	// You can also use the subscript operator [] to retrieve individual characters in a string

	return 0;
}
