#include <iostream>
#include <iomanip>
#include <random>
#include <functional>
#include "hw62f.h"

using namespace std;

int main(int argc, char* argv[]){   

    if (argc < 4){
        cout << endl;
        cout << "Error! You need to specify the interval start and endpoint, and the number of points for Monte-Carlo simulation.\nNow exiting.\n" << endl;
        return 0;
    }

    double start = stod(argv[1]);
    double end = stod(argv[2]);
    long long int points = stoll(argv[3]);

    random_device rd;
    int seed = rd();
    mt19937 generator(seed);
    uniform_real_distribution<double> distribution(start, end);
    auto choose = bind(distribution, generator);

    double xi;
    double I = 0.0;
    double r = (end - start)/points;

    cout << endl;
    cout << "Running Monte-Carlo simulation, please hold on..." << endl;

    for (long long int i=0; i < points; i++){
    	xi = choose();
    	I += r * f(xi);
    }

	cout << "The approximate integral of the function is: " << setprecision(12) << I << endl;
	cout << endl;

	return 0;
}