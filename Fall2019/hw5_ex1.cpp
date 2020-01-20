#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> process_line(string line);

int main(int argc, char * argv[]){

  if(argc == 1){
    cout << "You did not enter any file names!" << '\n';
    return 0;
  }

  string file_name = argv[1];
  ifstream ifs;
  ifs.open(file_name);

  vector<vector<int>> data;

  string line;
  while(getline(ifs,line)){
    data.push_back(process_line(line));
  }
  ifs.close();
  ifs.clear();

  vector<int> sums;
  for(int i = 0; i < data.size(); i++){
    sums.push_back(0);
    for(int j = 0; j < data[i].size(); j++){
      sums[i] += data[i][j];
    }
  }

  ofstream ofs;
  ofs.open("ex1_output.dat");
  if(!ofs.is_open()){
    cout << "The file failed to open!" << '\n';
    return 0;
  }
  for(int i = 0; i < sums.size(); i++){
    ofs << sums[i] << '\n';
  }
  ofs << flush;
  ofs.close();

  return 0;

}

vector<int> process_line(string line){
        // Create a new input string stream, opening up the string line to use
        istringstream iss(line);

        string elem;

        vector<int> processed_line;


        // use getline to get a "line" from the stream, delimited by the comma character
        while(getline(iss,elem, ';')){
                processed_line.push_back(stod(elem));
        }

        return processed_line;
}
