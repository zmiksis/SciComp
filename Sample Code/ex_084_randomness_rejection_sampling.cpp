// We will find the average distance of a point inside the triangle in the plane
// with vertices (0, 0), (1, 1) and (2, 0) to the origin using a Monte Carlo approach.

// We will draw points (uniformly) at random from the triangle in the plane 
// with vertices (0, 0), (1, 1), and (2, 0)
// To do this, we could draw uniformly from the rectangle [0, 1] x [0, 2] repeatedly until
// we obtain a point in the desired region (i.e. using rejection sampling)

// This procedure can be modified to draw from distributions that are not just uniform distributions,
// but the modification is a little more complicated

#include <iostream>
#include <random>
#include <functional>
#include <string>
#include <iomanip>

using namespace std;




// Function for checking whether or not a point (x,y) is inside the triangle
bool is_valid(double x, double y);

// Pass in the number of trials and the seed value by optional command line arguments
int main(int argc, char* argv[]){
	// N is the number of points to draw

	int N;
	int seed_value;
	random_device rd;

	switch(argc){
		case 1:
			N = 1000;
			seed_value = rd();
			break;
		case 2:
			N = stoi(argv[1]);
			seed_value = rd();
			break;
		default:
			N = stoi(argv[1]);
			seed_value = stoi(argv[2]);
			break;
	}


	mt19937 generator(seed_value);

	// Set up distribution from which to sample
	uniform_real_distribution<double> distribution_x(0, 2);
	uniform_real_distribution<double> distribution_y(0, 1);
	
	// To keep drawing x and y independently, pass the generator to bind using ref
	// If you do not use the ref function here, the draws between x and y will become correlated
	// and your Monte Carlo approximation will not be accurate
	auto draw_x = bind(distribution_x, ref(generator));
	auto draw_y = bind(distribution_y, ref(generator));
	
	// Keep track of the total distance
	double total_distance = 0.0;

	double x;
	double y;

	for(int i = 0; i < N; i++){
		// Draw an x and a y
		x = draw_x();
		y = draw_y();

		// x and y might not lie inside the triangle.
		// If they do not, just draw repeatedly until you find
		// an x and y pair that does lie inside the triangle.
		// The code here can be easier to read if you use a separate function to check validity.

		while (!is_valid(x, y)){
			x = draw_x();
			y = draw_y();
		}


		// Now we are guaranteed to have a valid (x, y) coordinate in the triangle,
		// so we add the distance of the point to the origin to the total distance found so far.
		total_distance += pow(pow(x, 2) + pow(y, 2), .5);
		
	}

	// Now, compute the average distance and report the result.
	double average_distance = total_distance/N;
	
	cout << setprecision(12) << endl << endl;
	cout << "The approximate average distance of a point in the triangle" << endl;
	cout << "  with vertices (0, 0), (1, 1) and (2, 0) to the origin is: " << average_distance << endl << endl;
	
	cout << "The true value is around 1.08215" << endl << endl;	


	return 0;
}


bool is_valid(double x, double y){
	// Check to see if x and y lie inside the triangle
	if (0 <= y && y <= 1 && y <= x && x <= 2 - y){
		return true;
	}
	return false;
}
