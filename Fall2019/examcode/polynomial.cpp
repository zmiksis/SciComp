#include "polynomial.h"
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


polynomial::polynomial(){
	coefficients = vector<double> (1, 0.0);
}

polynomial::polynomial(const polynomial &p){
	coefficients = p.coefficients;
}

polynomial::polynomial(double x){
	coefficients = vector<double> (1, x);
}

polynomial::polynomial(const vector<double> &coefs){
	coefficients = coefs;
	while(coefficients.size() > 1 && coefficients.back() == 0.0){
		coefficients.pop_back();
	}
}


polynomial& polynomial::operator=(const polynomial &q){
	this->coefficients = q.coefficients;
}

polynomial& polynomial::operator=(double c){
	this->coefficients = polynomial(c).coefficients;
}




const double& polynomial::operator[](int n) const {
	return coefficients[n];
}

double& polynomial::operator[](int n) {
	/*
	if (n >= coefficients.size()){
		coefficients.resize(n+1);
		return coefficients[n];
	} else {
		return coefficients[n];
	}
*/
	return coefficients[n];
}


polynomial operator+(const polynomial &p, const polynomial &q){
	vector<double> new_coefficients ( max(p.degree(), q.degree()) + 1);
	for(int i = 0; i < new_coefficients.size(); i++){
		if(i < p.coefficients.size() && i < q.coefficients.size()){
			new_coefficients[i] = p[i] + q[i];
		} else if(i < p.coefficients.size()){
			new_coefficients[i] = p[i];
		} else {
			new_coefficients[i] = q[i];
		}
	}

	while(new_coefficients.size() > 1 && new_coefficients.back() == 0.0){
		new_coefficients.pop_back();
	}

	return polynomial(new_coefficients);
}

polynomial operator+(const polynomial &p, double c){
	return p + polynomial(c);
}

polynomial operator+(double c, const polynomial &p){
	return p + c;
}


polynomial operator-(const polynomial &p, const polynomial &q){
	vector<double> new_coefficients ( (max(p.degree(), q.degree()) + 1) );
	for(int i = 0; i < new_coefficients.size(); i++){
		new_coefficients[i] = p[i] - q[i];
	}
	
	while(new_coefficients.size() > 1 && new_coefficients.back() == 0.0){
		new_coefficients.pop_back();
	}

	return polynomial(new_coefficients);
}
	
polynomial operator-(const polynomial &p, double c){
	return p - polynomial(c);
}


polynomial operator-(double c, const polynomial &p){
	return polynomial(c) - p;
}




polynomial operator*(const polynomial &p, const polynomial &q){

	vector<double> new_coefficients( p.degree() + q.degree() + 1, 0.0);

	for(int power = 0; power < new_coefficients.size(); power++){
		for(int i = 0; i <= power; i++){
			if(0 <= i && i < p.coefficients.size() && 0 <= power-i && power-i < q.coefficients.size()){
				new_coefficients[power] += p.coefficients[i] * q.coefficients[power-i];
			}
		}
	}

	while(new_coefficients.size() > 1 && new_coefficients.back() == 0.0){
		new_coefficients.pop_back();
	}

	return polynomial(new_coefficients);
}



polynomial operator*(const polynomial &p, double c){
	if (c == 0.0){
		return polynomial(0.0);
	} else {
		vector<double> new_coefficients(p.coefficients);
		for(int i = 0; i < new_coefficients.size(); i++){
			new_coefficients[i] *= c;
		}

		while(new_coefficients.size() > 1 && new_coefficients.back() == 0.0){
			new_coefficients.pop_back();
		}

		return polynomial(new_coefficients);
	}
}

polynomial operator*(double c, const polynomial &p){
	return p * c;
}

polynomial operator/(const polynomial &p, double c){
	return p * (1.0/c);
}

polynomial operator-(const polynomial &p){
	polynomial q(p);
	for(int i = 0; i < q.coefficients.size(); i++){
		q[i] = -q[i];
	}
	return q;
}

double polynomial::operator()(double x) const {
	double total = 0.0;
	for(int i = 0; i < coefficients.size(); i++){
		total += coefficients[i] * pow(x, i);
	}
	return total;
}

bool operator==(const polynomial &p, const polynomial &q){
	return p.coefficients == q.coefficients;
}

bool operator==(const polynomial &p, double c){
	return p == polynomial(c);
}

bool operator==(double c, const polynomial &p){
	return p == c;
}

			
bool operator!=(const polynomial &p, const polynomial &q){
	return !(p == q);
}

bool operator!=(const polynomial &p, double c){
	return !(p == c);
}


bool operator!=(double c, const polynomial &p){
	return !(p == c);
}



void polynomial::clear(){
	coefficients.resize(1);
	coefficients[1] = 0.0;
	return;
}


int polynomial::degree() const {
	return coefficients.size() - 1;
}



ostream& operator<<(ostream &os, const polynomial &p){
	os << p.coefficients[0];
	for(int i = 1; i < p.coefficients.size(); i++){
		double ai = p.coefficients[i];
		if( ai < 0 ){
			os << " - " << abs(ai);
		} else {
			os << " + " << abs(ai);
		}
		os << "x^" << i;
	}
	return os;
}


polynomial create_monomial(int n){
	vector<double> new_coefficients((n+1), 0.0);
	new_coefficients[n] = 1.0;
	return polynomial(new_coefficients);
}

polynomial pow(const polynomial &p, int n){
	if (n < 0){
		return polynomial(0.0);
	}
	polynomial q(vector<double>(1, 1.0));
	for(int i = 1; i <= n; i++){
		q = (q * p);
	}
	return q;
}
