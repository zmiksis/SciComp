// This program shows a possible danger of automatic type conversions

#include <iostream>

using namespace std;

int main()
{
	
	// A dangerous and easy to miss behavior - the variable sale_price will be 0
	// because the integer division 3/4 results in 0
	double original_price = 100.0;
	double sale_price = 3/4 * original_price;
	
	cout << "The original price is: " << original_price << endl;
	cout << "The sale price is: " << sale_price << endl;
	
	return 0;
}
