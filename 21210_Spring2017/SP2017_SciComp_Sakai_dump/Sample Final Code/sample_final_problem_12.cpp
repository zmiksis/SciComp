#include <iostream>
#include <string>
#include <functional>
#include <cmath>
#include <random>

// There are many other ways to do this problem!

using namespace std;

int main(int argc, char* argv[]){

	if (argc < 3) { 
		cout << "Not enough command line arguments!" << endl;
		return 0;
	}

	double R = stod(argv[1]);
	int num_trials = stoi(argv[2]);

	// Set up for choosing a random direction to take a step
	random_device rd;
	mt19937 generator(rd());
	// Draw from one of four possible directions, each equally likely
	uniform_int_distribution<int> distribution(0, 3);
	auto draw = bind(distribution, generator);
	

	// Use x and y to store the current location of the walk
	int x;
	int y;
	int steps_taken;
	int total_steps_taken; // This problem could be done with just one counter for the total number of steps taken
	int choice;

	

	// Carry out the required number of trials
	for(int i = 0; i < num_trials; i++){
		// Reset the simulation - set the position to the origin, and the number of steps taken to 0
		x = 0;
		y = 0;
		steps_taken = 0;

		// hypot is just a more accurate way of calculating sqrt( pow(x, 2.0) + pow(y, 2.0))
		while ( hypot(x, y) < R){
			choice = draw();
			switch(choice){
				case 0: x += 1;
								break;
				case 1: x -= 1;
								break;
				case 2: y += 1;
								break;
				case 3: y -= 1;
								break;
			}

			// Update the number of steps taken after every step
			steps_taken += 1;
		}
		
		total_steps_taken += steps_taken;
	}
	cout << endl;
	cout << "The expected number of steps to move a distance of " << R 
					<< " or more from the origin is approximately: " 
					<< double(total_steps_taken)/num_trials << endl << endl;
	// Remember to convert to a double before averaging so that you do not use integer division

	return 0;
}
