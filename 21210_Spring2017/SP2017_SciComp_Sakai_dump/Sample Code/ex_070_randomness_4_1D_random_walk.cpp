// In this program, we will determine the average number of steps required 
// in simple symmetric random walk on the interval [-N, N], starting at 0
// to reach either endpoint -N or N

// We will run a user entered number of simulations, and then report the average number of steps
// per walk on the interval

#include <iostream>
#include <string>
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

	int num_trials;
	cout << "Enter the number of simulations to run: ";
	cin >> num_trials;
	
	int N;
	cout << "Enter the bound N for the interval [-N, N]: ";
	cin >> N;

	// Initialize a generator using the Mersenne Twister 19937 algorithm for random number generation.
	// There is a default_random_engine available, but it varies system to system
	mt19937 generator(seed_value);
	
	// The Bernoulli distribution corresponds to flipping a coin with probability p of heads (1) and 1-p of tails (0)
	// The parameter for the distribution is p
	bernoulli_distribution distribution(.5);


	auto draw = bind(distribution, generator);

	// Some of the following variables are not strictly necessary, 
	// but are used to make the procedure easier to follow

	// Need an integer to start the simulation
	int location = 0;

	// Use an integer to hold the next step
	int step;

	// Use an integer to store the current number of steps taken in a single walk.
	int current_steps = 0;

	// Use an integer to count the total number of steps taken among all walks
	int total_steps = 0;
	
	// Use a double to hold the average number of steps per walk
	double average_steps;

	// Repeat the simulation num_trials number of times
	for(int i = 0; i < num_trials; i++){
		// Start each walk at the origin, having taken no steps
		location = 0;
		current_steps = 0;

		// Keep walking left or right as long as we have not reached the endpoints of the interval
		while (location != N && location != -N){
			// Take a step to the left or right with equal probability
			// We need to multiply by 2 and subtract 1 to obtain either -1 or 1, instead of 0 or 1
			step = 2 * draw() - 1;
			
			location += step;
			current_steps += 1;
	
		}

		total_steps += current_steps;

	}

	average_steps = double(total_steps)/double(num_trials);
	
	cout << "Over " << num_trials << " simulations, the average number of steps taken was " << average_steps << endl;

	return 0;
}
