#include <iostream>

// Use the following to obtain access to std::map
// maps are a kind of "associative array"
// maps take keys and associate them to a corresponding value.
// The keys are maintained in order, using < for comparison
#include <map>

#include <string>

// Use utility for make_pair
#include <utility>


using namespace std;


int main(){
	
	std::map<string, int> age_map;

	// One way to add an key-value pair to a map is using assignment with the subscript operator
	age_map["Matthew"] = 35;
	age_map["Margarita"] = 30;
	age_map["Ivan"] = 23;

	// The elements of a map are key-value pairs, with the type std::pair<key_type, value_type>
	// You can access the first element of a pair with .first
	// and the second element with .second
	cout << endl << endl;
	for(const pair<string, int> &kv : age_map){
		cout << kv.first << " is " << kv.second << " years old." << endl;
	}



	// You can also add an element with .insert( value ) or the newer emplace member function
	// If you try to insert a key that already exists, the value will not change


	age_map.insert(std::make_pair<string, int>("Aphranius", 52));
	age_map.insert(std::make_pair<string, int>("Mark", 39));
	age_map.insert(std::make_pair<string, int>("Matthew", 31));

	cout << endl << endl<< "After adding Afranius and Mark and trying to change Matthew's age with insert:" << endl << endl;

	// Here the iteration is by constant reference since no values will be changed.
	// Note that, because the keys in a map are stored in sorted order, the names will be printed out
	// in alphabetical order.
	for(const pair<string, int> &kv : age_map){
		// You can access the first entry of a pair with .first, and the second with .second
		cout << kv.first << " is " << kv.second << " years old." << endl;
	}

	cout << endl << "Note that Matthew's age did not change using insert." << endl;
	
	age_map["Matthew"] = 31;
	cout << endl << endl << "After changing Matthew's age with []: " << endl << endl;

	for(const pair<string, int> &kv : age_map){
		cout << kv.first << " is " << kv.second << " years old." << endl;
	}

	// You can remove a pair with .erase(key)
	age_map.erase("Matthew");
	age_map.erase("Ivan");

	cout << endl << endl << "After erasing Matthew and Ivan:" << endl << endl;
	for(const pair<string, int> &kv : age_map){
		cout << kv.first << " is " << kv.second << " years old." << endl;
	}

	cout << endl;	

	return 0;
}
