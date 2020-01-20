// This program uses both an ifstream to obtain input into our program
// and an ofstream to output values from our program.

// We will open a file, reading in the values one by one
// and output to another file only those values that are strictly positive.

#include <iostream>
#include <fstream>

using namespace std;


int main(){

	ifstream ifs("ex_078_data.dat");

	if (!ifs.is_open()){
		cout << "The input file could not be opened!" << endl;
		return 0;
	}
	
	ofstream ofs("ex_078_output.dat");

	if (!ofs.is_open()){
		cout << "The output file could not be opened!" << endl;
		ifs.close();
		return 0;
	}

	double x;
	while (ifs >> x){
		// Only keep the positive entries		
		if (x > 0) {
			// Remember that using '\n' rather than endl does not flush the buffer/write to the disk
			// If you left out any kind of end of line, you would find that the outputs would all run together on one line
			ofs << x << '\n';
		}
	}

	ifs.close();

	// Closing an ofs automatically flushes the buffer
	ofs.close();

	return 0;
}
