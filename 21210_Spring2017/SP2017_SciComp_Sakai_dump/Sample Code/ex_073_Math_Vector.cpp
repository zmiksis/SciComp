#include "ex_073_Math_Vector.h"

#include <cmath>
#include <vector>

using namespace std;


Math_Vector::Math_Vector() {
	v_size = 0;
	data = nullptr;
}

// Zero initialize the elements
Math_Vector::Math_Vector(int length) {
	if (length > 0) {
		v_size = length;
		data = new double[v_size];
		for(int i = 0; i < v_size; i++){
			data[i] = 0.0;
		}
	} else {
		v_size = 0;
		data = nullptr;
	}
}

// Initialize all elements to value
Math_Vector::Math_Vector(int length, double value) {
	if (length > 0){
		v_size = length;
		data = new double[v_size];
		for(int i = 0; i < v_size; i++){
			data[i] = value;
		}
	} else {
		v_size = 0;
		data = nullptr;
	}
}


// Copy constructor
Math_Vector::Math_Vector(const Math_Vector &v){
	// We can directly access the private data of another object of the same exact class
	// from a member function using a . for member access
	if (v.v_size > 0){
		v_size = v.v_size;
		data = new double[v_size];
		for(int i = 0; i < v_size; i++){
			data[i] = v[i];
		}
	} else {
		v_size = 0;
		data = nullptr;
	}
}

// Make a Math_Vector out of a std::vector<double>
Math_Vector::Math_Vector(const std::vector<double> &v){
	if (v.size() > 0){
		v_size = v.size();
		data = new double[v_size];
		for(int i = 0; i < v_size; i++){
			data[i] = v[i];
		}
	} else {
		v_size = 0;
		data = nullptr;
	}
}

// The destructor needs to free up resources used by the object
Math_Vector::~Math_Vector(){
	// Must free dynamic memory
	delete[] data;
}

Math_Vector Math_Vector::operator-() const{
	Math_Vector w(v_size);
	for (int i = 0; i < v_size; i++){
		w[i] = -data[i];
	}
	return w;
}

double& Math_Vector::operator[](const int i){
	return data[i];
}

const double& Math_Vector::operator[](const int i) const{
	return data[i];
}

int Math_Vector::size() const{
	return v_size;
}


Math_Vector& Math_Vector::operator=(const Math_Vector &rhs){
	// Check for self-assignment
	// this is a keyword that is used for a pointer to the object that called the member function.
	// Every member function of a class has access to the 'this' keyword
	if (this == &rhs){
		// If the calling object is the exact same as the RHS of the assignment, 
 		// we do not need to do anything
		return *this;
	}

	// Otherwise, clear out the currently held data
	delete[] data;
	v_size = rhs.v_size;
	
	if (v_size == 0){
		data = nullptr;
	} else {

		data = new double[v_size];
		for (int i = 0; i < v_size; i++){
			data[i] = rhs[i];
		}
	}
	
	// Return the object itself by reference
	return *this;
}
	


// Non-member functions below

Math_Vector operator+(const Math_Vector &lvec, const Math_Vector &rvec){
	if(lvec.size() != rvec.size()){
		// Return a Math_Vector with no length and no entries
		Math_Vector v;
		return v;
	}
	
	// Create a Math_Vector of the correct size	
	Math_Vector v(lvec.size());
	for (int i = 0; i < v.size(); i++){
		v[i] = lvec[i] + rvec[i];
	}
	
	return v;
}

Math_Vector operator-(const Math_Vector &lvec, const Math_Vector &rvec){
	if(lvec.size() != rvec.size()){
		// Return a Math_Vector with no length and no entries
		Math_Vector v;
		return v;
	}
	
	// Create a Math_Vector of the correct size	
	Math_Vector v(lvec.size());
	for (int i = 0; i < v.size(); i++){
		v[i] = lvec[i] - rvec[i];
	}
	
	return v;
}


Math_Vector operator*(const Math_Vector &lvec, double c) {

	Math_Vector w( lvec.size() );
	for (int i = 0; i < w.size(); i++){
		w[i] = lvec[i] * c;
	}
	return w;
}

Math_Vector operator*(double c, const Math_Vector &rvec){

	Math_Vector w( rvec.size() );
	for (int i = 0; i < w.size(); i++){
		w[i] = rvec[i] * c;
	}
	return w;
}

Math_Vector operator/(const Math_Vector &lvec, double c){
	Math_Vector w( lvec.size() );
	for (int i = 0; i < w.size(); i++){
		w[i] = lvec[i] / c;
	}
	return w;
}

// You could also implement this as a 'friend' function in order to access the private data
// of the Math_Vector class directly
bool operator==(const Math_Vector &lhs, const Math_Vector &rhs){
	if (lhs.size() != rhs.size() ){
		return false;
	}

	for (int i = 0; i < lhs.size(); i++){
		if (lhs[i] != rhs[i]){
			return false;
		}
	}
	return true;
}

// Just use the existing == and negate it
bool operator!=(const Math_Vector &lhs, const Math_Vector &rhs){
	return !(lhs == rhs);
}

double dot(const Math_Vector &v1, const Math_Vector &v2){
	if (v1.size() != v2.size()){
		return nan("");
	}

	double total = 0.0;
	for (int i = 0; i < v1.size(); i++){
		total += v1[i] * v2[i];
	}
	return total;
}


double norm(const Math_Vector &v, double p) {
	double total = 0.0;
	for (int i = 0; i < v.size(); i++){
		total += pow(v[i], p);
	}
	return pow(total, 1.0/p);
}
