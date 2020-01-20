// This program uses a command line argument for the user to enter one or two integers.
// If the user enters no integers, the program terminates with an error message.
// If the user enters one integer N, the program computes the sum of the integers from 1 to N inclusive.
// If the user enters two integers M and N, the program computes the sum of the integers from M to N inclusive.
// If the user enters more than two integers, the first two are taken and the rest ignored.

// The function stoi converts strings (either C++ class or C-style) to integers.
// The function stod converts string to doubles (although it is not used in this program).


#include <iostream>
#include <string>
#include <vector>


using namespace std;

int sum_of_integers(int lower, int upper);


int main(int argc, char* argv[]){
	
	int N, M;

	switch(argc){
		case 1: 
			cout << "You didn't enter any integers!" << endl;
			break;
		case 2:
			N = stoi(argv[1]);
			cout << "The sum of the integers from 1 to " << N << " is " << sum_of_integers(1, N) << endl;
			break;
		default:
			M = stoi(argv[1]);
			N = stoi(argv[2]);
			cout << "The sum of the integers from " << M << " to " << N << " is " << sum_of_integers(M, N) << endl;
			break;
	}

	return 0;
}


// This computes the sum of integers from lower to upper inclusive
// with an inefficient approach
int sum_of_integers(int lower, int upper){
	int total = 0;
	for (int i = lower; i <= upper; i++){
		total += i;
	}
	return total;
}
