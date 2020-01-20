#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream> // To open file

using namespace std;

vector<int> process_line(string line); // To process each line

int main(int argc, char * argv[]){

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

	if(!ifs.is_open()){
		cout << "The file did not open!" << endl;
		return 0;
	}

	vector<vector<int>> data;
  vector<vector<int>> mat1;
  vector<vector<int>> mat2;


	string line;

	// Go through the file line by line, processing and then adding each row of doubles
	while(getline(ifs, line)){
    if(process_line(line).size() == 0){
      mat1 = data;
      data.clear();
    }
		data.push_back(process_line(line));
	}
  mat2 = data;

  for(int i = 0; i < mat1.size(); ++i){
    for(int j = 0; j < mat1[i].size(); ++j){
      cout << mat1[i][j] << " ";
    }
    cout << endl;
  }
   cout << endl;

   for(int i = 0; i < mat2.size(); ++i){
     for(int j = 0; j < mat2[i].size(); ++j){
       cout << mat2[i][j] << " ";
     }
     cout << endl;
   }

  return 0;

}

vector<int> process_line(string line){

	vector<int> entries;

	string built_double = "";

	for(int i = 0; i < line.size(); i++){

		if (line[i] == ' '){
			entries.push_back(stod(built_double));
			built_double = "";
		} else {
			built_double = built_double + line[i];
		}
	}

	entries.push_back(stod(built_double));

	return entries;
}
