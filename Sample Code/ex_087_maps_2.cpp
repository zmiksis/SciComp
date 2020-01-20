// This is an unsophisticated implementation of using a map to count the number of letters that appear in a document.
// The program takes a single command line argument, the name of a single file, to read the letters from.

// The program leaves out many features such a program would probably want.
// For example, you would probably want to leave apostrophes intact for
// letters like "you're" but might want to remove them and the trailing letter 's' for possessive letters
// like "John's"



#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <vector>


// For isalnum
#include <cctype>

// For string streams
#include <sstream>


using namespace std;

string strip_punctuation(const string &line);

int main(int argc, char* argv[]){

	if (argc < 2) {
		cout << "Please enter a file name!" << endl;
		return 0;
	}

	ifstream ifs(argv[1]);

	// Create a map that will store the count of each letter that appears
	map<string, int> letter_count_map;

	// Store each line of the input file in a string called line
	string line;

	// Store each letter from a given line in a string called letter
	string letter;

	while(getline(ifs, line)){
		line = strip_punctuation(line);

		// Use an input string stream to extract the letters from line
		// istringstreams are a stream form of strings that allow
		// the use of the extraction operator <<
		istringstream issline(line);


		while(issline >> letter){

			// If we have not encountered the letter before, add it to the map
			// with a count of one
			if(letter_count_map.count(letter) == 0){
				letter_count_map[letter] = 1;
			} else {
				letter_count_map[letter] += 1;
			}
		}
	} // end of letter extraction procedure


	cout << endl << endl;
	for (auto &kv : letter_count_map){
		cout << kv.first << " occurred " << kv.second << " times." << endl;
	}
	cout << endl << endl;




	// Now, let's make a map that associates the number of times a letter occurred with
	// a vector of letters that occurred that many times
	map<int, vector<string>> occurrences;

	for (auto &kv : letter_count_map){
		if (occurrences.count(kv.second) == 0){
			occurrences[kv.second] = vector<string> {kv.first};
		} else {
			occurrences[kv.second].push_back(kv.first);
		}
	}


	for (auto &kv : occurrences){
		cout << "The letters that occurred " << kv.first << " times were: ";
		for (int i = 0; i < kv.second.size() - 1; i++){
			cout << kv.second[i] << ", ";
		}
		cout << kv.second[kv.second.size() - 1] << endl;
	}



	return 0;

}

// This is a possible implementation of stripping punctuation that ignores MANY edge cases,
// such as apostrophes in letters or hyphens in letters and ignores capitalization.
// You would need a more sophisticated implementation to deal with those cases.
// There are probably much easier implementations of this function,
// but this one demonstrates using string streams
string strip_punctuation(const string &line){
	istringstream input_line(line);
	ostringstream output_line;

	// A letter might include the punctuation
	string letter;
	while (input_line >> letter){
		// Make a new output string stream to hold the output letter
		ostringstream output_letter;
		for (char c : letter){
			// Only allow alphanumeric characters
			if (isalnum(c)){
				output_letter << char(tolower(c),'\0');
			}
		}

		// Convert the string stream to a string
		letter = output_letter.str();

		// This will result in an extra space at the end of the line, but it will not matter
		output_line << letter << " ";
	}

	return output_line.str();
}
