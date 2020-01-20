// Names and scores program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> names;
    vector<int> scores;

    string name;
	int score;

	cout << "Program for recording names and scores." << endl;
	cout << "Enter each name, a space and a score e.g. Joe 17, and press enter." << endl;
	cout << "No duplicate names please. To stop entering data, enter NoName 0" << endl;
	cout << endl;

	while(cin >> name >> score && name != "NoName"){
		for (int i=0; i<names.size(); i++){
			if (names[i]==name){
				cout << "Error! Duplicate data. " << name << " has been entered already" << endl;
				return 1;
			}
		}
	    names.push_back(name);
		scores.push_back(score);
	}
	cout << endl;
    cout << "Names and scores, one per line:" << endl;
    for (int i=0; i<names.size(); i++){
    	cout << names[i] << " " << scores[i] << endl;
    }
    return 0;   
}
