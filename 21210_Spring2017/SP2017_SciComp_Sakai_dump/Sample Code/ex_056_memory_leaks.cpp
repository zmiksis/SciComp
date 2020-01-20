// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// CAUTION: AVOID RUNNING THIS PROGRAM !!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// This program gives an example of a memory leak.
// A memory leak occurs when you allocate memory dynamically, and then lose track of it.
// The memory is still reserved for your program by the operating system,
// you just can't access it.


#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int *p;
	
	// We repeatedly allocate new memory, but lose track of it by reassigning the pointer to a new location
	for(int i = 0; i < 100000000; i++){
		p = new int[100000];
		cout << "i is " << i << endl;
		// Uncommenting the following line will fix the memory leak
		// delete[] p;
	}
	
	// Regardless of whether or not you actually use delete in your program,
	// when the program terminates, the allocated memory will be returned to the operating system.

	return 0;
}
