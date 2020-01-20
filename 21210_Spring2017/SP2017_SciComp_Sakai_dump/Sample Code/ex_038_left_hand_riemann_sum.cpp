#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double definite_integral_lhs(double a, double b, int n);
double f(double x);

int main()
{
	double a;
	double b;
	double res;
	int n;	
	
	cout << "Enter the lower bound a: ";
	cin >> a;
	cout << "Enter the upper bound b: ";
	cin >> b;
	cout << "Enter the number of subintervals n: ";
	cin >> n;

	res = definite_integral_lhs(a, b, n);
	
	cout << setprecision(12);
	cout << "The definite integral of f was " << res << endl;
	
	

	return 0;
}

// Left hand Riemann sum of the function f,
// which is defined in this program.
// The only way to integrate a different function is to change the definition of f.
double definite_integral_lhs(double a, double b, int n){
	double total = 0.0;
	double delta_x = (b-a)/n;
	
	for(int i = 0; i < n; i++){
		total += f(a + i * delta_x) * delta_x;
	}
	
	return total;
}

double f(double x){
	return x * log(pow(x, 2) + 1);
}
