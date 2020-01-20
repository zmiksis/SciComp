#include <iostream>

using namespace std;

void square(int &x);

int main(){
	
	int a = 3;
	cout << "The value of a is: " << a << endl;
	square(a);
	cout << "After calling the pass by reference function square, the value of a is: " << a << endl;

	return 0;

}

// The parameter x is passed by reference.
// Changes made to x in the function change its argument in the calling scope as well.
// You can only pass (non-constant) variables as arguments when a parameter is passed by reference,
// not expressions (e.g. square(2) would not work in this program).
void square(int &x){
	x = x * x;
	return;
}
