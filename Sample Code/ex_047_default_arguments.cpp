#include <iostream>
#include <cmath>


using namespace std;


// global variable for pi, computed using the cmath library as the inverse cosine of -1.0
constexpr double pi = acos(-1.0);

// This function gives the value of the normal density function specifying sigma.
// Other implementations of densities might specify sigma squared.
double normal_density(double x, double mu = 0.0, double sigma = 1.0);


// The following alternative declaration would not work, because you cannot have a parameter to a function
// that takes a default argument precede a parameter that does not take a default argument
//
// double normal_density(double x, double mu = 0.0, double sigma);



int main(){
	
	double x = 2.0;
	double mu = 4.0;
	double sigma = 0.5;

	// When calling a function that has default arguments, you can pass fewer arguments than you usually would
	// The remaining arguments will be filled in with the default values.
	cout << "The standard normal density function has value " << normal_density(x) << " at x == " << x << endl;

	cout << "The normal density function with mean " << mu << " and standard deviation 1.0 has value " 
					<< normal_density(x, mu) << " at x == " << x << endl;

	cout << "The normal density function with mean " << mu << " and standard deviation " << sigma << " has value "
					<< normal_density(x, mu, sigma) << " at x == " << x << endl;

	return 0;
}

double normal_density(double x, double mu, double sigma){
	return exp(-( pow( (x-mu)/sigma, 2.0)/2.0))/(sqrt(2.0 * pi) * sigma);
}
