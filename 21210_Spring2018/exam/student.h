#ifndef STUDENT_H

#define STUDENT_H

#include <string>
#include <vector>

class Student{
	// Public interface
	public:
		Student(std::string first, std::string last, std::vector<int> homework, std::vector<int> exams, int finalexam);

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