#include <iostream>
#include <iomanip>
#include <random>
#include <functional>
#include <vector>

using namespace std;

//void valid_knight_moves(const int &N, vector<int> &knight);

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
    int seed = rd();
    mt19937 seedmaker(seed);
    uniform_int_distribution<int> choices(0, 7);
    auto select = bind(choices, seedmaker); 

    vector<vector<int>> options;
    options = {{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};

    int moves;
    int sum = 0;

    cout << endl;
    cout << "Running Monte-Carlo simulation, please hold on..." << endl;

    for (long long int i=0; i < trials; i++){
        vector<int> knight(2, 0);
        bool finished = false;
        moves = 0;
        while (!finished){
            bool validmove = false;
            while(!validmove){
                int opt = select();
                knight[0] = knight[0] + options[opt][0];
                knight[1] = knight[1] + options[opt][1];

                if ((knight[0] >= 0) && (knight[0] < N) && (knight[1] >= 0) && (knight[1] < N)){
                    validmove = true;
                    moves++;       
                }else{
                    knight[0] = knight[0] - options[opt][0];
                    knight[1] = knight[1] - options[opt][1];
                }
            }
            //cout << knight[0] << " " << knight[1] << endl;            
            if ((knight[0] == 0) && (knight[1] == 0)) finished = true;
        }
        sum += moves;
        //cout << "-----" << endl;
    }
    double avg = sum / float(trials);

    cout << "The expected number of moves to return to the start is " << setprecision(12) << avg << endl;
    cout << endl;

    return 0;
}

void 

/*
void legalmove(const int &N, vector<int> &knight){
    vector<vector<int>> options;    
    bool validmove = false;

    random_device rd;
    int seed = rd();
    mt19937 seedmaker(seed);
    switch(knight[0]+knight[1]){
        case 0:
            options = {{2,1}, {1,2}};
            uniform_int_distribution<int> choices(0, 1);
            break;
        case (N-1):
            options = 
            break;
        default:
            options = {{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};
            uniform_int_distribution<int> choices(0, 7);
            break;
    }
    if (knight[0] * knight[1] > 0){
        
    }else{
        if ((knight[0] + knight[1] == 0) || (knight[0] + knight[1] == N-1) || (knight[0] + knight[1] == 2*N-2)){
            options = {{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};
        }
    }
    auto select = bind(choices, seedmaker);    
    
    while(!validmove){
        int move = select();
        knight[0] += options[move][0];
        knight[1] += options[move][1];
        if ((knight[0] >= 0) && (knight[0] < N) && (knight[1] >= 0) && (knight[1] < N)){
            validmove = true;
            knight[2] += 1;            
        }
    }
    
}
*/

