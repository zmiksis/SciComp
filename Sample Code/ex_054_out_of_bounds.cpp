// This program can show what might happen if you try to read or write memory out of bounds.
// You should avoid reading or writing memory out of bounds.


#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> v = {1, 3, 5, 7};

	int N;
	cout << "Enter an index N: ";
	cin >> N;

	// Reading a value with an index out of bounds
	// May give unpredictable values without producing an error
	cout << "Trying to access v[" << N << "] gives: " << v[N] << endl << endl;


	// Trying to assign to an out of bounds index
	// Often (though not always) produces a run time error 
	// (e.g. segmentation fault from accessing memory that is not available to you)
	v[N] = 20;
	cout << "Trying to access v[" << N << "] gives: " << v[N] << endl << endl;

	return 0;
}
