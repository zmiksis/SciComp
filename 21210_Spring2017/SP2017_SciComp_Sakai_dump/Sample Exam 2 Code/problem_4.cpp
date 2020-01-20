#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void replace_below_threshold(vector<int> &v, int threshold);

int main(){

	vector<int> test_vec = {1, 8, 4, 5, 6, 3, 2};

	int threshold;
	cout << endl << endl << "Enter a threshold: ";
	cin >> threshold;

	cout << endl << "Before replacing elements below the threshold of " << threshold << " the original vector contained: " << endl;
	for (int i = 0; i < test_vec.size(); i++){
		cout << test_vec[i] << endl;
	}
	
	replace_below_threshold(test_vec, threshold);

	cout << endl;
	cout << "After replacing the elements below " << threshold << " by " << threshold << ", the vector contains: " << endl;
	for (int i = 0; i < test_vec.size(); i++){
		cout << test_vec[i] << endl;
	}

	return 0;
}


// Solution begins here
void replace_below_threshold(vector<int> &v, int threshold){

	for(int i = 0; i < v.size(); i++){
		// If the value in index i is lower than the threshold, replace it by the threshold
		if (v[i] < threshold){
			v[i] = threshold;
		}
	}

	return;
}	
