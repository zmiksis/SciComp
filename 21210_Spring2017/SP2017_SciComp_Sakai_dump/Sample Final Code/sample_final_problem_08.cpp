#include <iostream>

// For reading from files and writing to files
#include <fstream>

#include <map>

using namespace std;

int main(){

	ifstream input_file("transactions.dat");
	// Should probably check if the file actually opened, but I did not here
	
	// The map will associates names (strings) as keys and balances (ints) as values
	// We will exploit the fact that maps store their keys in order to simplify printing
	// the names in alphabetical order
	map<string, int> balance_map;

	// Easiest way to read the file is to recognize that each line
	// consists of a name followed by an integer, so just read them in
	// with an extraction in a while loop
	
	string name;
	int transaction;

	while(input_file >> name >> transaction){
		if (balance_map.count(name) > 0 ){
			balance_map[name] += transaction;
		} else {
			balance_map[name] = transaction;
		}
	}

	// Good to get into the habit of closing files when done with them
	input_file.close();

	// Open the correct file for output
	ofstream output_file("balances.dat");
	for(const auto &kv : balance_map){
		// Output the name (the key) followed by their balance (the associated value)
		// Use the escape character for newline to avoid flushing the buffer
		output_file << kv.first << " " << kv.second << '\n';
	}
	
	output_file << flush;
	output_file.close();


	return 0;
}
