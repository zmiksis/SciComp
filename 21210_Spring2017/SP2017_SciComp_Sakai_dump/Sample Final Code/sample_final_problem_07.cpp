// The solution is the function named "trace" defined near the bottom of the file

#include <iostream>
#include <vector>

// For string streams to simplify reading the matrix from a file
#include <sstream>


// For reading from (and writing to) files
#include <fstream>

using namespace std;

double trace(const vector<vector<double>> &A);

int main()
{

	ifstream input_file("sample_final_problem_07_example_matrix.dat");
	

	vector<vector<double>> matrix_A;

	// Used to read lines from the file into
	string line;
	// Variable used to store values read from the file temporarily
	double temp;
	// Keep getting new lines of data until unable
	while(getline(input_file, line)){
		
		vector<double> row;
		istringstream row_data(line);
		// Extract the row element by element

		while (row_data >> temp){
			row.push_back(temp);
		}
		
		// Add the row to A
		matrix_A.push_back(row);
	}
	
	cout << endl;
	cout << "The matrix A is: " << endl << endl;
	for (int i = 0; i < matrix_A.size(); i++){
		for (int j = 0; j < matrix_A[i].size(); j++){
			cout << matrix_A[i][j] << "\t";
		}
		cout << endl;
	}
		
	cout << endl;
	cout << "The trace of A is: " << trace(matrix_A) << endl << endl;


	return 0;
}


// Solution begins here
// Pass by constant reference to avoid a potentially expensive copy
double trace(const vector<vector<double>> &A){
	double total = 0.0;
	// Iterate over row numbers, summing the diagonal entries
	for (int i = 0; i < A.size(); i++){
		total += A[i][i];
	}
	return total;
}
