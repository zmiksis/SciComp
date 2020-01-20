// This file has the implementation details for the Bank_Account class
// Include the header for your class

#include "ex_072_Bank_Account.h"
#include <string>

// We are in the .cpp file, not the .h file, so using namespace std is ok
using namespace std;

// We need to provide definitions for the member functions to the Bank_Account class

// We need to tell the compiler that the member functions belong to the class, by prefacing them
// with the name of the class, followed by ::

// The member functions know that the variables fn, ln, cb and sb below refer to
// the private member data of the particular Bank_Account from which the function was called.


// Constructor, using initializer list style
Bank_Account::Bank_Account(string first, string last, double checking, double savings) 	:fn{first}, ln{last}, cb{checking}, sb{savings} {
}
	// Initialize the members of the class

	// You could also have written the constructor with an older style:
// Bank_Account::Bank_Account(string first, string last, double checking, double savings){
	// fn = first;
	// ln = last;
	// cb = checking;
	// sb = savings;
// }


// To create a variable named my_account of the Bank_Account type,
// you will need to use the constructor, in one of the following ways:
//
// Bank_Account my_account {first, last, checking, savings};
// Bank_Account my_account = {first, last, checking, savings};
// Bank_Account my_account = Bank_Account(first, last, checking, savings);
// Bank_Account my_account(first, last, checking, savings);


// Accessor
std::string Bank_Account::full_name(){
	return fn + " " + ln;
}


// Accessor
std::string Bank_Account::first_name(){
	return fn;
}


// Accessor
std::string Bank_Account::last_name(){
	return ln;
}


// Accessor
double Bank_Account::checking_balance(){
	return cb;
}


// Accessor
double Bank_Account::savings_balance(){
	return sb;
}


// Accessor
double Bank_Account::total_balance(){
	return cb + sb;
}


// Mutator
void Bank_Account::deposit_to_checking(double amount){
	cb = cb + amount;
}


// Mutator
void Bank_Account::deposit_to_savings(double amount){
	sb = sb + amount;
}


// Mutator
void Bank_Account::withdraw_from_checking(double amount){
	cb = cb - amount;
}


// Mutator
void Bank_Account::withdraw_from_savings(double amount){
	sb = sb - amount;
}
