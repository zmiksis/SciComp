// Introduction to arrays

#include <iostream>

using namespace std;


int main(){
	
	// Basic array definition, defines an array of length 10
	// Arrays do not know their own size, so if you use an array
	// you should store the size somewhere
	const	int my_int_array_size = 10;
	int my_int_array[my_int_array_size];
	

	// Print the int array, noting the data already stored is not default initialized to 0
	cout << "The contents of my_int_array after definition are: " << endl; 
	for (int i = 0; i < my_int_array_size; i++){
		cout << my_int_array[i] << endl;
	}
	cout << "We did not specify any values yet, so the values were the contents already in those memory addresses!" << endl;
	cout << endl << endl;

	// Now let's make a new array, which we will default initialize.
	// Note that the values after those specified in the initialization list are default initialized to 0.0
	double my_double_array[8] = { 2.5, -3.2, 1.7};
	const int my_double_array_size = 8;

	// Print the double array, noting the effect of the default initialization to 0.0
	cout << "The contents of my_double_array are: " << endl;
	for (int i = 0; i < my_double_array_size; i++){
		cout << my_double_array[i] << endl;
	}
	cout << endl << endl;
	
	// You can also initialize an array without specifying its size
	// The array still will not know its own size, though
	double my_double_array_2[] = {2.5, 3.8, -4.1, 2.2};
	const int my_double_array_2_size = 4;
	
	cout << "The contents of my_double_array_2 are: " << endl;
	for (int i = 0; i < my_double_array_2_size; i++){
		cout << my_double_array_2[i] << endl;
	}
	cout << endl << endl;
	

	// The following commented out code is technically not valid C++, but your compiler might let you get away with it.
	// In C++, array sizes are supposed to be known at compile time, which is a big limitation.
	// In the code below, the array size is not known until run time, when the user enters a value.
	// You should probably avoid using code like the following, since it isn't standard.

  //	int N;
  //	cout  << "Enter an integer N: ";
  //	cin >> N;
  //	int my_int_array_2[N];

  //  cout << "The contents of my_double_int_array_2 are: " << endl;
  //	for (int i = 0; i < my_int_array_2_size; i++){
  //		cout << my_int_array_2[i] << endl;
  //	}
  //	cout << endl << endl;

	return 0;
}
