#include <iostream>
#include <string>
#include <iomanip>

// Must include the header where f is declared
#include "function_to_integrate.h"

using namespace std;

int main(int argc, char* argv[]){

	if (argc < 4){
		cout << "You did not supply enough command line arguments!" << endl;
		return 0;
	}

	double a = stod(argv[1]);
	double b = stod(argv[2]);
	int N = stoi(argv[3]);

	double delta_x = (b-a)/N;	
		

	double total = f(a);

	for (int i = 1; i < N; i++){
		total += 2.0 * f(a + i * delta_x);
	}

	total += f(b);
	total = total * delta_x/2.0;

	cout << setprecision(12) << endl;
	cout << "The definite integral of f over the interval [" << a << ", " << b << "]" << endl;
	cout << " using the trapezoidal rule with " << N << " subintervals is: " << total << endl << endl;

	return 0;
}
