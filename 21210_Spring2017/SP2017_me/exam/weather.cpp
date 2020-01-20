#include <algorithm>  // needed for "sort"
#include <functional> // needed for "greater_equal", in sorting function
#include "student.h" // contains student class

using namespace std;

Weather::Weather(string country, string state, string town, vector<int> temperature, vector<double> rain, int avg_temp, double avg_rain){
	cn = country;
	st = state;
	tw = town;
	te = temperature;
	ra = rain;
	avte = avg_temp;
	avra = avg_rain;
}

// Return name of location
string Weather::get_location(){
	return tw + string(", ") + st + string ("(") + cn + string(")");
}

// Return temperatures
double Weather::get_temperature(){
	Weather::calc_temp();	
	return te;
}

double Weather::get_rain(){
	Weather::calc_rain();	
	return ra;
}

void Weather::calc_rain(){
	sort(ra.begin(), ra.end(), greater_equal<int>());
	ra.pop_back();
	ra.push_back(avra);
}

void Weather::calc_temp(){
	te.push_back(avte);
	sort(te.begin(), te.end(), greater_equal<int>());
	te.pop_back();
}