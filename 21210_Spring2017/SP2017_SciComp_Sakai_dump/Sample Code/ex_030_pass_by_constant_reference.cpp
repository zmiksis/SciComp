#include <iostream>

using namespace std;

int simple_function(const int &a, const int &b);

int main(){
	
	int a = 3;
	int b = 4;

	// assignment with a function call
	int res = simple_function(a, b);

	cout << "For a == " << a << " and b == " << b << ", the result is " << res << endl;

	return 0;

}

// a and b are passed by constant reference.
// No copies are made, but the values of a and b are not allowed to change.
// Usually, you should not pass the basic types (integers, doubles, characters, booleans)
// by reference or by constant reference, but for larger types it can be much more efficient
// to pass by reference than by value, because the copying for pass by reference may take
// a long time. 
// Passing by constant reference makes it so that you do not accidentally change
// a value that you do not want to change.
int simple_function(const int &a, const int &b){
	
	// If you uncomment the following line, the program will not compile because it tries to change the value of a
  // a = a + 2;
	return a + 2*b;
}

