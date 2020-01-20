#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main(){

}

// Resturns smaple mean
double mean(const vector<double> &x_obs){
  double total 0.0;
  for(int i = 0; i < x_obs.size(); i++){
    total += x_obs[i];
  }
  return total/x_obs.size();
}

// Returns sample standard deviation
double st_dev(const vector<double> &x_obs){
  double x_bar = mean(x_obs);
  double total = 0.0;
  for(double elem : x_obs){
    total += pow(elem - x_bar,2);
  }
  return pow(total/(x_obs.size() - 1.), 0.5);
}

// Returns correlation
double cor(const vector<double> &x_obs, const vector<double> &y_obs,
            double &sx, double &sy, double &xbar, double &ybar){
    double r = 0;
    for(int i = 0; i < x_obs.size(); i++){
      r += ((x_obs[i] - xbar)/sx)*((y_obs[i] - ybar)/sy);
    }
    return r/(x_obs.size() - 1);

}
