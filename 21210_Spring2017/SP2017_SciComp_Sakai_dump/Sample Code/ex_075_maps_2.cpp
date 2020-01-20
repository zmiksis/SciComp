// This is an unsophisticated implementation of using a map to count the number of words that appear in a document.
// The program takes a single command line argument, the name of a single file, to read the words from.

// The program leaves out many features such a program would probably want.
// For example, you would probably want to leave apostrophes intact for
// words like "you're" but might want to remove them and the trailing letter 's' for possessive words
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
	
	ifstream input_file(argv[1]);

	// Create a map that will store the count of each word that appears
	map<string, int> word_count_map;
	
	// Store each line of the input file in a string called line	
	string line;

	// Store each word from a given line in a string called word
	string word;

	while(getline(input_file, line)){
		line = strip_punctuation(line);
		
		// Use an input string stream to extract the words from line
		// istringstreams are a stream form of strings that allow
		// the use of the extraction operator <<
		istringstream issline(line);
		


		while(issline >> word){
			
			// If we have not encountered the word before, add it to the map
			// with a count of one
			if(word_count_map.count(word) == 0){
				word_count_map[word] = 1;
			} else {
				word_count_map[word] += 1;
			} 
		} 
	} // end of word extraction procedure


	cout << endl << endl;
	for (auto &kv : word_count_map){
		cout << kv.first << " occurred " << kv.second << " times." << endl;
	}
	cout << endl << endl;
	

	// Now, let's make a map that associates the number of times a word occurred with
	// a vector of words that occurred that many times
	map<int, vector<string>> occurrences;

	for (auto &kv : word_count_map){
		if (occurrences.count(kv.second) == 0){
			occurrences[kv.second] = vector<string> {kv.first};
		} else {
			occurrences[kv.second].push_back(kv.first);
		}
	}


	for (auto &kv : occurrences){
		cout << "The words that occurred " << kv.first << " times were: ";
		for (int i = 0; i < kv.second.size() - 1; i++){
			cout << kv.second[i] << ", ";
		}
		cout << kv.second[kv.second.size() - 1] << endl;
	} 
			
	return 0;

}

// This is a possible implementation of stripping punctuation that ignores MANY edge cases,
// such as apostrophes in words or hyphens in words and ignores capitalization.
// You would need a more sophisticated implementation to deal with those cases.
// There are probably much easier implementations of this function,
// but this one demonstrates using string streams
string strip_punctuation(const string &line){
	istringstream input_line(line);
	ostringstream output_line;

	
	string word;
	while (input_line >> word){
		// Make a new output string stream to hold the output word
		ostringstream output_word;
		for (char c : word){
			// Only allow alphanumeric characters
			if (isalnum(c)){
				output_word << char(tolower(c));
			}
		}
		
		// Convert the string stream to a string
		word = output_word.str();
		
		// This will result in an extra space at the end of the line, but it will not matter
		output_line << word << " ";
	}
	
	return output_line.str();
}
