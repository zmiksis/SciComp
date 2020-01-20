#include <iostream>

// You need to #include <cmath> to use the pow, exp and cos functions,
// but you do not need to mention that as the answer on the exam 
#include <cmath>


using namespace std;


double f(double x, double);



// This part of the program is not part of the problem on the sample exam,
// it is just to demonstrate using the function
int main()
{

	double x = 0.0;
	double y = 0.0;

	while (x < 2.1){
		while (y < 2.1) {
			cout << "f(" << x << ", " << y << ") == " << f(x,y) << endl;
			y += .5;
		}
		x += .5;
		y = 0.0;
	} 

	return 0;
}

// You only need to give this part as the answer
double f(double x, double y){
	return pow(x, 2) + exp(x) * cos(y);
}
