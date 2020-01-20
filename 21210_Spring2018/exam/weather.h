#ifndef WEATHER_H

#define WEATHER_H

#include <string>
#include <vector>

class Weather{
	// Public interface
	public:
		Weather(std::string country, std::string state, std::string town, std::vector<int> temperature, std::vector<double> rain, int avg_temp, double avg_rain);

		// Accessors / Getters
		std::string get_location();
		double get_temperature();
		double get_rain();

		// Mutators / Setters
		void calc_rain();
		void calc_temp();
	
	// Private interface
	private:
		// Weather data
		std::string cn; // Country
		std::string st; // State
		std::string tw; // Town
		std::vector<int> te; // temperature
		std::vector<double> ra; // rainfall
		int avte; // Average temperature
		double avra; // Average rainfall
};

#endif