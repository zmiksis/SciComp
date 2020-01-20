// In this program, we will store double values taken from a file
// where each line of the file contains doubles separated by commas.
// However, we will not assume that the user knows how many doubles are in a line
// in the file, and will have to figure it out.

// We assume each line consists of doubles, separated by commas, and no other characters.

// To store the doubles, we will use a vector of vectors of doubles.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;


// You could improve performance by modifying a vector<double> passed by reference
// instead of returning one, to avoid making a copy along the way
vector<double> process_line(string line);
void print_vector_of_vectors(const vector<vector<double>> &d);

int main(){
	
	// Define an input stream and open a file
	ifstream ifs("ex_074_data.dat");

	if(!ifs.is_open()){
		cout << "The file did not open!" << endl;
		return 0;
	}

	vector<vector<double>> data;
	
	string line;

	// Go through the file line by line, processing and then adding each row of doubles
	while(getline(ifs, line)){
		data.push_back(process_line(line));
	}

	cout << endl;
	print_vector_of_vectors(data);
	cout << endl;

	ifs.close();

	return 0;
}

// Avoid using the following function, as 
// there are better ways to do this!
// One way is to use an istringstream (input string stream),
// which is present in the upcoming sample code.
vector<double> process_line(string line){

	// Store the entries in a given line in a vector of doubles
	// that we will add to, one at a time
	vector<double> entries;
	
	// Start out building the double from an empty string and adding characters as they are encountered
	string built_double = "";
	

	// Iterate over all characters in the line
	// You can use the .size() function to find the length of a string
	// and access the characters in a string using []
	for(int i = 0; i < line.size(); i++){

		// Any time you encounter a comma, you have reached the end of the current double
		if (line[i] == ','){
			// Convert the string, whose contents are the double in question, to a double
			// using the stod function
			entries.push_back(stod(built_double));
			// Reset the double you are building to an empty state to build a new one
			built_double = "";
		} else {
			// If you have yet to reach a comma, you can still build
			built_double = built_double + line[i];
		}
	}

	// Add the last double, which does not have a comma following it
	entries.push_back(stod(built_double));
	
	return entries;
}


// When dealing with vectors of vectors, you might want to consider using a 'typedef' to create an alias
// for the type
void print_vector_of_vectors(const vector<vector<double>> &d){
	// i is the row index
	for(int i = 0; i < d.size(); i++){
		// j is the colum index
		for(int j = 0; j < d[i].size(); j++){
			cout << d[i][j] << '\t';
		}
		cout << endl;
	}
	return;
}
