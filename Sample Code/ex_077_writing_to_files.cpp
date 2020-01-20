#include <iostream>
#include <fstream>

using namespace std;


int main(){

	ofstream ofs;

	// Will create the file if it does not exist
	// Otherwise, it will open the file for writing AT THE BEGINNING.
	// When you next write to the file, you will overwrite any existing contents.
	// It is possible to append to a file or seek to arbitrary places in a file,
	// but we will not need them in this course.
	ofs.open("ex_077_data.dat");
	
	// This is not likely to fail
	if(!ofs.is_open()){
		cout << "The file failed to open!" << endl;
		return 0;
	}

	// Write the squares of the integers from 0 to 9 inclusive to the file
	// with one integer per line
	for(int i = 0; i < 5; i++){	
		ofs << i * i << '\n'; 
		// You could also use endl instead, but endl will flush the buffer and execute a write to the disk
		// It may be better to hold off on this until later, since disk access is generally much slower than memory.
		// However, if the program encounters an error and closes before flushing the buffer, some data
		// may not be written to the file.
	}

	// Deliberately flushes the buffer and forces a disk write.
	ofs << flush;

	// Should always close files when done with them. This will force a write to the disk. 
	// You can also flush the buffer and force a write to the disk with flush, as in the next line
	// ofs << flush;
	// If the buffer has not been flushed, and your program encounters an error before flushing the buffer,
	// the contents of the buffer will not be written to your file.
	ofs.close();

	return 0;
}
