//#include <stdafx>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc == 1) {
		cout << "You did not enter any command line arguments!" << endl;
		return 0;
	}
	string file_name;
	for (int q = 0; q < argc - 1; q++) {
		file_name = argv[q + 1];
		cout << file_name << endl;
	}

	ifstream input_file;
	input_file.open(file_name);
	if (!input_file.is_open()) {
		cout << "The file could not be opened!" << endl;
		return 0;
	}

	string line;
	vector < vector<double> > matrix;
	while (getline(input_file, line)) {
		vector<double>temp_vector;
		string built_int = "";
		for (int i = 0; i < line.size(); i++) {
		if (all_of(line[i].begin(), line[i].end(), isspace)) {
				cout << stod(built_int) << endl;
				temp_vector.push_back(stod(built_int));
				built_int = "";
			}
			
			else {
				built_int = built_int + line[i];
			}
			
		}
	}
}