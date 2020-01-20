#include <iostream>
#include <cmath>
#include <vector>

#include "ex_073_Math_Vector.h"


using namespace std;

void print_Math_Vector(const Math_Vector &v);

int main(){

	int N = 5;
	// Make u a Math_Vector with N entries, all of which are initialized to zero
	Math_Vector u(5, 0);

	
	for(int i = 0; i < u.size(); i++){
		u[i] = 2 *i;
	}

	Math_Vector v(N, 2);
	for (int i = 0; i < v.size(); i++){
		v[i] = pow(i, 2);
	}


	Math_Vector w;
	w = u + v;

	cout << endl;
	cout << "The entries of u are: " << endl;
	print_Math_Vector(u);
	
	cout << endl;
	cout << "The entries of v are: " << endl;
	print_Math_Vector(v);

	cout << endl;
	cout << "The entries of w are: " << endl;
	print_Math_Vector(w);

	
	cout << endl << endl; 
	cout << "The norm of u is: " << norm(u) << endl;
	cout << "The norm of v is: " << norm(v) << endl;
	cout << "The dot product of u and v is: " << dot(u, v) << endl;

	
	// Since we have operators for +, -, * and /, the next section reads like ordinary mathematics!
	w = w - 2.0 *u;
	w = -w * 2.0;
	w = w/4.0;
	w = 2 * ( u + w );

	cout << endl;
	cout << "After some vector arithmetic, the entries of w are: " << endl;
	print_Math_Vector(w);
	
	cout << endl;
	return 0;	
}


void print_Math_Vector(const Math_Vector &v){
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}
	return;
}
