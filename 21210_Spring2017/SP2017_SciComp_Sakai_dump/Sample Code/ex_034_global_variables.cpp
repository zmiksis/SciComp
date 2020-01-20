#include <iostream>

using namespace std;

// Define a global variable named n
// It is generally good practice to avoid using global variables, 
// because it can be difficult to keep track of where they are modified.
int n = 3;


void example_function(void);
void modify_global_variable(void);

int main(){
	cout << "The value of the global variable n is " << n << endl;
	
	int n = 4;

	// The value printed is the one in the innermost scope
	cout << "The value of the local variable n in the main routine is " << n << endl;


	

	example_function();


	// use the modify global variable function to change the value of the global variable n
	modify_global_variable();
	
	// You can still access the global scope by using the 'unary scope resolution operator,' which is ::
	cout << "The value of the global variable n is now " << ::n << endl;

	return 0;

}

void example_function(void){
	int n = 5;
	cout << "The value of the local variable n in the example function is " << n << endl;
	return;
}


void modify_global_variable(void){
	// The value of the global variable n is changed, which could be difficult to notice in a more complicated program
	n = 17;
	return;
}


