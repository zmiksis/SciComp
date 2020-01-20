// Remember to use header guards!
#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include<vector>


// This class implements a mathematical vector. 
// You could also use the standard template library's valarray type for this sort of behavior (and more),
// but the point of this exercise is to see how one would go about implementing a class
// with the desired properties.

class Math_Vector{

	public:
		
		// Constructors
		Math_Vector();
		Math_Vector(int length);
		Math_Vector(int length, double value);
		Math_Vector(const Math_Vector &v);
		Math_Vector(const std::vector<double> &v);

		// Destructor
		~Math_Vector();


		// Overloaded unary minus. See below for the use of keyword const here.
		Math_Vector operator-() const;

		// Overloading of the subscript operator for const and non-const objects
		// The keyword const here is used to indicate that this function will not
		// modify the Math_Vector from which it is called.
		// This allows them to be called by a const Math_Vector
		// You cannot call non-const functions from const objects.
		double& operator[](const int i);
		const double& operator[](const int i) const;


		Math_Vector& operator=(const Math_Vector &rhs);


		// Member function for obtaining the length of the vector
		// It might be better to use std::size_t instead of int
		int size() const;

	private:
		double * data;
		int v_size;

};
// Remember the trailing semicolon for a class definition!

// You can overload many operators, such as + - * / = etc in C++
// Note that these are NOT member functions, just overloads of the operator
// Use for standard vector addition and subtraction
Math_Vector operator+(const Math_Vector &lvec, const Math_Vector &rvec);
Math_Vector operator-(const Math_Vector &lvec, const Math_Vector &rvec);


// multiply by scalar
Math_Vector operator*(const Math_Vector &lvec, double c);
Math_Vector operator*(double c, const Math_Vector &rvec);
Math_Vector operator/(const Math_Vector &lvec, double c);

// check for equality/inequality
bool operator==(const Math_Vector &lhs, const Math_Vector &rhs);
bool operator!=(const Math_Vector &lhs, const Math_Vector &rhs);


// Non-member versions of dot product and norm
// There is a standard library routine for inner products that you can use with
// the built in template container classes
double dot(const Math_Vector &v1, const Math_Vector &v2);
double norm(const Math_Vector &v, double p = 2.0);

#endif
