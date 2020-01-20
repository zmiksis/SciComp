#include <iostream>
#include <iomanip>
#include <random>
#include <functional> // Needed for bind
#include <vector>
 
using namespace std;
 
int main(int argc, char* argv[]){ 
 
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
        vector<int> location(2); // Create a vector with two components for the current location of the knight
        bool finished = false; // Has the knight returned to the origin? No.
        int moves = 0; // Number of moves the knight has made so far.
        while (!finished){ // While the knight is still on tour
            vector<vector<int>> options; // Define a vector to store the options
            options = {{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};
            // Above are the 8 possible knight moves. 2 steps in x or y axis in any direction, and one step in the other axis.
 
            bool validmove = false; // We begin by assuming the move is invalid, and then we can check if it is valid
            while(!validmove){ // As long as it is not a valid move, keep looking for other moves.
                int opt = select(); // Choose one move at random
 
                // Temporary holding for possible location, needs to be validated.
                 // Attempt to move to this square by adding the opt's coordinate to the current one 
                int x = location[0] + options[opt][0]; // New x coordinate, hopefully valid
                int y = location[1] + options[opt][1]; // New y coordinate, hopefully valid
 
                // Now check if the x and y coordinates are actually valid
                if ((x >= 0) && (x < N) && (y >= 0) && (y < N)){ // Don't go off the board!
                    validmove = true; 
                    location[0] = x; // Now we can truly update the x-coordinate
                    location[1] = y; // Now we can truly update the y-coordinate
                }
            }
            moves++; // Increase the number of moves
            if ((location[0] == 0) && (location[1] == 0)) finished = true; // The knight has returned to the origin
        }
        sum += moves; // Total number of moves used to return to origin
    }
    double avg = sum / float(trials); // Average number of moves
 
    // Announce results
    cout << "The expected number of moves to return to the start is roughly: " << int(avg) << endl;
    cout << endl;
 
    return 0;
}