// In this program, we open and print the contents of several files by the filenames supplied by the user
// as command line arguments


#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void print_file_contents(ifstream &ifs, string file_name);

int main(int argc, char * argv[]){

	if (argc == 1){
		cout << "You did not enter any file names!" << endl;
		return 0;
	}


	// Process command line arguments into a vector of file names
	vector<string> file_names(argc - 1);
	for (int i = 0; i < file_names.size(); i++){
		file_names[i] = argv[i+1];
	}

	ifstream ifs;
	
	for (string file_name : file_names){
		print_file_contents(ifs, file_name);
	}

	return 0;
}

// You should usually pass streams by reference
void print_file_contents(ifstream &ifs, string file_name){
	ifs.close();
	ifs.clear();
	ifs.open(file_name);
	
	if (!	ifs.is_open()){
		cout << endl << "Could not open the file " << file_name << endl << endl;
		return;
	}
	
	cout << endl << "Now printing the file " << file_name << ":" << endl << endl;
	
	string line;

	while( getline(ifs, line) ){
		cout << line << endl;
	}
	cout << endl;

	ifs.close();
	ifs.clear();	
	
	return;
}
	
