// This program prints the powers of two below the threshold N, starting with 2 to the zeroth.
#include <iostream>

using namespace std;

int main()
{
	
	constexpr int N = 1000000;			


	for(int power_of_two = 1; power_of_two < N; power_of_two *= 2){
		cout << "The next power of two is " << power_of_two << endl;
	}
	
	return 0;
}
