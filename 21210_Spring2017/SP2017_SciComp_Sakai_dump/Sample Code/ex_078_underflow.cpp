// For C++, there is a smallest positive floating point value for each floating point type


#include <iostream>

#include <limits>
 
using namespace std;


int main(){

	double value = 1.0;

	// Keep halving value until it becomes 0.0
	while (value > 0){
		cout << value << endl;
		value = value/2.0;
	}

	cout << "Finally, value == " << value << endl;

	// Subnormalization is a way to represent floating point numbers that are slightly smaller than what
	// would be the minimum floating point number without the technique.
	// Subnormalization is not very important for this course, but you may encounter it when you discuss
	// floating point numbers in a numerical analysis course.
	cout << "The minimum representable positive double (without subnormalization) on this system is: " << numeric_limits<double>::min() << endl;

	return 0;
}
