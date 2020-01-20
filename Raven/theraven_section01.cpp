#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

void print_file_contents(ifstream &ifs, string file_name);

// ./executable theraven #of verses
int main(int argc, char* argv[]){
  if(argc == 1) //first check
  {
      cout << "You didn't enter any file names!" << endl;
      return 0;
  }

  string title = argv[1];
  int verses = stoi(argv[2]);
  string response;
  int count = 0;
  cout << "Do you want to print the next verse? Enter y for yes and n for no: ";
  cin >> response;
  vector<string> file_names(verses);
  for(int i = 0; i < file_names.size(); ++i){
    file_names[i] = title + to_string(i+1) + ".txt";
  }
  ifstream ifs;

  while (response == "y" || response == "n"){
    if (count < file_names.size()) {
      print_file_contents(ifs, file_names[count]);
      cout << "Print next verse? y/n: ";
      cin >> response;
      count ++;
    } else {
        break;
    }
  }
  return 0;
}

// You should usually pass streams by reference
void print_file_contents(ifstream &ifs, string file_name){
	ifs.close();
	ifs.clear();
	ifs.open(file_name);

	if (!	ifs.is_open()){
		cout << endl << "Could not open the file " << file_name << endl << endl;
		return;
	}

	cout << endl << "Now printing the verse..."<< endl << endl;

	string line;

	while( getline(ifs, line) ){
		cout << line << endl;
	}
	cout << endl;

	ifs.close();
	ifs.clear();

	return;
}
