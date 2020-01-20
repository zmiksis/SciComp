#include <iostream>
#include <vector>


using namespace std;

int main() {
	
	vector<int> v = {1, 3, 5, 7};

	cout << endl << endl;

	cout << "Printing elements of v: " << endl;	
	for(auto elem : v){
		cout << elem << endl;
	}

	cout << endl << endl;

	// The following will not change the values in v, since the iteration
	// in the range for copies the values into elem
	cout << "Trying to change elements of v" << endl;
	for(auto elem : v){
		elem = elem + 1;
	}

	cout << endl << "After trying to change elements of v: " << endl;
	for(auto elem : v){
		cout << elem << endl;
	}

	
	cout << endl << endl;

	// The following does change the values in v, due to the presence of the reference
	cout << "Trying to change elements of v, iterating with &:" << endl;
	for(auto &elem : v){
		elem = elem + 1;
	}
	

	cout << "Elements of v are now: " << endl;
	for(auto elem : v){
		cout << elem << endl;
	}
	
	cout << endl;

}
