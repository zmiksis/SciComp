#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){

	if (argc < 2){
		cout << "You did not enter any file names!" << endl;
		return 0;
	}

	string alphalower = "abcdefghijklmnopqrstuvwxyz";
	string alphaupper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	vector<int> alphacount(26);
	int sum = 0;

	vector<string> files(argc - 1);

	for (int i = 0; i < files.size(); i++){
		files[i] = argv[i+1];
	}

	ifstream input_file;

	for (string file : files){
		input_file.clear();

		input_file.open(file);

		if (!input_file.is_open()){
			cout << "Error: data file could not be opened.\nNow exiting.\n" << endl;
			return 0;
		}

		string line;

		while(getline(input_file, line)){ // Read line
			for (char character : line){ // Loop over characters in line
				for (int i=0; i < 26; i++){ // Check each letter of English alphabet
					if ((character == alphalower[i]) || (character == alphaupper[i])){ // if lower or upper case exists on line
						alphacount[i] += 1; // increase count for that letter
						sum += 1; // increase total count for all letters
					}
				}
			}
		}

		if (input_file.eof()){
	        cout << endl;
	        cout << file << " has been read successfully." << endl;
	        cout << endl;
	    }else if (!input_file.good()) {
	        cout << "Something went wrong!" << endl;
	        return 0;
	    }

		input_file.close();    	
	}

	for (int i=0; i < 26; i++){
		cout << "Letter " << alphaupper[i] << "/" << alphalower[i] << " appeared " << alphacount[i] << " times." << endl;
		cout << "Frequency = " << float(alphacount[i] * 100) / sum << "%" << endl;
	}

}