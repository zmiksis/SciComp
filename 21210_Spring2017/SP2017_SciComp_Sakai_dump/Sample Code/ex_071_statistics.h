// This is the header file for ex_071_statistics.cpp
// It contains declarations for the functions in statistics.cpp


// The following lines are 'header guards'
// They prevent the contents of the header file from being included multiple times
// If STATISTICS_H was already defined by the preprocessor, the header's contents would not be
// included again

#ifndef STATISTICS_H
#define STATISTICS_H

// We need to include vector for these declarations to make sense
#include <vector>

// You should avoid incorporating 'using namespace ...' in your headers
// as it might cause unexpected behavior due to different naming conventions
// in programs that use your code. This is not an issue in small programs that
// you personally maintain, but might be a problem if you work on a larger project with
// collaborators who need to use your code.

// Now, put the declarations (but not definitions) of the functions in your corresponding .cpp file
// for which this is the header.

double mean(const std::vector<double> &x);
double std_dev(const std::vector<double> &x);
double median(std::vector<double> x);


// Place after the portion we would like to include if the header has not already been included
#endif
