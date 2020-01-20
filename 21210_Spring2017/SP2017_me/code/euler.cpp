#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){   

    if (argc < 3){
        cout << endl;
        cout << "Error! You need to specify the number of subintervals followed by the output filename.\nNow exiting.\n" << endl;
        return 0;
    }

    int N = stoi(argv[1]);
    double h = 1.0/N;

    ofstream output_file(argv[2]);

	if(!output_file.is_open()){
		cout << endl;
		cout << "Error! Unable to create the specified output file." << endl;
		return 0;
	}
	
	{
		double xval = 0.0;
		double yval = 0.0;

	    double xinit = 0.0;
	    double yinit = 1.0;	

		for (int i=0; i <= N; i++){				
			yval = yinit + yval*h;
			xval = xinit + xval*h;
			output_file << setprecision(12) << xinit + i*h << " " << yval << '\n';

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