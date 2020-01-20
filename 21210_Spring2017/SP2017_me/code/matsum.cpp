// We want to sum two matrices.
// The "array" data container (to be studied later) may help simplify this code.

#include <iostream> // Needed for console input/output (I/O) operations
#include <string> // Needed because we will manipulate strings
#include <vector> // Matrices will be stored as vectors made up of vectors
#include <fstream> // Need the file stream for file I/O operations
#include <sstream> // Need the string stream library, to read the parts of a line

using namespace std;

int main(int argc, char* argv[]){ // We will pass a total of argc command line arguments, with values argv[]
// In our case, only the input file will be passed, so argc = 2 
// because the first argument is the name of the C++ file being compiled

    vector<vector<int>> matrixA; // define a vector made up of vectors. Inner vectors are "rows"
    vector<vector<int>> matrixB; // and the outer vectors storing them are a "column" of those "rows"

    if (argc == 1){ // No input file was specified
        cout << "Error! You did not specify a data file name in the command line argument.\nNow exiting.\n" << endl;
        return 0;
    }

    ifstream input_file(argv[1]); // Get the name of the input file from command line
    ofstream output_file("problem_4_solution.dat"); // We have a fixed name for the output file

    if (!input_file.is_open()){ // If for any reason we can't open the input file
        cout << "Error: data file could not be opened.\nNow exiting.\n" << endl;
        return 0;
    }

    if(!output_file.is_open()){ // If for any reason we can't open the output file
        cout << endl;
        cout << "Error! Unable to create the specified output file." << endl;
        return 0;
    }    

    string line; // This line variable will hold the data for each line in our input file

    bool firstmatrix = true; // Are we reading the first matrix?
    // This variable firstmatrix helps prevent writing two loops to read each matrix.
    // You may do that instead, if you like.

    // We will use getline to fetch each line from the input file
    while(getline(input_file, line)){ // Read each line from the input file
        if (line.empty()){ // Have we reached an entirely blank line? This is the separation line.
            firstmatrix = false; // If so, then we will begin reading the second matrix on the next iteration.
        }else{
            istringstream linedata(line); // Feed that line into a string-stream called linedata

            vector<int> row; // Define row as a Matrix Row
            string num;    // Each number to be read on that Matrix Row

            while(!linedata.eof()) { // While not yet at the end of the line, and there is still data to read
                linedata >> num; //Fetch each number in this current line
                if (!num.empty()){ // Hopefully this wasn't a space, tab or newline or another kind of whitespace?
                    row.push_back(stoi(num)); // Convert to integer, then store the number in the matrix row                   
                }               
            }

            // We have data in the rows, to be pushed into the vector of vectors, i.e. matrix
            if (firstmatrix == true){
                matrixA.push_back(row); // We're in A. Store the entire row into A
            }else{
                matrixB.push_back(row); // We're in B. Store the entire row into B
            }       
        }
    }

    cout << endl; // Just for visuals

    if (input_file.eof()){     // Have we reached the end of the input file?    
        if (matrixA.empty() || matrixB.empty()){ // After reading the file, we check if our matrices are empty
            cout << "Both matrices are empty! Check the input file, ensure first line isn't blank." << endl;
            return 0;
        }else{
            // Matrices are not empty. Hurray.
            cout << "Data file read successfully. End of data file successfully reached." << endl;
            cout << endl;        
        }
    }else if (!input_file.good()) { // The input file was not properly read.
        cout << "Something went wrong! The input file could be properly read." << endl;
        return 0;
    }

    input_file.close(); // Close the input file

    int rows = matrixA.size();   // Number of rows will be the size of matrixA
    int cols = matrixA[0].size(); // Number of cols will be the size of each row in matrixA  

    for (int i=0; i < rows;  i++){ // Go row by row in each matrix
        vector<int> rowA = matrixA[i]; // Matrix A row
        vector<int> rowB = matrixB[i]; // Matrix B row

        for (int j=0; j < cols; j++){ // Go column by column
            output_file << rowA[j] + rowB[j]; // Sum components and print each sum in a column within the row
            if (j != cols-1) { output_file << " ";} // add a space if it's not yet the end of the line
        }
        output_file << "\n"; // Row is done. Now add a line break to advance to the next row.
    };

    cout << "Matrices have been summed and printed into file: problem_4_solution.dat" << endl;

    return 0;
}