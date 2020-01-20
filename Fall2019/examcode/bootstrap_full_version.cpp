#include <iostream>
#include <random>
#include <functional>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include "statistical_function.h"


using namespace std;



int quantile_index(double p, int n);
double mean(const vector<double> &x);
double std_dev(const vector<double> &x);


int main(int argc, char* argv[]){



	double p = stod(argv[1]);
	int num_trials = stoi(argv[2]);

	random_device rd;
	int seed = rd();
	mt19937 generator(seed);

	ifstream ifs("problem_2_data_2.txt");
	
	vector<double> x_obs;
	

	double temp;
	while(ifs >> temp){
		x_obs.push_back(temp);
	}

	uniform_int_distribution<int> index_dist(0, x_obs.size() - 1);
	auto draw_index = bind(index_dist, ref(generator));


	// MC loop for bootstrap
	vector<double> statistic_values;
	for(int i = 0; i < num_trials; i++){
		vector<double> new_sample(x_obs.size());
		for(int i = 0; i < x_obs.size();i++){
			new_sample[i] = x_obs[draw_index()];
		}
		statistic_values.push_back(statistical_function(new_sample));	
	}
	sort(statistic_values.begin(), statistic_values.end());

	double lower_quantile = (1.0-p)/2;
	double upper_quantile = 1.0 - lower_quantile;
	cout << "Lower quantile: " << lower_quantile << endl;
	cout << "Upper quantile: " << upper_quantile << endl;

	double lower_endpoint = statistic_values[quantile_index(lower_quantile, statistic_values.size())];
	double upper_endpoint = statistic_values[quantile_index(upper_quantile, statistic_values.size())];
	
	cout << p << " confidence interval: [" << lower_endpoint << ", " << upper_endpoint << "]" << endl;


	return 0;
}





int quantile_index(double p, int n){
	return ceil(p * n) - 1;
}
