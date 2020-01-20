// 
// Alternatives:
// - you can omit the checks for proper input
// - you can use: if (i % 5) && (i % 7) instead of: if (i % 35)
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float N;
	cout << "Enter a positive integer:\n" << endl;
	cin >> N;
	
	if (N<=0 or N!=ceil(N)){
	    cout << N << " is not a positive integer. Now exiting" << endl;
	    return 1;
	}
	
	for(int i=1; i<=N; i++){
		if (i%35 == 0){
			cout << i << " is divisible by both 5 and 7\n" << endl;
		}else if (i%7 == 0){
			cout << i << " is divisible by 7 but not 5\n" << endl;
		}else if (i%5 == 0){
			cout << i << " is divisible by 5 but not 7\n" << endl;
		}else{
			cout << i << " is divisible by neither 5 nor 7\n" << endl;
		}
	};	

	return 0;
}