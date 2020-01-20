// This program uses both an ifstream to obtain input into our program
// and an ofstream to output values from our program.

// We will open a file, reading in the values one by one
// and output to another file only those values that are strictly positive.

#include <iostream>
#include <fstream>

using namespace std;


int main(){

	ifstream input_file("ex_065_data.dat");

	if (!input_file.is_open()){
		cout << "The input file could not be opened!" << endl;
		return 0;
	}
	
	ofstream output_file("ex_065_output.dat");

	if (!output_file.is_open()){
		cout << "The output file could not be opened!" << endl;
		input_file.close();
		return 0;
	}

	double x;
	while (input_file >> x){
		// Only keep the positive entries		
		if (x > 0) {
			// Remember that using '\n' rather than endl does not flush the buffer/write to the disk
			// If you left out any kind of end of line, you would find that the outputs would all run together on one line
			output_file << x << '\n';
		}
	}

	input_file.close();

	// Closing an output_file automatically flushes the buffer
	output_file.close();

	return 0;
}
