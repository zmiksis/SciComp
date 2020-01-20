#ifndef WEATHER_H

#define WEATHER_H

#include <string>
#include <vector>

class Weather{
	// Public interface
	public:
		Weather(std::string country, std::string state, std::string town, std::vector<int> temperature, std::vector<int> rain, int projected);

		// Accessors / Getters
		std::string get_full_name();
		float get_final_grade();

		// Mutators / Setters
		void set_final_grade();
	
	// Private interface
	private:
		// Student data
		std::string fn; // First Name
		std::string ln; // Last Name
		std::vector<int> hw; // Homework scores
		std::vector<int> ex; // Exam scores
		int fin; // Final Exam score
		float gp; // Grade percent
};

#endif