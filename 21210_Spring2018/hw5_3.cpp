#include <iostream>  // Needed for console input/output (I/O) operations
#include <fstream>  // Need the file stream for file I/O operations
#include <cmath> // For exponentiation and absolute value

using namespace std;

double func(double &x);
double deriv(double &x);

int main(int argc, char* argv[]){

	int itermax=20;
	double x, xinit=0, tol=1e-7;
    switch(argc){
    	case 4:
            itermax = stoi(argv[3]);	
    	case 3:
    		tol = stod(argv[2]);
    	case 2:
    		xinit = stod(argv[1]);
    		break;
   		default:
   			break;
    }

    ofstream output_file("hw_5_ex_3_output.dat");  // We have a fixed name for the output file

    if(!output_file.is_open()){ // If for any reason we can't open the output file
        cout << endl;
        cout << "Error! Unable to create the specified output file." << endl;
        return 0;
    }    

    output_file << xinit << "\n";

    if (func(xinit) == 0){
    	cout << "Cannot use Newton's method. The derivative is zero at the initial point." << endl;
    	return 0;
    }
    
    int iter = 0;
    x = xinit;
    while((abs(func(x)) >= tol) && (iter < itermax)){
    	double fx = func(xinit); // Function at current value of x
    	double dfx = deriv(xinit); // Derivative at current value of x
    	if (dfx == 0){
    		cout << "Derivative is zero at " << xinit << ". Stopping Newton's method" << endl;
            output_file << "Zero derivative encountered at x="<< x << ". Stopping Newton's method" << endl;
    		break;
    	}else{
    		x = x - (fx / dfx);
    		output_file << x << "\n";
    		iter++;
            xinit = x; // Update current value of x
    	}
    }

    output_file.close();

    cout << "After " << iter << " iterations, the approximate solution is x = " << x << endl; 

	return 0;
}

double func(double &x){
	return pow(x, 5.0) - x + 1;
}

double deriv(double &x){
	return 5*pow(x,4.0) - 1;
}

