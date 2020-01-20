#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream> // To open file

using namespace std;

double mean(const vector<double> &x_obs);
double st_dev(const vector<double> &x_obs);
double cor(const vector<double> &x_obs, const vector<double> &y_obs,
           double &sx, double &sy, double &xbar, double &ybar);
vector<double> process_line(string line); // To process each line

int main(int argc, char * argv[]){ // To take input

  // Check input
  if (argc == 1){
		cout << "You did not enter any file names!" << endl;
		return 0;
	}

  // Open file
  string file_name = argv[1];
  ifstream ifs;
  ifs.close();
	ifs.clear();
  ifs.open(file_name);

	if (!	ifs.is_open()){
		cout << endl << "Could not open the file " << file_name << endl << endl;
		return 0;
	}

  // Store all values in vector data
  vector<vector<double>> data;
  string line;
  while(getline(ifs, line)){
		data.push_back(process_line(line));
	}

  // Close stream
  ifs.close();
	ifs.clear();

  vector<double> x_obs;
  vector<double> y_obs;

  for(int i = 0; i < data.size(); ++i){
    x_obs.push_back(data[i][1]);
    y_obs.push_back(data[i][2]);
  }

  double m;
  double b;
  double r;
  double xbar;
  double ybar;
  double sx;
  double sy;

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

vector<double> process_line(string line){

	// Store the entries in a given line in a vector of doubles
	// that we will add to, one at a time
	vector<double> entries;

	// Start out building the double from an empty string and adding characters as they are encountered
	string built_double = "";


	// Iterate over all characters in the line
	// You can use the .size() function to find the length of a string
	// and access the characters in a string using []
	for(int i = 0; i < line.size(); i++){

		// Any time you encounter a comma, you have reached the end of the current double
		if (line[i] == ','){
			// Convert the string, whose contents are the double in question, to a double
			// using the stod function
			entries.push_back(stod(built_double));
			// Reset the double you are building to an empty state to build a new one
			built_double = "";
		} else {
			// If you have yet to reach a comma, you can still build
			built_double = built_double + line[i];
		}
	}

	// Add the last double, which does not have a comma following it
	entries.push_back(stod(built_double));

	return entries;
}
