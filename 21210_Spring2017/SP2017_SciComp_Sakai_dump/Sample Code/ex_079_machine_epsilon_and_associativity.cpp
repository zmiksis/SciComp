// Another issue with floating point numbers is that, for each floating point number,
// there is a smallest floating point number that you can add to it before getting something distinct.
// One definition of 'machine epsilon' for a floating point system is that it is the smallest positive value
// that you can add to 1.0 to obtain a different floating point number.

// There are other, non-equivalent definitions of machine epsilon, but all reasonable definitions
// try to capture roughly the same idea: adding something positive yet below a certain threshold may lead to 
// obtaining the same number as you had initially.

// This behavior is due to the finite precision of floating point arithmetic.

// Once you know about machine epsilon, it is easy to see that floating point arithmetic is not associative

#include <iostream>
#include <limits>
#include<iomanip>

using namespace std;


int main(){

	double machine_epsilon = numeric_limits<double>::epsilon();	

	double value = 1.0;
	
	double res1 = value + machine_epsilon;


	cout << "The value of machine epsilon is: " << machine_epsilon << endl << endl;

	cout << setprecision(30);

	cout << "After adding machine epsilon to 1.0, we obtain: " << res1 << endl;

	cout << endl << endl;
	
	double half_machine_epsilon = machine_epsilon/2.0;

	
	double res2 = value + half_machine_epsilon;
	
	cout << "Half of machine epsilon is: " << half_machine_epsilon << ", which is clearly not 0.0" << endl;
	cout << setprecision(30) << endl;
	cout << "If we add half of machine epsilon to 1.0, we get: " << res2 << endl;


	cout << endl << endl;

	double first_way = 1.0 + (half_machine_epsilon + half_machine_epsilon);
	double second_way = (1.0 + half_machine_epsilon) + half_machine_epsilon;

	cout << "Performing the calculation the first way, we get: " << first_way << endl;
	cout << "Performing the calculation the second way, we get: " << second_way << endl;


	
	cout << endl << endl << endl;

	// This odd behavior can be compounded:
	first_way = 0.0;
	first_way = first_way + 1.0;
	for (int i = 0; i < 10000000; i++){
		first_way = first_way + half_machine_epsilon;
	}

	second_way = 0.0;
	for (int i = 0; i < 10000000; i++){
		second_way = second_way + half_machine_epsilon;
	}
	second_way = second_way + 1.0;
 
	cout << "After performing the addition of many small values and 1.0 the first way, we obtain: " << first_way << endl;
	cout << "After performing the addition of many small values and 1.0 the second way, we obtain: " << second_way << endl;
	cout << "The difference between the two sums is " << second_way - first_way << endl;

	// If accuracy is of supreme importance in addition (and all of the values are positive),
	// you should add the values from least to greatest.

	// This is rarely a practical concern, but you should be aware of it


	return 0;
}
