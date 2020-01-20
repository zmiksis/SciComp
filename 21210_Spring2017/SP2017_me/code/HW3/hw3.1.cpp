// Distances program
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> distances;

    double total_distance=0.0, least_distance=0.0, most_distance=0.0;
	double temp;

	cout << "Program for summing and comparing distances." << endl;
	cout << "Enter a sequence of distances between the cities separated by spaces or the enter key." << endl;
	cout << "To stop entering distances, use a negative number or a string." << endl;
	cout << endl;

	while(cin >> temp && temp >= 0){
	    distances.push_back(temp);
	    
        if (distances.size() == 1){
            least_distance = temp;
            most_distance = temp;
        }
        
		total_distance += temp;
		if (temp < least_distance) least_distance = temp;
		if (most_distance < temp) most_distance = temp;
	}
    cout << "Total distance =" << total_distance << endl;
    cout << "Least distance = " << least_distance << endl;
	cout << "Most distance = " << most_distance << endl;
	cout << "Mean distance = " << total_distance/distances.size() << endl;
    return 0;   
}
