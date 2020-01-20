#include <iostream>  // Needed for console input/output (I/O) operations
#include <string> // Needed for string data to be data read from input file
#include <fstream>  // Need the file stream for file I/O operations
#include <sstream>  // Need the string stream library, to read the parts of a line
#include <vector> // For storing the savings data
#include <iomanip> // For setting precision of the result in the output file

using namespace std;

int main(int argc, char* argv[]){

    if (argc < 3){
        cout << "Error! You did not specify two input files in the command line argument.\nNow exiting.\n" << endl;
        return 0;
    }

    ifstream input_file(argv[1]);  // Get the name of the first input file from command line
    ifstream input_file2(argv[2]);  // Get the name of the second input file from command line

    if (!input_file.is_open() || !input_file2.is_open()){
        cout << "Error: input data files could not be opened.\nNow exiting.\n" << endl;
        return 0;
    }

    ofstream output_file("mcdonalds_output.dat");  // We have a fixed name for the output file

    if(!output_file.is_open()){ // If for any reason we can't open the output file
        cout << endl;
        cout << "Error! Unable to create the specified output file (mcdonalds_output.dat)." << endl;
        return 0;
    }

    string line;  // This line variable will hold the data for each line in our input file
    vector<double> savings;

    while (getline(input_file, line)){  // Read each line from the input file 1
    	if (!line.empty()){ // Check if this is NOT an entirely blank line anywhere in the file?	
    		istringstream linedata(line); // Feed that line INTO a string-stream called linedata. Now we can read through the line.

    		string name; // Name of the worker 
    		getline(linedata, name, '|'); // Get the worker name string UNTIL a pipe char is reached   		
    		
    		double num; // Savings data to be read from file
    		char delim; // Data delimiter (in this case it is a pipe i.e. |)
    		double linetotal = 0.0; // Total amount saved, for that line

    		// Read as many doubles as are on the line
    		while(!linedata.eof()){ // While not yet at the end of the line, and there is still data to read
    			linedata >> num >> delim; // Receive the savings data and the delimiter
    			linetotal += num; // Add the number to the total
    		}

    		// Save the line total into the savings vector
    		savings.push_back(linetotal);
    	}    	
    }

	if (input_file.eof()){ // We reached the end of the savings file
		cout << "Finished reading the savings data file." << endl;
	}else if (!input_file.good()){
		cout << "Error: something went wrong with the weekly savings data file!" << endl;
	}

	input_file.close(); // We are done with the first input file, so we close it.

    int linecount = 0; // The line count will refer to each worker by number, starting from zero (same index as savings vector)
    while (getline(input_file2, line)){  // Read each line from the input file 2
    	if (!line.empty()){ // Check if this is NOT an entirely blank line anywhere in the file?
    		istringstream linedata(line); // Feed that line INTO a string-stream called linedata. Now we can read through the line.

    		string name; // Name of the worker
    		getline(linedata, name, '|'); // Get the worker name string UNTIL a pipe is reached

    		int hours; // Number of hours to be read from file
    		double rate, saved; // Hourly wage data to be read from file
    		char delim; // Data delimiter (in this case it is a pipe i.e. |)

    		linedata >> hours >> delim >> rate >> delim >> saved; // Receive the rest of the data
    		if (saved != savings[linecount]){ // Does the amount in the report match the savings for this worker?
    			cout << "Error! An amount in the report does not match the savings data.\nNow exiting." << endl;
    			input_file2.close(); output_file.close(); // Even though we are aborting the process, it is neater to close the files
    			return 0;
    		}else{
    			double earned = rate * hours;
    			output_file << fixed << setprecision(2); // Set two decimal places
    			output_file << name << " earns $" << earned << " per week, and saves " << (saved/earned)*100 << "% of it." << "\n";
    			linecount++; // Increment the line count
    		}
    	}    	
    }   

    if (input_file2.eof()){ // We are at the end of the reports file
        cout << "Finished reading the reports file. Output written successfully." << endl;
    }else if (!input_file2.good() || !output_file.good()) {
        cout << "Error: something went wrong with the reports file or the output file!" << endl;
    }

    // Close the input 2 and output files
    input_file2.close();
    output_file.close();

    return 0;           
}