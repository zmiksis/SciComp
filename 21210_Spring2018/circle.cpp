#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <functional>

using namespace std;

int main(int argc, char* argv[]){   

    if (argc < 4){
        cout << endl;
        cout << "Error! You need to specify the point\'s x and y coordinates, and the number of trials for Monte-Carlo simulation.\nNow exiting.\n" << endl;
        return 0;
    }

    double xval = stod(argv[1]);
    double yval = stod(argv[2]);
    long long int trials = stoll(argv[3]);

    random_device rd;
    int seed = rd();
    mt19937 seedmaker(seed);
    uniform_real_distribution<double> distrib(0, 1);
    auto guess = bind(distrib, seedmaker);

    double theta, radius, avgdist = 0.0, pi = acos(-1);

    cout << endl;
    cout << "Running Monte-Carlo simulation, please hold on..." << endl;

    for (long long int i=0; i < trials; i++){
    	theta = 2 * pi * guess();
    	radius = sqrt(guess());
    	double pointX = radius*cos(theta);
    	double pointY = radius*sin(theta);
    	avgdist += sqrt(pow(xval - pointX,2.0) + pow(yval - pointY, 2.0));
    }
    avgdist = avgdist / trials;

	cout << "The approximate expected distance to (" << xval << "," << yval << ") is: " << setprecision(12) << avgdist << endl;
	cout << endl;

	return 0;
}