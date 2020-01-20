#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main(){
	int choice;
	vector<string> options = {"water", "soup", "salad"};

	cout << "Please enter your choice: (1)water (2)soup (3)salad: ";
	cin >> choice;

	if (choice < 1 || choice > 3){
		cout << "That is not a valid option." << endl;
	} else {
		cout << "You chose " << options[choice - 1] << endl;
	}

	cout << "Thank you!" << endl;

	return 0;
}
