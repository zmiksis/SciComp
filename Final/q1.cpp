#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<int> read_line(string line);
vector<vector<int>> read_palindromes(ifstream &ifs, string filename);
bool compare(vector<int> &data, int value);

int main(int argc, char* argv[]){

  vector<int> palindromes;

  if(argc == 1){
    cout << "You did not enter any file names!" << endl;
    return 0;
  } else{

    ifstream ifs;

    string filename;
    for(int i = 1; i < argc; ++i){

      filename = argv[i];
      vector<vector<int>>temp_palindromes = read_palindromes(ifs, filename);

      for(int i = 0; i < temp_palindromes.size(); ++i){
        for(int j = 0; j < temp_palindromes[i].size(); ++j){
          palindromes.push_back(temp_palindromes[i][j]);
        }
      }

      temp_palindromes.clear();
    }

  }

  cout << "There are " << palindromes.size() << " palindromes."<< endl;

  vector<int> distinct_palindromes;
  for(int i = 0; i < palindromes.size(); ++i){
    if(compare(distinct_palindromes,palindromes[i]) == false)
      distinct_palindromes.push_back(palindromes[i]);
  }

  cout << "There are " << distinct_palindromes.size() << " distinct palindromes."<< endl;

  return 0;

}

bool compare(vector<int> &data, int value){

  bool duplicate = false;
  for(int i = 0; i < data.size(); ++i){
    if(value == data[i]){
      duplicate = true;
    }
  }

  return duplicate;
}

vector<vector<int>> read_palindromes(ifstream &ifs, string filename){

  ifs.close();
  ifs.clear();
  ifs.open(filename);

  vector<vector<int>> palindromes;

  if(!ifs.is_open()){
    cout << "The file could not be opened!" << endl;
    return palindromes;
  }

  string line;
  while(getline(ifs,line)){
    palindromes.push_back(read_line(line));
  }

  return palindromes;
}

vector<int> read_line(string line){

  vector<int> palindromes;

  string built_palindrome = "";
  string temp_palindrome;

  for(int i = 0; i < line.size(); ++i){

    if(line[i] == ' '){
      temp_palindrome = built_palindrome;
      reverse(temp_palindrome.begin(),temp_palindrome.end());
      if(temp_palindrome == built_palindrome && built_palindrome.size() != 0)
        palindromes.push_back(stoi(built_palindrome));
      built_palindrome = "";
    } else{
    built_palindrome = built_palindrome + line[i];
    }
  }

  temp_palindrome = built_palindrome;
  reverse(temp_palindrome.begin(),temp_palindrome.end());
  if(temp_palindrome == built_palindrome && built_palindrome.size() != 0)
    palindromes.push_back(stoi(built_palindrome));

  return palindromes;
}
