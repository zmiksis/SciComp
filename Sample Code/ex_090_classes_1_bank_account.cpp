// This program will create a variable of the type Bank_Account (which is defined in a separate header file)
// It will then use some of the member functions of that class

#include <iostream>
#include <string>
#include <iomanip>

#include "ex_090_Bank_Account.h"


using namespace std;

int main(){

	double checking_withdrawal_amount;
	double savings_deposit_amount;

	// Create a new object of the Bank_Account type with the owner John Doe
	// and 1000 in checking and 2000 in savings.
	Bank_Account user_account("John", "Doe", 1000.00, 2000.00);

	

	cout << endl << fixed << setprecision(2);

	cout << "Initially " << user_account.full_name() << " has " << 
				user_account.checking_balance() << " in checking and " <<
				user_account.savings_balance() << " in savings,\n for a total of " << 
				user_account.total_balance() << "." << endl << endl;

	cout << "Please enter an amount to withdraw from checking: ";
	cin >> checking_withdrawal_amount;
	cout << "Please enter an amount to deposit into savings: ";
	cin >> savings_deposit_amount;
	

	// Call the member functions to make a withdrawal and a deposit
	user_account.withdraw_from_checking(checking_withdrawal_amount);
	user_account.deposit_to_savings(savings_deposit_amount);

	cout << endl;
	cout << "After withdrawing " << checking_withdrawal_amount << " from checking and depositing " << 
				savings_deposit_amount << " to savings, \n";
	cout << user_account.full_name() << " has " << user_account.checking_balance() << " in checking and " << 
				user_account.savings_balance() << " in savings, for a total of " << user_account.total_balance() << "." << endl << endl;

	

	return 0;
}
