#include "Vector3D.h"
#include <iostream>
#include <cmath>

using namespace std;


// Write implementations of all the other functions declared in Vector.h below!










ostream& operator<<(ostream &os, const Vector3D &v){
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}
