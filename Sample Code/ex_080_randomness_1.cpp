#include <iostream>
#include <string>

// Use for more sophisticated random number generation in C++
// There are simpler ways to generate much less useful random numbers
#include <random>

using namespace std;

// The first genuine command line argument will be for setting the seed value, if we desire
// Otherwise, a random_device object will be used
int main(int argc, char* argv[]) {
	
	int seed_value;

	// Create an object of the random_device class, used for seeding the random number generator.
	// A random device object obtains a seed value from the system, using various sources that are difficult to predict,
	// such as the time (among others)
	random_device rd;

	// Use the seed value provided by command line argument if one is supplied, otherwise use the random device
	if (argc > 1){
		seed_value = stoi(argv[1]);
	} else {
		seed_value = rd();
	}
	
	cout << "The seed value is " << seed_value << endl;

	// Initialize a generator using the Mersenne Twister 19937 algorithm for random number generation.
	// There is a default_random_engine available, but it varies system to system
	mt19937 generator(seed_value);
	

	// The uniform int distribution with parameters (a, b) obtains a random integer from a to b inclusive
	// The template parameter <int> just has to be an integer type, like int, long int, etc.
	uniform_int_distribution<int> distribution(1, 10);

	// You can draw a single random number with distribution(generator)  
	int random_int = distribution(generator);
	
	cout << "A random integer between 1 and 10 is: " << random_int << endl;
	
	return 0;
}
