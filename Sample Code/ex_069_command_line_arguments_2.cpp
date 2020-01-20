// This program also prints out the command line arguments that you entered, 
// after converting them to strings.

#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main(int argc, char* argv[]){

	if(argc == 1){
		cout << "You did not enter any command line arguments!" << endl;
		return 0;
	}		

	// Let's make a vector to store the command line arguments as strings.
	// We will ignore the element at index 0 in argv because it is just the program name.
	vector<string> command_line_vector(argc-1);
	for(int i = 0; i < argc - 1; i++){
		command_line_vector[i] = argv[i+1];
	}

	cout << endl << "The command line arguments that you entered were: " << endl;
	for(int i = 0; i < command_line_vector.size(); i++){
		cout << command_line_vector[i] << "\t";
	}
	cout << endl;

	return 0;
}
