// Introduction to multidimensional arrays

#include <iostream>

using namespace std;


int sum(int a[], int n);
void zero_out_array(int a[], int n);

void print_array(int a[], int n);


int main(){

	int my_int_array[5] = {-2, 5, 3, 4, -6};
	const int n = 5;

	int array_total = sum(my_int_array, n);
	
	cout << "my_int_array contains: " << endl;
	print_array(my_int_array, n);	

	cout << "The total of my_int_array is: " << array_total << endl;
	
	cout << endl << "Now zeroing out my_int_array." << endl;

	zero_out_array(my_int_array, n);

	cout << "my_int_array now contains: " << endl;
	print_array(my_int_array, n);

	return 0;

}


// We pass the array length as n, because the array does not know its own size
int sum(int a[], int n){
	int total = 0;
	for (int i = 0; i < n; i++){
		total += a[i];
	}
	return total;
}

// Note that this affects the values of the original array passed in
// Arrays 'decay to pointers'
// We will discuss pointers in the near future
void zero_out_array(int a[], int n){
	for(int i = 0; i < n; i++){
		a[i] = 0;
	}
	return;
}

void print_array(int a[], int n){
	for (int i = 0; i < n; i++){
		cout << a[i] << "\t";
	}
	cout << endl;
	return;
}

