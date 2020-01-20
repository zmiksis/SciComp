#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double mean(const vector<double> &x_obs);
double stdev(const vector<double> &x_obs);
double correlation(const vector<double> &x_obs, const vector<double> &y_obs);

int main(){
    vector<double> x_obs;
    vector<double> y_obs; 
    double x, y;
	cout << "Please enter each pair of x and y values and press enter." << endl;
	cout << "Enter a string to stop input at any time" << endl;
	cout << endl;
	
	while (cin >> x >> y && cin.good()){
        x_obs.push_back(x);
        y_obs.push_back(y);		    
	}
	
	if ((x_obs.size() < 2) || (y_obs.size() < 2)){
	    cout << "Sample is too small to be useful. Program needs at least 2 input pairs" << endl;
	    return 0;
	}
	
    double x_mean = mean(x_obs);
    double y_mean = mean(y_obs);
    double x_sdev = stdev(x_obs);
    double y_sdev = stdev(y_obs);
    
    cout << "The sample mean of x is " << x_mean << endl;
    cout << "The sample mean of y is " << y_mean << endl;
    cout << "The sample standard deviation of x is " << x_sdev << endl;
    cout << "The sample standard deviation of y is " << y_sdev << endl;
    
    if (x_sdev==0){
        cout << "Since the standard deviation of x is 0, " << endl;
        cout << "the sample correlation and least squares regression line are undefined" << endl;
    }else if(y_sdev==0) {
        cout << "Since the standard deviation of y is 0 but that for x is non-zero, " << endl;
        cout << "the sample correlation is undefined, and the regression is the horizontal line Y=" << y_obs[0] << endl;      
    }else{
        double r = correlation(x_obs, y_obs);
        double m = r * y_sdev / x_sdev;
        double b = y_mean - (m * x_mean);        

        cout << "The sample correlation 'r' is " << r << endl;
        cout << "The least squares regression line is Y = " << m << "*X";
        if (b > 0) cout << "+" << b << endl;
        cout << endl;
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
double stdev(const vector<double> &x_obs){
    double x_bar = mean(x_obs);
    double total = 0.0;
    for (double elem : x_obs){
        total += pow(elem - x_bar, 2);
    }
    return pow( total/(x_obs.size() - 1.0), .5);
}

// Returns the correlation
double correlation(const vector<double> &x_obs, const vector<double> &y_obs){
    double mean_x = mean(x_obs);
    double mean_y = mean(y_obs);
    double stdev_x = stdev(x_obs);
    double stdev_y = stdev(y_obs);
    double nsize = x_obs.size();
    double r=0.0;
    for (int i=0; i < nsize; i++){
        r += ((x_obs[i] - mean_x)/stdev_x)*((y_obs[i] - mean_y)/stdev_y);
    }
    return r / (nsize -1);
}