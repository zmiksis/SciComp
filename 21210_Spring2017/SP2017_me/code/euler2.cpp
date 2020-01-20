#include <iostream>
#include <iomanip>
#include <fstream>
#include "hw61f.h"

using namespace std;

int main(int argc, char* argv[]){   

    if (argc < 5){
        cout << endl;
        cout << "Error! You need to specify the initial value, the end-point, number of subintervals and the output filename.\nNow exiting.\n" << endl;
        return 0;
    }

    double yinit = stod(argv[1]);

    double xinit = 0.0;
    double b = stod(argv[2]);

    int N = stoi(argv[3]);
    double h = (b-xinit)/N;

    ofstream output_file(argv[4]);

	if(!output_file.is_open()){
		cout << endl;
		cout << "Error! Unable to create the specified output file." << endl;
		return 0;
	}
	
	{
		double xval = 0.0;
		double yval = 0.0;

	    output_file << setprecision(12) << xinit << " " << yinit;

		for (int i=0; i < N; i++){				
			yval = yinit + h*f(xval,yinit);
			xval = xinit + h;
			output_file << '\n' << setprecision(12) << xval << " " << yval;

			yinit = yval;
			xinit = xval;
		}
	}

	output_file << flush;
	output_file.close();

	cout << "Data file written successfully." << endl;
	cout << endl;

	return 0;
}

double f(double x, double y){
	return x * y;
}