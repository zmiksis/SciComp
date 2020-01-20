#include <iostream>

using namespace std;

// Define a global variable named n
// It is generally good practice to avoid using global variables, 
// because it can be difficult to keep track of where they are modified.
int n = 3;


// Placing 'void' as the parameters just indicates that the function takes
// no parameters. This is not typically done, but is allowed.
// You could just leave the list of parameters inside the parentheses blank.
void example_function(void);
void modify_global_variable(void);

int main(){
	// We haven't defined a local variable n yet, so the global value is printed in the next statement.
	cout << "The value of the global variable n is " << n << endl;
	
	int n = 4;

	// Now, the value printed is the one in the innermost scope
	cout << "The value of the local variable n in the main routine is " << n << endl;

	// example_function has a local variable also called n, which is printed inside the function.
	example_function();

	// use the modify global variable function to change the value of the global variable n
	modify_global_variable();
	
	// You can still access the global scope by using the 'unary scope resolution operator,' which is ::
	cout << "The value of the global variable n is now " << ::n << endl;

	return 0;

}

void example_function(void){
	int n = 5;
	// Note: this will print the local variable n instead of the global variable n.
	// The variable accessed will be the one in the innermost scope.
	cout << "The value of the local variable n in the example function is " << n << endl;
	return;
}


void modify_global_variable(void){
	// The value of the global variable n is changed, which could be difficult to notice in a more complicated program
	n = 17;
	return;
}


