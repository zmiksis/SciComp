#include <iostream>

using namespace std;

int main(){
	
	// Use a for loop to print the numbers from 0 to 9 inclusive.
	for(int i = 0; (i < 10) && (i % 2 == 0) ; i++){
		cout << "The value of i is " << i << endl;
	}

	
	return 0;
}
