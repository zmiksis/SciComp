#include <iostream>

// Must #include <map> to use maps
#include <map>
#include <string>

using namespace std;

int main() {
	
	//Create a new map from strings to ints named zoo_map
	map<string, int> zoo_map;


	// Add some animals, along with the count of the number of animals to the map
	// The map associates the name of the animal to the count
	zoo_map["penguin"] = 7;
	zoo_map["elephant"] = 3;
	zoo_map["lion"] = 2;

	// iterate through the map using a range for, with the auto keyword
	// kv will be of type pair<string, int>
	for(auto kv : zoo_map){
		// Access the elements of the key-value pair with .first and .second
		// kv.first is the key, and kv.second is the corresponding value
		cout << "There are " << kv.second  << " " << kv.first <<"s in the zoo." << endl;
	}

	// Add another type of animal to the map
	zoo_map["ostrich"] = 1;
	

	// Print out the contents again.
	// Note that the keys are stored in sorted order by <
	cout << endl << endl;
	cout << "After adding an ostrich to our zoo, the contents are: " << endl;
	for(auto kv : zoo_map){
		cout << "There are " << kv.second  << " " << kv.first <<"s in the zoo." << endl;
	}


	// The elephants have a child, so increase the count using the subscript operator
	zoo_map["elephant"] += 1;

	cout << endl << endl;
	cout << "After the elephants have a child, the contents of our zoo are: " << endl;
	for(auto kv : zoo_map){
		cout << "There are " << kv.second  << " " << kv.first <<"s in the zoo." << endl;
	}



	// All populations of animals now double in size.
	// Need a reference in the iteration to modify the original key-value pair in the map, 
	// rather than a copy of it.
	for(auto &kv : zoo_map){
		kv.second = 2 * kv.second;
	}

	cout << endl << endl;
	cout << "After doubling all populations, the quantities are: " << endl;
	for(auto kv : zoo_map){
		cout << "There are " << kv.second  << " " << kv.first <<"s in the zoo." << endl;
	}


	// Remove large carnivores, aka lions
	zoo_map.erase("lion");
	cout << endl << endl;
	cout << "After entirely removing lions: " << endl;
	for(auto kv : zoo_map){
		cout << "There are " << kv.second  << " " << kv.first <<"s in the zoo." << endl;
	}

	// The size member function will return the number of key-value pairs
	cout << endl << endl;
	cout << "There are " << zoo_map.size() << " exhibits in our zoo." << endl;

	// Use the count member function to test whether or not a key is present in the map
	cout << endl << endl;
	if(zoo_map.count("tiger") == 1){
		cout << "Tigers are present in our zoo." << endl;
	} else {
		cout << "Tigers are not present in our zoo." << endl;
	}


	return 0;	
}
