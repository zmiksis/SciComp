// Introduction to multidimensional arrays

#include <iostream>

using namespace std;

// The ability to pass a multidimensional array as a parameter is very limited
// You must specify the size of each dimension after the first
void print_two_dim_array(int two_dim_array[][5], int num_rows);

int main(){
	
	const int m = 4;
	const int n = 5;

	int my_two_dim_array[m][n];

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			my_two_dim_array[i][j] = 10*i + j;
		}
	}


	print_two_dim_array(my_two_dim_array, m);

	return 0;
	
}

void print_two_dim_array(int two_dim_array[][5], int num_rows){
	// The depth of the second dimension must be specified in the parameter list, unfortunately
	for (int i = 0; i < num_rows; i++){
		for (int j = 0; j < 5; j++){
			cout << two_dim_array[i][j] << "\t";
		}
		cout << endl;
	}
	return;
}
