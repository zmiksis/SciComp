// Introduction to multidimensional arrays

#include <iostream>

using namespace std;

int main(){

	constexpr int m = 4;
	constexpr int n = 6;
	
	// define a multidimensional array
	// think of as an m by n array
	// where m is the number of rows
	// and n is the number of columns
	int multi_dim_array[m][n];

	// Outer loop iterates over rows
	for (int i = 0; i < m; i++){

		// Inner loop iterates over columns
		for (int j = 0; j < n; j++){
			multi_dim_array[i][j] = 10 * i + j;
		}
	}



	// Now let's print the array
	cout << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << multi_dim_array[i][j] << "\t";
		}
		cout << endl;
	}		
	cout << endl;

	return 0;
}
