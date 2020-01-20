// The solution to this problem is the function calculate_S, found near the bottom of this file

#include <iostream>

// To use vectors
#include <vector>
#include <cmath>


using namespace std;

double calculate_S(const vector<double> &v, int x);

int main()
{
	vector<double> v = {2.0, -1.3, 3.2, 4.1, 6.7, -4.0};
	
	
	cout << calculate_S(v, 1.5) << endl;

	return 0;
}


// Solution begins here
// No need for error checking (i.e. if x is positive)
double calculate_S(const vector<double> &v, int x){
	double total = 0.0;
	for (int i = 0; i < v.size(); i++){
		if (abs(v[i]) > x){
			total += 1.0/v[i];
		}
	}
	return total;
}
