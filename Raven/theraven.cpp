#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void print_file_contents(ifstream &ifs, string file_name);

int main(int argc, char * argv[]){

	if (argc == 1){
		cout << "You did not enter any file names!" << endl;
		return 0;
	}

  string title = argv[1];
  int verses = stoi(argv[2]);

  ifstream ifs;

  vector<string> file_names(verses);
  for(int i = 0; i < file_names.size(); ++i){
    file_names[i] = title + to_string(i+1) + ".txt";
  }

  {
    string temp;
    cout << "Print first verse (y/n)? ";
    cin >> temp;
    for(int i = 0; i < verses; ++i){
      while(temp != "n" && temp != "y"){
        cout << "Please enter y/n...";
        cin >> temp;
      }
      if(temp == "n"){
        break;
      }
      print_file_contents(ifs, file_names[i]);
      if(i != verses-1){
        cout << "Print next verse (y/n)? ";
        cin >> temp;
      }
      //cin.get();
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
