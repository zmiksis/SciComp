#include <iostream>

// For random number generation
#include <random>

// For stoi and stod
#include <string>

// To create a map storing the counts of each integer.
// You could also do this with a vector, but it might be a little more work.
#include <map>


// To simplify drawing random numbers slightly
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
	
	if (argc < 4) {
		cout << "Not enough command line arguments!" << endl;
		return 0;
	}


	// Convert the command line arguments to the appropriate types.
	int a = stoi(argv[1]);
	int b = stoi(argv[2]);
  int	N = stoi(argv[3]);	


	// Code for random number generation
	random_device rd;
	mt19937 generator(rd());
	// We need the uniform integer distribution since we are drawing
	// integers uniformly at random.
	uniform_int_distribution<int> distribution(a, b);
	auto draw = bind(distribution, generator);

	
	map<int, int> count_map;
	

	int x;
	for(int i = 0; i < N; i++){
		x = draw();
		if(count_map.count(x) > 0 ){
			count_map[x] += 1;
		} else {
			count_map[x] = 1;
		}
	}

	// Print out the occurence of each value
	// kv.first is the number (the key in the count map)
	// kv.second is how many times it was drawn (the associated value in the count map)
	for(auto kv : count_map){
		cout << kv.first << " occurred " << kv.second << " times." << endl;
	}

	return 0;
}
