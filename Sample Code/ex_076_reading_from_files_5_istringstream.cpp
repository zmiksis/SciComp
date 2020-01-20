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


// Need to include isstream to use string streams
#include <sstream>

// Use for isalnum function
#include <cctype>


using namespace std;


// You could improve performance by modifying a vector<double> passed by reference
// instead of returning one, to avoid making a copy along the way
vector<double> process_line(string line);
void print_vector_of_vectors(const vector<vector<double>> &d);

int main(){
	
	// Define an input stream and open a file
	ifstream ifs("ex_076_data.dat");

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


// There are better ways to do this!
// One way is to use an istringstream (input string stream)
vector<double> process_line(string line){
	// Create a new input string stream, opening up the string line to use
	istringstream iss(line);

	string elem;

	vector<double> processed_line;


	// use getline to get a "line" from the stream, delimited by the comma character
	while(getline(iss,elem, ',')){
		processed_line.push_back(stod(elem));
	}
	
	return processed_line; 
}


// When dealing with vectors of vectors, you might want to consider using a 'typedef' to create an alias
// for the type
void print_vector_of_vectors(const vector<vector<double>> &d){
	for(int i = 0; i < d.size(); i++){
		for(int j = 0; j < d[i].size(); j++){
			cout << d[i][j] << '\t';
		}
		cout << endl;
	}
	return;
}
