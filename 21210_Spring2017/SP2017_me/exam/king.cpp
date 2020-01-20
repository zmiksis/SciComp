#include <iostream>
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

    if (N == 1){
        cout << endl;
        cout << "The expected number of moves is 1 for a one by one square.\nNow exiting.\n" << endl;
        return 0;
    } 

    random_device rd;
    int seed = rd(); // Seed only once
    mt19937 seedmaker(seed); // Generate pseudo-random numbers
    uniform_int_distribution<int> choices(0, 7); // Maximum of 8 possible king moves
    auto select = bind(choices, seedmaker); // Random move selector

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
            vector<vector<int>> options;
            options = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}}; // The 8 moves

            bool validmove = false;
            int x;
            int y;

            while(!validmove){
                int opt = select();
                x = location[0] + options[opt][0];
                y = location[1] + options[opt][1];

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
        //cout << moves << endl;
    }
    double avg = sum / float(trials);

    clock_t end = clock();
    double elapsed = double(end - begin) / CLOCKS_PER_SEC;

    cout << "Expected number of king moves to visit each square on a " << N << " x " << N << " board at least once is: " << avg << endl;
    cout << "Simulation running time: " << elapsed << " secs" << endl;
    cout << endl;

    return 0;
}

