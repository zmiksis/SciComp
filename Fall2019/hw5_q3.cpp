#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include <bits/stdc++.h>

using namespace std;

vector<string> process_line(string line);

int main(int argc, char * argv[]){

  vector<char> alphabet{'A','B','C'};
  vector<int> alphacount(3,0);

  if(argc == 1){
    cout << "You did not enter any file names!" << '\n';
    return 0;
  }

  for(int i = 1; i < argc; i++){

    vector<vector<string>> file_lines;

    string file_name = argv[i];
    ifstream ifs;
    ifs.open(file_name);

    string line;
    while(getline(ifs,line)){
      file_lines.push_back(process_line(line));
    }
    ifs.close();
    ifs.clear();

    for(int j = 0; j < file_lines.size(); j++){
      for(int k = 0; k < file_lines[i].size(); k++){
        // Convert all letters to upper case
        transform(file_lines[j][k].begin(), file_lines[j][k].end(), file_lines[j][k].begin(), ::toupper);
        for(int n = 0; n < file_lines[j][k].size(); n++){
          for(int m = 0; m < alphabet.size(); m++){
            if(file_lines[j][k][n] == alphabet[m]){
              alphacount[m]++;
            }
          }
        }
      }
    }

  }

  for(int i = 0; i < alphabet.size(); i++){
    cout << alphabet[i] << ": " << alphacount[i] << '\n';
  }

  return 0;

}

vector<string> process_line(string line){
        // Create a new input string stream, opening up the string line to use
        istringstream iss(line);

        string elem;

        vector<string> processed_line;


        // use getline to get a "line" from the stream, delimited by the comma character
        while(getline(iss,elem, ' ')){
                processed_line.push_back(elem);
        }

        return processed_line;
}
