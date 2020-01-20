#include <iostream>

using namespace std;

int main(){
    int n;
    
	cout << "Enter an integer for your selection: (1) Music (2) Video (3) Quiet:" << endl;
	cin >> n;

	switch (n){
		case 1:
			cout << "You have selected music.";
			break;
		case 2:
			cout << "You have selected video.";
			break;
		case 3:
			cout << "You have selected quiet.";
			break;
		default:
			cout << "That is not a valid selection.";
			break;
	}

    cout << endl;
	cout << "Thank you.";

	return 0;
}