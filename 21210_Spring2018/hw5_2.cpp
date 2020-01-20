#include <iostream>  // Needed for console input/output (I/O) operations
#include <string> // Needed because data read from a file is naturally a string
#include <fstream>  // Need the file stream for file I/O operations
#include <sstream>  // Need the string stream library, to read the parts of a line

using namespace std;

int main(int argc, char* argv[]){
	
    if (argc == 1){
        cout << "Error! You did not specify a data file name in the command line argument.\nNow exiting.\n" << endl;
        return 0;
    }

    ifstream input_file(argv[1]);  // Get the name of the input file from command line

    if (!input_file.is_open()){
        cout << "Error: data file could not be opened.\nNow exiting.\n" << endl;
        return 0;
    }

    ofstream output_file("hw_5_ex_2_output.dat");  // We have a fixed name for the output file

    if(!output_file.is_open()){ // If for any reason we can't open the output file
        cout << endl;
        cout << "Error! Unable to create the specified output file." << endl;
        return 0;
    }

    string line;  // This line variable will hold the data for each line in our input file

    while (getline(input_file, line)){  // Read each line from the input file
    	if (!line.empty()){ // Have we reached an entirely blank line?
    		int linetotal = 0;
    		
    		istringstream linedata(line); // Feed that line into a string-stream called linedata
    		int numdata; // Numerical data
    		char delim; // Delimiter (semi-colon)
    		while(!linedata.eof()){ // While not yet at the end of the line, and there is still data to read
    			linedata >> numdata >> delim; // Eat the input number and the delimiter
    			linetotal += numdata; // Add the number
    		}
    		output_file << linetotal << "\n"; // Type the line total into the output file
    	}    	
    }

    if (input_file.eof()){
        cout << endl;
        cout << "Data file read and written successfully." << endl;
        cout << endl;
    }else if (!input_file.good() || !output_file.good()) {
        cout << "Something went wrong with the input or output file!" << endl;
    }

    input_file.close();
    output_file.close();    
    return 0;
}