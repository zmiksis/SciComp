#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


double mean(const vector<double> &x_obs);
double st_dev(const vector<double> &x_obs);
void print_double_vec(const vector<double> &a, bool print_newline = true);

int main(){

	double user_avg;
	double user_st_dev;

	vector<double> user_data;	
		
	// Placing temp and the loop inside a block of code
	// with curly braces makes it so that temp goes out of scope
	// at the end of the block.
	{ 
		double temp;
		cout << "Enter a real number (or string to exit): ";
		while(cin >> temp){
			user_data.push_back(temp);
			cout << "Enter another real number (or string to exit): ";
		}
	}

	user_avg = mean(user_data);
	user_st_dev = st_dev(user_data);
	
	cout << endl << "The data that you entered was:" << endl;
	print_double_vec(user_data);
	
	cout << endl << "The mean of your data was: " << user_avg << endl;
	cout << "The sample standard deviation of your data was: " << user_st_dev << endl;	

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
// Note that this will not work correctly if x_obs has only one or two entries
double st_dev(const vector<double> &x_obs){
	double x_bar = mean(x_obs);
	double total = 0.0;
	for (double elem : x_obs){
		total += pow(elem - x_bar, 2);
	}
	return pow( total/(x_obs.size() - 1.0), .5);
}	

void print_double_vec(const vector<double> &a, bool print_newline){

	// Don't print anything if the vector has size 0
	if (a.size() == 0){
		return;
	}

	// This loop iterates through all the elements except the last, and accesses and prints the element
	// and a comma.
	for (int i = 0; i < a.size() - 1; i++){
		cout << a[i] << ", ";
	}
	
	// Print the last element without a comma
	cout << a[a.size() - 1];
	
	// Optionally print a newline
	if (print_newline) {
		cout << endl;
	}

	return;	
}
