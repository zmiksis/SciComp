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

// The argument x is passed by reference.
// Changes made to x in the function change its argument in the calling scope as well.
void square(int &x){
	x = x * x;
	return;
}
