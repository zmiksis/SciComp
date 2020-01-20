// This one is probably the most straightforward.
// There are faster implementations (i.e. O(1) implementations) than the O(n) implementation given here

#include <iostream>

using namespace std;

int main()
{

	int a;
	int b;
	int n;

	cout << "Please enter a lower integer a: ";
	cin >> a;
	cout << "Please enter an upper integer b: ";
	cin >> b;

	// You do not need to do error checking, but I have included it here anyway
	if (b < a){
		cout << "Please make certain that b is greater than a." << endl;
		return 0;
	}

	cout << "Please enter a positive integer n: ";
	cin >> n;

	if (n <= 0){
		cout << "Please make certain that n is positive!" << endl;
		return 0;
	}
	
	// Keep a running total. Make sure to initialize it to 0.
	int total = 0;
	
	// Use i <= b since you want the integers from a to b inclusive 
	for(int i = a; i <= b; i++){
		if( i % n != 0){
			total += i;
		}
	}		

	cout << "The total of the integers between " << a << " and " << b << " inclusive that are not divisible by "
			<< n << " is " << total << endl;

	return 0;
}
