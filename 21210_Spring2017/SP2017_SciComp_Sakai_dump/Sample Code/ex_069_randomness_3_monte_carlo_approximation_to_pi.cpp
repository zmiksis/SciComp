// In this program, we will approximate pi using a Monte Carlo method
// Monte Carlo methods are useful for approximating deterministic quantities
// using a random procedure. 
// However, they tend to converge fairly slowly (with error often proportional to 1/sqrt(num_trials))

// We will repeatedly draw, uniformly at random, two doubles from the square [-1, 1) x [-1, 1) in R^2
// We will record a 'success' if the point we draw lies inside the unit circle

// Because the unit circle has area pi and the square has area 4, approximately pi/4 portion of the time
// we should record a success

// So, pi should be approximately 4 times the percentage of success among all trials we record.

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <random>
#include <functional>

using namespace std;


int main(int argc, char* argv[])
{
	
	int seed_value;
	random_device rd;
	
	if (argc == 1){
		seed_value = rd();
	} else {
		seed_value = stoi(argv[1]);
	}

	mt19937 generator(seed_value);
	uniform_real_distribution<double> distribution(-1, 1);
	auto draw = bind(distribution, generator);
	

	long long int num_trials;
	cout << "Enter the number of trials to run: ";
	cin >> num_trials;	

	// Use to record the total number of points drawn that lie in the unit circle
	long long int num_successes = 0;
	
	// A place to store the x and y coordinates
	// The program could be rewritten not to include these at the expense of being readable
	double x;
	double y;

	for (long long int i = 0; i < num_trials; i++){
		// Draw the x and y coordinates uniformly at random
		x = draw();
		y = draw();
	
		// Check if the point is inside the unit circle
		// If so, record a success
		if ( pow(x,2) + pow(y,2) <= 1.0 ) {
			num_successes += 1;
		}
	}

	cout << setprecision(12);
	cout << "The approximation of pi after " << num_trials << " trials is " << 4.0 * double(num_successes)/double(num_trials) << endl;

	return 0;
}
