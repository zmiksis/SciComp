#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void print_file_contents(ifstream &ifs, string file_name);

int main(int argc, char* argv[])
{
	if (argc == 1) {
		cout << "You did not enter any command line arguments!" << endl;
		return 0;
	}
	string title = argv[1];
	vector<string> file_names(stoi(argv[2]));
	for (int i=0; i< file_names.size(); i++){
		file_names[i]= title + to_string(i+1) +".txt";
	}

	ifstream ifs;

 	cout << "Would you like to print the first paragraph?";
 	string cont;
	cin >> cont;
	for (string name : file_names)
	{
		while(cont != "y" && cont != "n")
		{
			cout << "Would you like to print the next part";
			cin >> cont;
		}
		if(cont == "y"){
			print_file_contents(ifs, name);
			cout << "Would you like to print the first paragraph?";
			cin >> cont;
	  }
		if(cont == "n"){
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
