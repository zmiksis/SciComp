// A simple example using a while loop.
#include <iostream>

using namespace std;

int main()
{
	
	// This while loop is essentially filling the role of a for loop.
	int i = 0;
	while (i % 2 == 0){
		cout << "The value of i is " << i << endl;
		
		// If you do not update the counter, you get an infinite loop.
		// Control-C can be used to break an infinite loop.
		i += 2;
	}

	// i does not go out of scope after the loop
	// because it was defined before the loop began.

	cout << "After the loop, the value of i is " << i << endl << endl;
	
	return 0;
}
