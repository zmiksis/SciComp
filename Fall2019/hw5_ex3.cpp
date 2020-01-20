#include <iostream>
#include <string>
#include <vector>
#include <cctype> // For toupper function
#include <sstream>
#include <fstream>
#include <bits/stdc++.h> // For transform function

using namespace std;

vector<string> process_line(string line);

int main(int argc, char * argv[]){

  vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  vector<int> alphcount(26,0);

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

    for(int i = 0; i < file_lines.size(); i++){
      for(int j = 0; j < file_lines[i].size(); j++){
        transform(file_lines[i][j].begin(), file_lines[i][j].end(), file_lines[i][j].begin(), ::toupper); // Change all to upper
        for(int k = 0; k < file_lines[i][j].size(); k++){
          for(int n = 0; n < alphabet.size(); n++){
            if(file_lines[i][j][k] == alphabet[n]){
              alphcount[n]++;
            }
          }
        }
      }
    }

  }

  double total = 0;
  for(int i = 0; i < alphcount.size(); i++){
    total += alphcount[i];
  }
  for(int i = 0; i < alphabet.size(); i++){
    cout << alphabet[i] << ": " << alphcount[i] << "    " << 100*alphcount[i]/total << '\n';
  }

  return 0;

}


vector<string> process_line(string line){
        // Create a new input string stream, opening up the string line to use
        istringstream iss(line);

        string elem;

        vector<string> processed_line;


        // use getline to get a "line" from the stream, delimited by the comma character
        while(getline(iss,elem,' ')){
                processed_line.push_back(elem);
        }

        return processed_line;
}
