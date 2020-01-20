// This program might not compile on your implementation, though it will on most modern implementations


#include <iostream>

// For obtaining the value of positive infinity.
// Your particular implementation might not support positive infinity distinct from
// the maximum representable double
#include <limits>
 
using namespace std;


int main(){

	// The first issue is that there is a maximum size for floating point numbers.
	// If you exceed it, you will end up with an 'infinite' value on most
	// implementations of C++

	double value = 1.0;

	double infinity = numeric_limits<double>::infinity();


	// Keep doubling value until it becomes 'infinite'
	while (value < infinity){
		cout << value << endl;
		value *= 2.0;
	}

	cout << "Value has become infinite! Value == " << value << endl;

	cout << "The maximum representable double on this system is: " << numeric_limits<double>::max() << endl;

	return 0;
}
