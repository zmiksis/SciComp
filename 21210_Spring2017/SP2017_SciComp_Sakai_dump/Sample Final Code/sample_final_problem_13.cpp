#include <iostream>
#include <string>
#include <random>
#include <functional>


using namespace std;

int main(int argc, char* argv[]){
	
	if (argc < 4) {
		cout << "Not enough command line arguments!" << endl;
	}

	double F = stod(argv[1]); 
	double M = stod(argv[2]);
	int num_trials = stoi(argv[3]);

	random_device rd;
	mt19937 generator(rd());
	uniform_real_distribution<double> distribution(0, M);
	auto draw = bind(distribution, generator);

	double position;
	double move; // could be rewritten to remove this variable
	int steps_taken; // could be rewritten to remove this variable
	int total_steps_taken = 0;

	for (int i = 0; i < num_trials; i++){
		// Reset the simulation
		position = 0;
		steps_taken = 0;
		while (position < F){
			move = draw();
			position = position + move;
			steps_taken += 1;
		}
		total_steps_taken += steps_taken;
	}
	
	cout << endl << endl;
	cout << "The average steps required to move beyond the finish line at " << F
				<< " using steps of size at most " << M << " is: " << double(total_steps_taken)/num_trials << endl << endl;
			
		
	
	return 0;
}
