// Solution is the function f, defined near the bottom of the page

#include <iostream>

using namespace std;

int f(int n);

int main()
{
	cout << endl;
	for (int i = 1; i < 101; i++){
		cout << "f(" << i << ") == " << f(i) << endl;
	}
	cout << endl;
	return 0;
}



// Solution begins here
int f(int n){

	// Put the base cases first
	if (n == 1) {
		return 1;
	} else if (n == 2) {
		return 2;
	} else if (n % 2 == 1) {
		return f(n-1) + f( (n+1)/2 );
	} else {
		return f(n/2) + f( (n-2)/2 );
	}
}
