#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream> // To open file

using namespace std;

vector<int> process_line(string line);

int main(int argc, char * argv[]){ // argc = # of arguments, argv = vector of aguments

  // Check input
  if (argc == 1){
		cout << "You did not enter any file names!" << endl;
		return 0;
	}

  // Open file
  string file_name = argv[1];
  ifstream ifs;
  ifs.close();
	ifs.clear();
  ifs.open(file_name);

  vector<vector<int>> data;

	string line;

	// Go through the file line by line, processing and then adding each row of doubles
	while(getline(ifs, line)){
		data.push_back(process_line(line));
	}

  ifs.close();
	ifs.clear();

  vector<int> sums(data.size());
  for(int i = 0; i < sums.size(); ++i){
    sums[i] = 0;
  }

  for(int i = 0; i < data.size(); ++i){
    for(int j = 0; j < data[i].size(); ++j){
      sums[i] += data[i][j];
    }
  }

  ofstream ofs;

  ofs.open("q2_output.dat");

  if(!ofs.is_open()){
		cout << "The file failed to open!" << endl;
		return 0;
	}

  for(int i = 0; i < sums.size(); ++i){
    ofs << sums[i] << '\n';
  }

  ofs << flush;
  ofs.close();

  return 0;
}

vector<int> process_line(string line){

	vector<int> entries;

	string built_double = "";

	for(int i = 0; i < line.size(); i++){

		if (line[i] == ';'){
			entries.push_back(stod(built_double));
			built_double = "";
		} else {
			built_double = built_double + line[i];
		}
	}

	entries.push_back(stod(built_double));

	return entries;
}
