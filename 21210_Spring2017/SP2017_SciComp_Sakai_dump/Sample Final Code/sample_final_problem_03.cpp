// The solution to this problem is just the function get_key_with_highest_value, which occurs near the bottom of the file

// I have provided an alternate solution that is a little more efficient.
// There are other ways of doing this as well.

#include <iostream>
#include <string>


// To use maps
#include <map>


using namespace std;

string get_key_with_highest_value(const map<string, int> &m);
string get_key_with_highest_value_v_2(const map<string, int> &m);

int main(){
	
	map<string, int> zoo_map;


	// Add some key-value pairs to our map
	zoo_map["elephant"] = 3;
	zoo_map["lion"] = 4;
	zoo_map["penguin"] = 20;
	zoo_map["tiger"] = 6;
	zoo_map["lemur"] = 15;
	zoo_map["panda"] = 2;
	
	string key_with_greatest = get_key_with_highest_value_v_2(zoo_map);

	cout << "The key that corresponds to the greatest value is: " << key_with_greatest << endl;
	cout << "The corresponding value is: " << zoo_map[key_with_greatest] << endl;

	return 0;
}



// Solution begins here

// Probably best to pass by constant reference since we do not want to change the map,
// and we want to avoid a potentially expensive copy

// There is a better way to do this using iterators
// that avoids the conditionals
string get_key_with_highest_value(const map<string, int> &m){
	
	// this boolean will be used to help us get an initial greatest value found so far and the associated
	// key with the greatest value found so far.
	// You can avoid using a boolean like this if you use iterators.
	bool found_first = false;
	
	// key_with_greatest will store the key associated to the greatest value encountered so far
	string key_with_greatest;

	// greatest_value stores the greatest value encountered so far
	int greatest_value;
	// You could iterate by constant reference for improved performance
	for (auto kv : m){
		if (!found_first){
			// Just make the key with the greatest value found so far the first one
			key_with_greatest = kv.first;
			greatest_value = kv.second;

			found_first = true;
		} else if (kv.second > greatest_value){
			key_with_greatest = kv.first;
			greatest_value = kv.second;
		}
	}

	return key_with_greatest;
}


// Alternate solution with iterators that avoids using a boolean
string get_key_with_highest_value_v_2(const map<string, int> &m){

	string key_with_greatest;
	int greatest_value;

	key_with_greatest = (*m.begin()).first;
	greatest_value = (*m.begin()).second;

	for(const auto &kv : m){
		if(kv.second > greatest_value){
			greatest_value = kv.second;
			key_with_greatest = kv.first;
		}
	}
	
	return key_with_greatest;
}
