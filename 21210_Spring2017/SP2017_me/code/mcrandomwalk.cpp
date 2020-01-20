#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <functional>

using namespace std;

int main(int argc, char* argv[]){   

    if (argc < 4){
        cout << endl;
        cout << "Error! Please specify number of dimensions, total number of steps, and number of simulation trials.\nNow exiting.\n" << endl;
        return 0;
    }

    int dim = stoi(argv[1]);
    long long int steps = stoll(argv[2]);
    long long int trials = stoll(argv[3]);

    if(dim == 0){
        cout << "Number of dimensions must be at least 1.\nNow exiting.\n" << endl;
        return 0;
    }

    random_device rd;
    int seed = rd();

    mt19937 bern_generator(seed);
    mt19937 int_generator(seed);

    bernoulli_distribution bern_dist(.5);
    auto pick_direction = bind(bern_dist, bern_generator);

    uniform_int_distribution<int> int_dist(0, dim-1);
    auto pick_axis = bind(int_dist, int_generator);

    cout << endl;
    cout << "Running Monte-Carlo simulation, please hold on..." << endl;

    double avgdist = 0.0;
    int axis;
    for (long long int i=0; i < trials; i++){
        double distance = 0.0;
        vector<int> location (dim);
        for (long long int j=0; j < steps; j++){
            if (dim > 1){
                axis = pick_axis();
            }else{
                 axis = 0;
            }
            int direction = 2*pick_direction() - 1;
            location[axis] = location[axis] + direction;
        }
        for (int k=0; k < dim; k++){
            distance += pow(location[k],2.0);
        }
        distance = sqrt(distance);    
        avgdist += distance;
    }
    avgdist = avgdist / trials;

	cout << "The average distance to the origin after " << trials <<  " trials is: " << setprecision(12) << avgdist << endl;
	cout << endl;

	return 0;
}