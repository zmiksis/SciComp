#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

double mean(const vector<double> &x_obs);
double st_dev(const vector<double> &x_obs);
double cor(const vector<double> &x_obs, const vector<double> &y_obs,
           double &sx, double &sy, double &xbar, double &ybar);

int main(){

  double m;
  double b;
  double r;
  double xbar;
  double ybar;
  double sx;
  double sy;

  vector<double> x_obs;
  vector<double> y_obs;

  {
    double temp_x;
    double temp_y;
    cout << "Enter a pair of values, x and y: ";
    while(cin >> temp_x >> temp_y){
      x_obs.push_back(temp_x);
      y_obs.push_back(temp_y);
      cout << "Enter a pair of values, x and y: ";
    }
  }

  if(x_obs.size() == 0 || x_obs.size() == 1){
    cout << "Number of entries is too small!" << endl;
    return 0;
  }

  xbar = mean(x_obs);
  ybar = mean(y_obs);
  sx = st_dev(x_obs);
  sy = st_dev(y_obs);

  if(sx == 0){
    cout << "Correlation and regression line undefined!" << endl;
    return 0;
  }
  if(sy == 0 && sx != 0){
    cout << "Correlation undefined! Regression line equation is:" << endl;
    cout << "     yhat = " << y_obs[0] << endl;
    return 0;
  }

  r = cor(x_obs,y_obs,sx,sy,xbar,ybar);
  m = r*(sy/sx);
  b = ybar - m*xbar;

  cout << "The sample mean of x is: " << xbar << endl;
  cout << "The sample mean of y is: " << ybar << endl;
  cout << "The sample standard deviation of x is: " << sx << endl;
  cout << "The sample standard deviation of y is: " << sy << endl;
  cout << "The sample correlation is: " << r << endl;
  cout << "The least squares regression line is: yhat = " << m << "x + " << b << endl;

  return 0;

}

// Returns the sample mean
double mean(const vector<double> &x_obs){
	double total = 0.0;
	for (int i = 0; i < x_obs.size(); i++){
		total += x_obs[i];
	}
	return total/x_obs.size();
}

// Returns the sample standard deviation
// Note that this will not work correctly if x_obs has only one entry
double st_dev(const vector<double> &x_obs){
	double x_bar = mean(x_obs);
	double total = 0.0;
	for (double elem : x_obs){
		total += pow(elem - x_bar, 2);
	}
	return pow( total/(x_obs.size() - 1.0), .5);
}

double cor(const vector<double> &x_obs, const vector<double> &y_obs,
           double &sx, double &sy, double &xbar, double &ybar){
  double r = 0;
  for(int i = 0; i < x_obs.size(); ++i){
    r += ((x_obs[i]-xbar)/sx)*((y_obs[i]-ybar)/sy);
  }
  r = r/(x_obs.size()-1);
  return r;
}
