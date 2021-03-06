// This program takes a command line argument specifying the precision to which to write the values in the vector v to a file

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


// iomanip will allow you to set the precision for your doubles
#include <iomanip>


using namespace std;


int main(int argc, char* argv[]){

	int desired_precision;
	
	if (argc == 1){
		desired_precision = 12;
	} else {
		desired_precision = stoi(argv[1]);
	}

	// v will have length 50 and v[i] will be e to the ith power
	vector<double> v(50);
	for (int i = 0; i < v.size(); i++){
		v[i] = exp(i);
	}


	ofstream output_file;

	output_file.open("ex_066_output.dat");
	if (!output_file.is_open()){
		cout << "The output file failed to open!" << endl;
		return 0;
	}
	
	// Set the output_file to use the desired precision, and to use a fixed width for doubles
	output_file << setprecision(desired_precision);
	
	for (double elem : v){
		output_file << elem << '\n';
	}

	output_file.close();

	return 0;
}
