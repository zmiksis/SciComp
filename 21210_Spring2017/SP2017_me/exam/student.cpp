#include <algorithm>  // needed for "sort"
#include <functional> // needed for "greater_equal", in sorting function
#include "student.h" // contains student class

using namespace std;

Student::Student(string first, string last, vector<int> homework, vector<int> exams, int finalexam){
	fn = first;
	ln = last;
	hw = homework;
	ex = exams;
	fin = finalexam;
}

// Concatenate last name and first name
string Student::get_full_name(){
	return ln + string(", ") + fn;
}

// Calculate and return final grade
float Student::get_final_grade(){
	Student::set_final_grade();	
	return gp;
}

// Calculates the final grade
void Student::set_final_grade(){
	sort(hw.begin(), hw.end(), greater_equal<int>()); // Arrange in descending order
	hw.pop_back(); // Remove the least homework score

	// Add up homework scores, to make up 100 maximum points
	float hwpoints = 0.0;
	for (int k=0; k < hw.size(); k++){
		hwpoints += hw[k];
	}
	
	ex.push_back(fin); // Add final exam to the set of exams
	sort(ex.begin(), ex.end(), greater_equal<int>()); // Arrange in descending order	
	ex.pop_back(); // Remove the least exam score
	
	// Add up exam scores to make up 300 maximum points
	float expoints = 0.0;
	for (int i=0; i < ex.size(); i++){
		expoints += ex[i];
	}

	// scale final exam to 150
	float fin_scaled = fin * 150.00/100;

	// add up and scale to a percentage
	gp = ((hwpoints + expoints + fin_scaled) / 550.00) * 100;
}