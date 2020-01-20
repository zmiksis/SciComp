#include <iostream>
#include <random>
#include <functional>
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

    if (N == 1){
        cout << endl;
        cout << "The expected number of moves is 1 for a one by one square.\nNow exiting.\n" << endl;
        return 0;
    } 

    random_device rd;
    int seed = rd(); // Seed only once
    mt19937 generator(seed); // Generate pseudo-random numbers
    uniform_int_distribution<int> directionOptions(0, 7); // Maximum of 8 possible king moves
    auto dir = bind(directionOptions, generator); // Random direction selector

    uniform_int_distribution<int> distanceOptions(1, N-1); // Number of moving distance options
    auto dist = bind(distanceOptions, generator); // Random distance selector

    vector<vector<int>> compass = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}}; // The 8 star points    

    cout << endl;
    cout << "Running Monte-Carlo simulation, please hold on..." << endl;

    int sum = 0;
    for (long long int t=0; t < trials; t++){
        vector<int> location(2);
        vector<vector<int>> visits(N, vector<int>(N));
        visits[0][0] = 1;
        bool finished = false;

        int moves = 0;

        while (!finished){
            bool validmove = false;
            int x;
            int y;

            while(!validmove){
                int direction = dir();
                int distance = dist();
                x = location[0] + distance*compass[direction][0];
                y = location[1] + distance*compass[direction][1];

                if ((x >= 0) && (x < N) && (y >= 0) && (y < N)){ // Don't go off the board
                    validmove = true;                      
                    location[0] = x; // Assign king to new square
                    location[1] = y; 
                    visits[x][y] = 1; // Mark a visit on this square
                }
            }

            moves++;

            
            // Check if all squares have been marked visited at least once. Can also use find.
            int zerocheck = 1;
            for(int i=0; i<N; i++){
                for (int j=0; j<N; j++){                    
                    zerocheck = visits[i][j] * zerocheck;               
                }
            }
            finished = (zerocheck > 0);
            /*
            bool flag = true; // Assume all squares are covered, but let's see
            for (int row = 0; row < N; row++)
            {
                for (int col = 0; col < N; col++)
                {
    
                    flag = flag && (visits[row][col] == 1);
                    
                }
            }
            finished = flag;
            */
 
        }
        sum += moves;
    }
    double avg = sum / float(trials);

    cout << "Expected number of king moves to visit each square on a " << N << " x " << N << " board at least once is: " << avg << endl;
    cout << endl;

    return 0;
}

