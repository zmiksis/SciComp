// Introduction to reading from files
// In this program we use getline to read a file line by line


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

	// You can open the file when you define the file stream.
	ifstream input_file("ex_061_text.txt");

	if (!input_file.is_open()){
		cout << "Error: file could not be opened." << endl;
	}
	
	string line;

	cout << endl;

	// This will repeatedly get new lines until the end of the text is reached, and then stop
	while(getline(input_file, line)){
		// Print out the line obtained from the file
		cout << line << endl;
	}

	cout << endl;

	input_file.close();

	return 0;
}
