#include <iostream>

using namespace std;

// Function declaration. In order to put the definition of 
// the cube function after the main routine, we need to declare the function first.
int cube(int a);


int main()
{
	constexpr int N = 10;

	for(int i = 1; i <= N; i++){
		// call the function cube with cube(argument)
		cout << "The cube of " << i << " == " << cube(i) << endl;
	}	

	return 0;	
}

// Function definition for the cube function.
int cube(int a){
	return a * a * a;
}



