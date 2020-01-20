// The solutions are the functions named "interweave" and "interweave_v_2" defined near the bottom of this file.
// "interweave" does not use a string stream
// "interweave_v_2" uses a string stream and is the better solution

#include <iostream>
#include <string>

#include <sstream>

using namespace std;


string interweave(string s1, string s2);
string interweave_v_2(string s1, string s2);


int main()
{

	cout << interweave("circle", "square") << endl;
	cout << interweave_v_2("cat", "dog") << endl;
	cout << interweave("different", "lengths") << endl; // Note: just prints an empty line due to the endl
	cout << interweave_v_2("different", "lengths") << endl; // Note: just prints an empty line due to the endl 

	return 0;
}


// Solution begins here
string interweave(string s1, string s2){
	
	string res = "";	

	if (s1.size() != s2.size()){
		return "";
	}
	
	for(int i = 0; i < s1.size(); i++){
		// build res through successive concatenations
		res = res + s1[i] + s2[i];
	}
	return res;
}


// This version of the solution uses an output string stream
string interweave_v_2(string s1, string s2){
	ostringstream res;
	if (s1.size() != s2.size()){
		return res.str();
	}
	for (int i = 0; i < s1.size(); i++){
		res << s1[i] << s2[i];
	}
	return res.str();
}
	 
