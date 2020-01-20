#include <iostream>
#include <string>

#include "Vector3D.h"


using namespace std;

int main(){

	Vector3D zero_vector;
	
	Vector3D vector_i(1, 0, 0);
	Vector3D vector_j(0, 1, 0);
	Vector3D vector_k(0, 0, 1);

	Vector3D u = 2 * vector_i + vector_j + 2*vector_k;
	Vector3D v = -2 * vector_i + vector_j * 4;
	Vector3D w( u+v +vector_j + vector_k * 6);

	cout << endl;
	cout << "Checking whether zero_vector really is the zero_vector..." << endl;
	if (zero_vector.is_zero()){
		cout << "Success, zero_vector really is zero!" << endl;
	} else {
		cout << "Something went wrong, zero_vector might not be zero, or the function might not work correctly!" << endl;
	}

	cout << endl;
	cout << "Checking whether vector_i is the zero vector..." << endl;
	if( vector_i.is_zero()){
		cout << "Somethign went wrong, your function claims that vector_i is the zero vector." << endl;
	} else {
		cout << "Success, vector_i is not the zero vector!" << endl;
	}

	
	cout << endl;
	cout << "Clearing vector_i, and checking to see whether the resulting vector is the zero vector..." << endl;
	vector_i.clear();
	if( vector_i.is_zero()){
		cout << "Success, vector_i was cleared successfully. Resetting vector_i..." << endl;
		vector_i = Vector3D(1, 0, 0);
	} else {
		cout << "Something went wrong, vector_i was not cleared successfully!" << endl;
	}
	

	cout << endl;
	cout << "u == " << u << endl;
	cout << "v == " << v << endl;
	cout << "w == " << w << endl;	

	cout << endl;
	cout << "The length of u is: " << u.norm() << endl;
	cout << "The length of v is: " << norm(v) << endl;
	cout << "The length of w is: " << w.norm() << endl;


	cout << endl;
	cout << "The dot product of u and v is: " << u.dot(v) << endl;
	cout << "The dot product of u and w is: " << dot(u, w) << endl;
	cout << "The dot product of v and w is: " << v.dot(w) << endl;

	cout << endl;
	cout << "The angle between u and v is: " << u.angle(v) << endl;
	cout << "The angle between u and w is: " << angle(u, w) << endl;
	cout << "The angle between v and w is: " << v.angle(w) << endl;

	cout << endl;
	cout << "The cross product of u and v is: " << u.cross(v) << endl;
	cout << "The cross product of u and w is: " << cross(u, w) << endl;
	cout << "The cross product of v and w is: " << v.cross(w) << endl;

	cout << endl;
	// Check for anti-commutative property of cross product in a specific example:
	if (cross(u, v) == - cross(v, u)){
		cout << "The cross product of u and v is the negative of the cross product of v and u!" << endl;
	} else {
		cout << "Something went wrong, the cross product of u and v was not the negative of the cross product of v and u!" << endl;
	}

	cout << endl;
	cout << "Testing whether or not i == j..." << endl;
	if (vector_i != vector_j){
		cout << vector_i << " is not equal to " << vector_j << endl;
	} else {
		cout << "Something went wrong, we found that " << vector_i << " == " << vector_j << endl;
	}

	cout << endl;
	cout << "Now changing the entries of v..." << endl;
	for (int i = 0; i < 3; i++){
		v[i] = 2*i + 1;
	}
	
	cout << "v is now: " << v << endl;
	double total = 0.0;
	for(int i = 0; i < 3; i++){
		total += v[i];
	}
	cout << "The sum of the entries of v is: " << total << endl;


	return 0;
}
