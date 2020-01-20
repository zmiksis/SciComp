// Introduction to reading from files
// In this program we use getline to read a file line by line


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

	// You can open the file when you define the file stream.
	ifstream ifs("ex_072_text.txt");

	if (!ifs.is_open()){
		cout << "Error: file could not be opened." << endl;
		return 0;
	}
	
	cout << endl;

	string line;

	// This will repeatedly get new lines until the end of the text is reached, and then stop
	while(getline(ifs, line)){
		// Print out the line obtained from the file
		cout << line << endl;
	}

	cout << endl;


	// Not really needed, since the ifstream will be closed automatically when it goes out of scope
	ifs.close();

	return 0;
}
