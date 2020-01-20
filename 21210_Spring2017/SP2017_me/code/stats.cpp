#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

double mean(const vector<double> &x_obs);
double stdev(const vector<double> &x_obs);
double correlation(const vector<double> &x_obs, const vector<double> &y_obs);

int main(int argc, char* argv[]){

    vector<double> x_obs;
    vector<double> y_obs;    

    if (argc == 1){
        cout << "Error! You did not specify a data file name in the command line argument.\nNow exiting.\n" << endl;
        return 0;
    }

    ifstream input_file(argv[1]);

    if (!input_file.is_open()){
        cout << "Error: data file could not be opened.\nNow exiting.\n" << endl;
        return 0;
    }

    {
        string xob; string yob;
        while (input_file >> xob >> yob){
            x_obs.push_back(stod(xob));
            y_obs.push_back(stod(yob));
        }
    }

    if (input_file.eof()){
        cout << endl;
        cout << "Data file read successfully. End of data file successfully reached." << endl;
        cout << endl;
    }else if (!input_file.good()) {
        cout << "Something went wrong!" << endl;
        return 0;
    }

    input_file.close();

    double xmean = mean(x_obs);
    double ymean = mean(y_obs);
    double xsdev = stdev(x_obs);
    double ysdev = stdev(y_obs);

    cout << "The sample mean of x is " << xmean << endl;
    cout << "The sample mean of y is " << ymean << endl;
    cout << "The sample standard deviation of x is " << xsdev << endl;
    cout << "The sample standard deviation of y is " << ysdev << endl;    

    if (xsdev==0){
        cout << "Since the standard deviation of x is 0, " << endl;
        cout << " the sample correlation and least squares " << endl;
        cout << " regression line are both undefined." << endl;
    }else if (ysdev == 0){
        cout << "Since the standard deviation of y is 0, " << endl;
        cout << " the sample correlation and least squares " << endl;
        cout << " regression line are both undefined." << endl;
    }else {
        double r = correlation(x_obs, y_obs);
        double m = r * ysdev / xsdev;
        double b = ymean - (m * xmean);        

        cout << "The sample correlation 'r' is " << r << endl;
        cout << "The least squares regression line is Y = (" << m << ")X";
        if (b > 0) cout << "+" ;
        cout << b << endl;
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
    double meanx = mean(x_obs);
    double meany = mean(y_obs);
    double stdevx = stdev(x_obs);
    double stdevy = stdev(y_obs);
    double nsize = x_obs.size();
    double r=0.0;
    for (int i=0; i < nsize; i++){
        r += ((x_obs[i] - meanx)/stdevx)*((y_obs[i] - meany)/stdevy);
    }
    return r / (nsize -1);
}