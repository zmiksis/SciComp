#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream> 
#include <algorithm>
#include "student.h"

using namespace std;

int main(){

	ifstream input_file;
	input_file.open("student_data.dat");

	if (!input_file.is_open()){
		cout << "Error: data file could not be opened.\nNow exiting.\n" << endl;
		return 0;
	}

	vector<string> firstnames;
	vector<string> lastnames;
	vector<vector<int>> homeworks;
	vector<vector<int>> exams;
	vector<int> finalexams;

	while(!input_file.eof()){
		string line;
		int linenumber = 0;

		while(getline(input_file, line)){
			if (line.empty()){
				linenumber = 0;
			}else{				
				istringstream linedata(line);

				linenumber++;
				vector<int> scorerow;
		
				while(!linedata.eof()) {
					if (linenumber == 1){
						string fname, lname;		
						linedata >> fname >> lname;
						if (!fname.empty() && !lname.empty()){
							firstnames.push_back(fname);
							lastnames.push_back(lname);
						}
					}else{
						int data;
						linedata >> data;
						if (data >= 0){					
							if (linenumber == 4) finalexams.push_back(data);
							if (linenumber != 4) scorerow.push_back(data);						
						}	
					}
				}
				if (linenumber == 2) homeworks.push_back(scorerow);
				if (linenumber == 3) exams.push_back(scorerow);		
			}
		}
	}

	cout << endl;

	if (input_file.eof()){ 
		if (firstnames.empty() || lastnames.empty() || homeworks.empty() || exams.empty() || finalexams.empty()){
			cout << "Something is wrong. Input file was read, but the matrices and vectors are empty. Check your input files!" << endl;
		}else{
            // Vectors and matrices are not empty. Hurray.
            cout << "Data file read successfully. End of data file successfully reached." << endl;
            cout << endl;        
        }
	}else if (!input_file.good()) { // The input file was not properly read.
        cout << "Something went wrong! The input file could be properly read." << endl;
        return 0;
    }

    input_file.close(); // Close the input file

	int num = firstnames.size();   // Number of students in file

    // Create and sort permutation vector
    vector<int> order;
    for (int i=0; i < num; i++){ // Use std::iota for this
    	order.push_back(i);
    }

    auto comparator = [&lastnames](int a, int b){
    	return (lastnames[a] < lastnames[b]);
    };

    sort(order.begin(), order.end(), comparator);
    // End sorting permutation vector   

    // Go student by student in each matrix
    for (int j=0; j < num; j++){
    	int i = order[j]; // Index based on permutation vector

    	Student stu = {firstnames[i], lastnames[i], homeworks[i], exams[i], finalexams[i]};  	

    	string fullname = stu.get_full_name();
    	float result = stu.get_final_grade();    	

    	cout << fullname << ": " << setprecision(4) << result << "%" << endl;
    }

    return 0;
}