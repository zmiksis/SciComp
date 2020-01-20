#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){

	int alphabet[26] = { };
	ifstream ifs;

	// Instead, you should use a while loop to go over every argument
	ifs.open(argv[1]);

	if (!ifs.is_open()){
		cout << "The file could not be opened!" << endl;
		return 0;
	}

	char c;
	while(ifs.get(c)){
		// cout << "My character is " << c << endl;
		if (isalpha(c)){
			c = tolower(c);
			int index = c - 'a';
			alphabet[index]++;
			// cout << index << endl;
		}
	}

	// Create a loop with index i
	for(int i = 0; i < 26; i++){
		char t = i + 'a';
		cout << "The letter " << t << " appears " << alphabet[i] << endl;
	}


	return 0;
}
