// 
// Alternatives:
// - you can omit the checks for proper input
// - you can use i*i*i instead of including cmath and using pow(i, 3.0)
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float N;
	double cubesum=0, cubesum2;
	cout << "Enter a positive integer:\n" << endl;
	cin >> N;
	
	if (N<=0 or N!=ceil(N)){
	    cout << N << " is not a positive integer. Now exiting" << endl;
	    return 1;
	}
	
	for(int i=1; i<=N; i++){
		cubesum += pow(i,3.0);
	};	
	cout << "The sum of the cubes from 1 up to " << N << " is: " << cubesum << endl;
	
	cubesum2 = pow(N*(N+1)/2, 2.0);
	cout << "The same sum (using a formula) is: " << cubesum2 << endl;
	return 0;
}