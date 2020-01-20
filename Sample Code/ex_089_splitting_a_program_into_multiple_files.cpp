#include <iostream>
#include <string>
#include <vector>

// Use include to be able to access functions/classes/etc declared (or defined)
// in your .h file

// (For most implementations) you should use " " to enclose the name of the header
// in your include if your header is in the same directory as your program
// and you should use < > to enclose the name if you are including part of the standard library.
// Which to use for headers elsewhere may depend on your particular implementation

#include "ex_089_statistics.h"

using namespace std;


int main(){
	
	// These values are just for an example
	vector<double> x = {1.0, 4.0, 6.0, 3.0, 5.0};
	
	cout << endl;
	cout << "The mean of x is: " << mean(x) << endl;
	cout << "The standard deviation of x is: " << std_dev(x) << endl;
	cout << "The median of x is: " << median(x) << endl;
	cout << endl;	

	return 0;
}
