#include <iostream>
#include <string>
#include <random>

// Use this for the bind() function that allows you to draw 
// from a distribution repeatedly using parentheses
// (this will actually be a call to operator() for the distribution object,
// but we will discuss what that means later)
#include <functional>

using namespace std;

// The first genuine command line argument will be for setting the seed value, if we desire
// Otherwise, a random_device object will be used
int main(int argc, char* argv[]) {
	
	int seed_value;

	// Create an object of the random_device class, used for seeding the random number generator.
	// A random device object obtains a seed value from the system, using various sources that are difficult to predict,
	// such as the current time
	random_device rd;

	// Use the seed value provided by command line argument if one is supplied, otherwise use the random device
	if (argc > 1){
		seed_value = stoi(argv[1]);
	} else {
		seed_value = rd();
	}

	// Initialize a generator using the Mersenne Twister 19937 algorithm for random number generation.
	// There is a default_random_engine available, but it varies system to system
	mt19937 generator(seed_value);
	

	// The uniform real distribution with parameters (a, b) obtains a random double
	// in the half-open interval [a, b)
	// The template parameter <double> just has to be a real type, like double, long double, float, etc.
	uniform_real_distribution<double> distribution(0, 1);

	// We can repeatedly generate random real numbers in the in the interval [0, 1) easily using	
	// bind to obtain an easy way to draw from the distribution
	// The 'auto' keyword used here is for automatic type deduction-
	// the compiler will figure out what type 
	// the lvalue should have from the type on the right.
	// This keyword can be useful for range for loops as well.
	// The actual type for draw here is complicated, but using it is not.
	// If you intend to bind more than one distribution to the same generator,
	// use instead: auto draw = bind(distribution, ref(generator));
	// If you omit the ref function, your draws may become correlated!
	auto draw = bind(distribution, generator);

	cout << "Drawing 10 random numbers from the uniform [0, 1) distribution: " << endl;
	for (int i = 0; i < 10; i++){
		cout << draw() << endl;
	}

	return 0;
}
