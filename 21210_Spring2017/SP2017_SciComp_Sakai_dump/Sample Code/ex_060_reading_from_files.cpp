// Introduction to reading from files
// Must #include <fstream> for file i/o
// Use an input file stream (ifstream) to read from a file on the disk


#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ifstream input_file;
	
	// By default, look for the file of the given name in the current directory
	// If the file is not in the current directory, you will need to specify the path,
	// which will depend on the operating system.
	// You can put all files that you will open in this course in the same directory as your program.
	input_file.open("ex_060_data.dat");


	// Check if the file could not be opened. 
	// This is generally good practice, and more important when the name of the file
	// could be supplied by a user or obtained elsewhere
	if (! input_file.is_open() ){
		cout << "The file could not be opened!" << endl;
		return 0;
	}

	int x;
	// Read values of x from the file until getting to the end
	// Note that the file contains only integers, so we won't obtain an error but will reach the end of the file.
	while (input_file >> x){
		cout << "The next value of x is: " << x << endl;
	}

	// You can use .eof() to test if you have tried to read past the end of the file.
	if (input_file.eof()){
		cout << "You reached the end of the file!" << endl;

	// You can use .good() to check if the stream is in a 'good' state.
	// Note that reaching the end of the file will set the stream into a not good state.
	// There is actually also a 'bad' state which is NOT the opposite of the good state,
	// but we will not worry about it in this course.
	// Trying to read the wrong type (e.g. string into int) 
	// will place the stream in a not good state, 
	// and trying to read past the end of the file will place the stream in a not good state.
	} else 	if (!input_file.good()) {
		cout << "Something went wrong!" << endl;
		return 0;
	}


	
	// Close the file after reading from it.
	input_file.close();

	// If you want to reuse the stream to open a new file, or the same one again, 
	// You should use .clear() to clear the not good state of the stream.

	input_file.clear();

	input_file.open("ex_060_data.dat");

	cout << endl << "Reading the file again!" << endl;
	while (input_file >> x){
		cout << "The next value of x is: " << x << endl;
	}

	input_file.close();

	return 0;
}
