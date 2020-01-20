#include <iostream>
#include <string>

using namespace std;

// The usual way of implementing command line arguments is with two parameters to main.
// Probably the most important use of command line arguments for our purposes will be to pass the program a filename to open. 
// argc is an integer that keeps track of the number of arguments passed.
// argv is an array of C-style strings. 
// (You can also use char** argv, but I prefer the style below.)
// The first element of argv contains the name of the program being run or an empty string.
// The remaining elements of argv will be optional values passed by the user on the command line after the name of the program.
// I recommend converting the C-style strings to members of the C++ string class, as we will see in the next program.

// This program just prints out the command line arguments passed in.
int main(int argc, char* argv[]){
	
	
	// First, check if there were any arguments passed in.
	if (argc == 1) {
		cout << "You did not enter any command line arguments!" << endl;
		return 0;
	} else{
		cout << "The arguments that you entered were: " << endl;
		for (int i = 1; i < argc; i++){
			cout << argv[i] << endl;
		}
		return 0;
	}
}
