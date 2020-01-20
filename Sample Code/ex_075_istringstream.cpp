#include <iostream>
#include <string>
#include <vector>


// To use string streams
#include <sstream>


using namespace std;

int main(){
	string s = "This is a test string. We will extract one word at a time using a string stream!";

	istringstream iss;

	// Open the string s for extraction
	iss.str(s);

	// The .str() function with no arguments will tell you what string iss is reading from.
	cout << "We are reading from the string: " << iss.str() << endl;

	// Need a string to extract into
	string word;
	
	int count = 0;

	// By default, the extraction operator seeks up to the next whitespace (or end of stream)
	while(iss >> word){
		count += 1;
		cout << "Word number " << count << " is: ";
		cout << word << endl;
	}


	return 0;

}
