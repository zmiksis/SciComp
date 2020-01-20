#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <iostream>

// class definition for a vector in R^3

class Vector3D{

	public:
		//constructors
		Vector3D();
		Vector3D(const Vector3D &v);
		Vector3D(double x, double y, double z);

		// Assignment operator
		Vector3D& operator=(const Vector3D &RHS);

		// subscript operator mutator
		double& operator[](int n);


		//subscript operator accessor
		const double& operator[](int n) const;


		// unary minus, obtains negative of v
		friend Vector3D operator-(const Vector3D &v);

		// vector addition
		friend Vector3D operator+ (const Vector3D &LHS, const Vector3D &RHS);

		// vector subtraction
		friend Vector3D operator- (const Vector3D &LHS, const Vector3D &RHS);

		// multiplication by a scalar
		friend Vector3D operator* (const Vector3D &LHS, double a);
		friend Vector3D operator* (double a, const Vector3D &RHS);

		
		// equality and inequality
		friend bool operator== (const Vector3D &LHS, const Vector3D &RHS);
		friend bool operator!= (const Vector3D &LHS, const Vector3D &RHS);		


		// non-member function dot product
		friend double dot(const Vector3D &LHS, const Vector3D &RHS);

		// member function dot product
		double dot(const Vector3D &RHS) const;
	
		// a function to check whether a vector is the zero vector.
		// should return true if the vector is the zero vector, and false otherwise
		bool is_zero() const;

		// set all entries to zero with this member function mutator
		void clear();


		// non-member function cross product of u and v
		friend Vector3D cross(const Vector3D &u, const Vector3D &v);

		// member function cross product for cross product with v
		Vector3D cross(const Vector3D &v) const;


		// non-member function norm
		friend double norm(const Vector3D &v);
		
		// member function norm
		double norm() const;


		//non - member function for computing the angle between u and v
		friend double angle (const Vector3D &u, const Vector3D &v);

		// member function for finding the angle with v
		double angle(const Vector3D &v) const;

		// function for printing a Vector3D
		friend std::ostream& operator<<(std::ostream &os, const Vector3D &v);



	private:
		double x;
		double y;
		double z;

};

#endif
