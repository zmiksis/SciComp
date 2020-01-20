// A simple example using a while loop.
#include <iostream>

using namespace std;

int main()
{
	
	// This while loop is essentially filling the role of a for loop
	int i = 0;
	while (i < 10){
		cout << "The value of i is " << i << endl;
		
		// If you do not update the counter, you get an infinite loop
		i += 1;
	}
	
	return 0;
}
