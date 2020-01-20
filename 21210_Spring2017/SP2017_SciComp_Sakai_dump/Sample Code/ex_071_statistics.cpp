// Include the header for your .cpp files which do not have main routines
#include "ex_071_statistics.h"

#include <cmath>
// Included to have access to the sort( ) function
#include <algorithm>


using namespace std;

// Now put the definitions for the functions declared in the header

double mean(const vector<double> &x){
	double total = 0.0;
	
	// Use auto to automatically detect the type of elements
	// Avoid overusing auto, as it may make it harder for the reader to determine types
	for (auto elem : x){
		total += elem;
	}
	return total/x.size();
}

double std_dev(const vector<double> &x){
	double x_bar = mean(x);
	double total = 0.0;
	for (auto elem : x){
		total += pow(elem - x_bar, 2.0);
	}
	return pow(total/(x.size() - 1.0), .5);
}

// Note that we have not passed by reference because sort performs a sort in place
double median(vector<double> x){
	// The vector has to be sorted to compute the median.
	// This uses the sort function from the algorithm library,
	// which is a good general purpose sorting algorithm
	sort(x.begin(), x.end());
	if (x.size() % 2 == 1){
		return x[(x.size() - 1)/2];
	} else {
		return (x[x.size()/2 - 1] + x[x.size()/2])/2.0;
	}
}
