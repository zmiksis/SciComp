#include <iostream>

using namespace std;


int sum_of_squares(int a, int b);


int main()
{
	int a = 0;
	int b = 0;
	int sum_squares_a_to_b = 0;

	cout << "Enter an integer a: ";
	cin >> a;
	cout << "Enter an integer b (with b > a): ";
	cin >> b;
		
	sum_squares_a_to_b = sum_of_squares(a, b);
	
	cout << "The sum of squares from " << a << " to " << b << " (inclusive) is " << sum_squares_a_to_b << endl;

	return 0;

}


int sum_of_squares(int a, int b){
	// total is a local variable
	// total is accessible only inside this function, and every time the function is called
	// total is defined again to be 0
	int total = 0;
	for(int i = a; i <= b; i++){
		total += i * i;
	}
	return total;
}

