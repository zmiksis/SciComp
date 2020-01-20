// Remember to use header guards!
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H


#include <string>

// Remember NOT to have 'using namespace std' in a header file


// We will make a user defined type to simulate a bank account
// with both a checking and savings balance. 
class Bank_Account{
	
	// Functions under the public access specifier.
	// You could also have data as well, but this class does not have any public data.
	// These functions (or class members) can be accessed outside the class.
	// These form the 'interface' to the class, the part that users can interact with.
	public:
		// The constuctor to make a new object of the Bank_Account type - note that it has the same name as the class
		Bank_Account(std::string first, std::string last, double checking, double savings);

		// Declarations of member functions. It is possible to supply definitions here, but we will do that in
		// the corresponding .cpp file instead

		// The following member functions are accessors, used to obtain (get) the values of the private class data
		std::string full_name() const;
		std::string first_name() const;
		std::string last_name() const;
		double checking_balance() const;
		double savings_balance() const;
		double total_balance() const;

		// The next few member functions are mutators, used to change (set) the values of the private class data 

		void deposit_to_checking(double amount);
		void deposit_to_savings(double amount);
		void withdraw_from_checking(double amount);
		void withdraw_from_savings(double amount);

	// Data and functions under the private access specifier.
	private:
		// We will store a first name, last name, checking balance, and savings balance for our customer's account
		std::string fn;
		std::string ln;
		double cb;
		double sb;

};
// Note: you need a semicolon after the closing brace for a class definition in C++!

#endif
