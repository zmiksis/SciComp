#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char * argv[]){

  string encrypted_file = argv[1];
  string key_file = argv[2];

  ifstream ifs;
  ifs.open(key_file);

  map<string, string> key_map;
  string line;
  while(getline(ifs,line)){
    istringstream iss(line);
    string elem1, elem2;
    getline(iss,elem1,' ');
    getline(iss,elem2,' ');
    key_map[elem1] = elem2;
  }
  key_map[" "] = " ";
  key_map["\n"] = "\n";

  ifs.close();
  ifs.clear();

  ifs.open(encrypted_file);
  char c;
  while(ifs.get(c)){
    string s(1,c);
    cout << key_map[s];
  }

  return 0;
}
