#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <functional>

using namespace std;

void randompoint(double &x, double &y);

int main(int argc, char* argv[]){   

    if (argc < 4){
        cout << endl;
        cout << "Error! You need to specify the point\'s x and y coordinates, and the number of trials for Monte-Carlo simulation.\nNow exiting.\n" << endl;
        return 0;
    }

    double xval = stod(argv[1]);
    double yval = stod(argv[2]);
    long long int trials = stoll(argv[3]);

    double avgdist = 0.0;

    cout << endl;
    cout << "Running Monte-Carlo simulation, please hold on..." << endl;

    double x;
    double y;
    for (long long int i=0; i < trials; i++){
    	randompoint(x, y);
    	avgdist += sqrt(pow(xval - x,2.0) + pow(yval - y, 2.0));
    }
    avgdist = avgdist / trials;

	cout << "The approximate expected distance to (" << xval << "," << yval << ") is: " << setprecision(12) << avgdist << endl;
	cout << endl;

	return 0;
}

void randompoint(double &x, double &y){
	x = 1.01; y=1.01;

	random_device rd;
    int seed = rd();
    mt19937 seedmaker(seed);
    uniform_real_distribution<double> distrib(-1, 1);
    auto guess = bind(distrib, seedmaker);

	while (pow(x, 2.0) + pow(y, 2.0) >= 1.0){
		x = guess();
		y = guess();
	}
}
