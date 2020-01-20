#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>


using namespace std;

vector<vector<double>> reader(string filename);
bool reduce_rows(vector<vector<double>> &A, int &ops);
vector<double> back_substitute(vector<vector<double>> &A, int &ops);

int main(int argc, char* argv[]){ 
	vector<vector<double>> LHS, RHS;
	vector<vector<double>> A; // Augmented matrix A
	vector<double> ans;
	int ops = 0;

    if (argc == 1){ // No input file was specified
        cout << "Error! You need to specify the input files for LHS and RHS matrices respectively.\nNow exiting.\n" << endl;
        return 0;
    }

    ofstream ANS_file("problem_4_solution.dat"); 

	if(!ANS_file.is_open()){ // If for any reason we can't open the output file
        cout << endl;
        cout << "Error! Unable to open the specified output file." << endl;
        return 0;
    }

	ANS_file.precision(4);
	ANS_file.setf(std::ios::fixed); 

    LHS = reader(argv[1]);
    RHS = reader(argv[2]);

    // Create the augmented matrix
    A = LHS;
    for (int i = 0; i < RHS.size(); i++){
    	double val = RHS[i][0]; // zeroth column of RHS (vector value)
    	A[i].push_back(val); // Augment the matrix
    }

  	// Gaussian row-reduction
  	if (!reduce_rows(A, ops)){
  		cout << "Error! The matrix is singular.\nNow exiting\n" << endl;
  		return 0;
  	}

    for (int i=0; i < A.size(); i++){
        for (int j=0; j < A[0].size(); j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n" << endl;

    cout << ops << endl;

  	// Solution via back-substitution
  	ans = back_substitute(A, ops);

  	// Recording results
  	for (int i=0; i < ans.size(); i++){
  		ANS_file << ans[i] << "\n";
  	}
  	ANS_file << endl;

  	ANS_file.close(); 

    // Reporting the number of operations
    cout << endl;
    cout << "Input matrix dimension: " << LHS.size() << ", and number of operations: " << ops << endl;
    cout << endl;

    return 0;
}

bool reduce_rows(vector<vector<double>> &A, int &ops){
	int numrows = A.size();
	int numcols = A[0].size();

    for (int dia=0; dia < numrows; dia++) {	

        // Check for maximum in this column        
        double maxNum = abs(A[dia][dia]); // Assume diagonal dominance
        int maxRow = dia;        
        for (int row=dia+1; row < numrows; row++) {
            if (abs(A[row][dia]) > maxNum) {
                maxNum = abs(A[row][dia]);
                maxRow = row;
            }
        }

        // Swap rows
        for (int col=dia; col < numcols; col++) {
            double tmp = A[maxRow][col];
            A[maxRow][col] = A[dia][col];
            A[dia][col] = tmp;
        }

        // Set all rows below this one 0 in current column
        for (int row=dia+1; row < numrows; row++) {
        	if (A[dia][dia] == 0){
        		cout << "Error! The Matrix is singular!" << endl;
        		return false;
        	}else{
	            double ratio = A[row][dia]/A[dia][dia];
	            ops += 1;
	            for (int col=dia; col < numcols; col++) {
	            	if (dia==col) {
	                    A[row][col] = 0;
	                } else {
	            		A[row][col] -= ratio * A[dia][col];
	            		ops += 2;
	            	}
	            }
        	}
        }
    }
    return true;
}

vector<double> back_substitute(vector<vector<double>> &A, int &ops){
	int numrows = A.size();
	vector<double> results(numrows);
	for (int row=numrows-1; row >= 0; row--){
		results[row] = A[row][numrows]/A[row][row];
		ops += 1;
		for (int prevrow=row-1; prevrow >= 0; prevrow--){
			A[prevrow][numrows] -= A[prevrow][row] * results[row];
			ops += 2;
		}
	}
	return results;
}

vector<vector<double>> reader(string filename){
	ifstream file_handle(filename);

    if (!file_handle.is_open()){ // If for any reason we can't open the input file
    	cout << endl;
        cout << "Error: Could not open at least one of the input files!\n" << endl;
    }	

	vector<vector<double>> mat;

	string line; // This line variable will hold the data for each line in our input file

    while(getline(file_handle, line)){
    	if (!line.empty()){
    		istringstream linedata(line);
    		vector<double> vec;
    		string num;

    		while(!linedata.eof()){
    			linedata >> num;
    			vec.push_back(stod(num));
    		}

    		mat.push_back(vec);
    	}    	
    }

    file_handle.close(); 
    
    return mat;
}

