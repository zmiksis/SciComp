// Introduction to dynamic memory allocation.
// This is useful for requesting space to store data, 
// particularly when you do not know how many objects you will need in advance.
// However, if you can avoid dynamic memory allocation, you generally should.


#include <iostream>
#include <cmath>

using namespace std;

int main(){

	// Use new for dynamic memory allocation
	// This will allocate enough storage in free store/the heap for a single integer.
	int* p = new int;
	*p = 100;
	
	cout << endl << "The value pointed to by p is " << *p << endl;

	// Free the memory allocated.
	// You should always free the memory allocated to prevent memory leaks.
	// This form of delete should be used when you have allocated memory for a single variable
	delete p;
	p = nullptr;

	cout << endl;	
	
	// New will use the default values or default constructors for the type that you are allocating memory for.

	int N;
	cout << "Enter how many integers you would like to store:";
	cin >> N;

	cout << endl;

	int* q = new int[N];
	cout << "The values in the dynamically allocated memory pointed to by q are: " << endl;
	for (int i = 0; i < N; i++){
		cout << q[i] << "\t";
	}
	cout << endl << endl;

	// Modify the values pointed to by $q$
	for(int i = 0; i < N; i++){
		q[i] = i * i;
	}
	
	// Print the modified values
	cout << "After modifying, the new values pointed to by q are: " << endl;
	for(int i = 0; i < N; i++){
		cout << q[i] << "\t";
	}	

	cout << endl << endl;

	// Delete to free up the memory allocated by new.
	// For classes, delete will call the appropriate destructor.
	delete[] q;
	q = nullptr;

	return 0;
}
