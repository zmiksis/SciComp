#include <iostream>
#include <iomanip>
#include <random>
#include <functional>
#include <vector>
#include <ctime>

using namespace std;

int main(int argc, char* argv[]){  

    clock_t begin = clock();

    if (argc < 3){
        cout << endl;
        cout << "Error! You need to specify one side of the square board\'s dimensions, and the number of trials.\nNow exiting.\n" << endl;
        return 0;
    }

    int N = stoi(argv[1]);
    long long int trials = stoll(argv[2]);

    if (N < 3){
        cout << endl;
        cout << "Error! The dimensions of the board should be at least 3 by 3\nNow exiting.\n" << endl;
        return 0;
    } 

    random_device rd;
    int seed = rd(); // Seed only once
    mt19937 seedmaker(seed); // Generate pseudo-random numbers
    uniform_int_distribution<int> choices(0, 7); // Maximum of 8 possible knight moves
    auto select = bind(choices, seedmaker); // Random move selector

    cout << endl;
    cout << "Running Monte-Carlo simulation, please hold on..." << endl;

    int sum = 0;
    for (long long int i=0; i < trials; i++){
        vector<int> location(2);
        bool finished = false;
        int moves = 0;
        while (!finished){
            vector<vector<int>> options;
            options = {{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}}; // The 8 moves

            bool validmove = false;
            while(!validmove){
                int opt = select();

                // Temporary holding for possible location, needs to be validated.
                int x = location[0] + options[opt][0];
                int y = location[1] + options[opt][1];

                if ((x >= 0) && (x < N) && (y >= 0) && (y < N)){ // Don't go off the board
                    validmove = true;
                    location[0] = x;
                    location[1] = y;      
                }
            }
            moves++;
            if ((location[0] == 0) && (location[1] == 0)) finished = true;
        }
        sum += moves;
    }
    double avg = sum / float(trials);

    clock_t end = clock();
    double elapsed = double(end - begin) / CLOCKS_PER_SEC;

    cout << "The expected number of moves to return to the start is roughly: " << int(avg) << endl;
    cout << "Simulation running time: " << elapsed << " secs" << endl;
    cout << endl;

    return 0;
}

