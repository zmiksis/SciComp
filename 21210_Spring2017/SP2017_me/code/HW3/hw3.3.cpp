// Statistical analysis program
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double mean(const vector<double> &x_obs);
double st_dev(const vector<double> &x_obs);
double correlation(const vector<double> &x_obs, const vector<double> &y_obs);

int main()
{
    vector<double> x_obs;
    vector<double> y_obs;

	cout << "Program for simple statistical analysis." << endl;
	cout << "Enter each x-y pair, with a space between x & y e.g. 1.5 0.35 and press enter." << endl;
	cout << "Provide at least two data pairs. To stop entering data, enter a string." << endl;
	cout << endl;

	double x, y;

	while(cin >> x >> y){
		x_obs.push_back(x);
		y_obs.push_back(y);
	}
	if (x_obs.size() < 2){
		cout << "Error! This sample is too small to be useful. Please provide at least two data pairs." << endl;
		return 1;
	}

	double x_bar = mean(x_obs);
	double y_bar = mean(y_obs);
	double x_std = st_dev(x_obs);
	double y_std = st_dev(y_obs);

	cout << "The sample means of x is: " << x_bar << endl;
	cout << "The sample means of y is: " << y_bar << endl;
	cout << "The sample standard deviation of x is: " << x_std << endl;
	cout << "The sample standard deviation of y is: " << y_std << endl;	
	
	if (x_std == 0 || y_std == 0){
		cout << "Sample correlation cannot be calculated because sample standard deviation of x or y = 0" << endl;
		if (x_std == 0){
			cout << "The least-squares linear regression equation is undefined since standard deviation of x = 0" << endl;
		}
	}else{		
		double r = correlation(x_obs, y_obs);		
		double m = r * y_std / x_std;
		double b = y_bar - m*x_bar;
		cout << "The sample correlation is: r=" << r << endl;
		cout << "The least-squares linear regression equation is y = " << m <<  "x + " << b << endl;
	}

    return 0;   
}

// Returns the sample mean
double mean(const vector<double> &x_obs){
	double total = 0.0;
	for (double elem : x_obs){
		total += elem;
	}
	return total/x_obs.size();
}

// Returns the sample standard deviation
double st_dev(const vector<double> &x_obs){
	double x_bar = mean(x_obs);
	double total = 0.0;
	for (double elem : x_obs){
		total += pow(elem - x_bar, 2);
	}
	return pow( total/(x_obs.size() - 1.0), .5);
}

// Returns the sample correlation coefficient
double correlation(const vector<double> &x_obs, const vector<double> &y_obs)
{
	double corr=0;
	double x_bar = mean(x_obs);
	double y_bar = mean(y_obs);
	double x_std = st_dev(x_obs);
	double y_std = st_dev(y_obs);	
	for (int i=0; i<x_obs.size(); i++){
		corr += ((x_obs[i]-x_bar)/x_std)*((y_obs[i]-y_bar)/y_std);
	}
	return corr/(x_obs.size() - 1);
}