#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <functional>

using namespace std;

bool capture(vector<int> &King1, vector<int> &King2);
void move(vector<int> &King);

int main(int argc, char* argv[]){

  if(argc < 3){
    cout << "Not enough values entered!";
    return 0;
  } else if(stoi(argv[1]) < 2){
    cout << "The board size is too small!";
    return 0;
  }

  int M = stoi(argv[1]);
  int trials = stoi(argv[2]);

  vector<long long int> moves(trials);

  for(int i = 0; i < M; ++i){

    vector<int> King1{1,1};
    vector<int> King2{M,M};

    long long int num_moves = 0;

    while(capture(King1,King2) == false){
      move(King1,M);
      move(King2,M);
      ++num_moves;
    }

    moves[i] = num_moves;

  }

  double avg_moves = 0;
  for(int i = 0; i < moves.size(); ++i){
    avg_moves += moves[i];
  }
  avg_moves /= M;

  cout << "Average number of moves to capture on " << M << "x" << M << " board is " << avg_moves << endl;

}

bool capture(vector<int> &King1, vector<int> &King2){

  bool capture = false;
  if(King1[0] == King2[0] && King1[1] == King2[1])
    capture = true;

  return capture;
}

void move(vector<int> &King, int M){

  randome_device rd;
  int seed_value = rd();

  mt19937 generator(seed_value);
  uniform_int_distribution<int> distribution(1,8);
  vector<int> move_x{-1,0,1,1,1,0,-1,-1};
  vector<int> move_y{1,1,1,0,-1,-1,-1,0};
  int move;
  if(King[0] > 1 && King[0] < M && King[1] > 1 && King[1] < M){
    move = distribution(generator);
  } else if(King[0] = 1 && King[1] > 1 && King[1] < M){
    move = 1;
    while(move == 1 || move == 7 || move == 8){
      move = distribution(generator);
    }
  } else if(King[0] = M && King[1] > 1 && King[1] < M){
    move = 3;
    while(move == 3 || move == 4 || move == 5){
      move = distribution(generator);
    }
  } else if(King[0] > 1 && King[0] < M && King[1] = 1){
    move = 5;
    while(move == 5 || move == 6 || move == 7){
      move = distribution(generator);
    }
  } else if(King[0] > 1 && King[0] < M && King[1] = M){
    move = 1;
    while(move == 1 || move == 2 || move == 3){
      move = distribution(generator);
    }
  } else if(King[0] == 1 && King[1] == 1){
    move = 1;
    while(move != 2 || move != 3 || move != 4)
      move = distribution(generator);
    }
  } else if(King[0] == 1 && King[1] == M){
    move = 1;
    while(move != 4 || move != 5 || move != 6)
      move = distribution(generator);
    }
  } else if(King[0] == M && King[1] == 1){
    move = 3;
    while(move != 1 || move != 2 || move != 8)
      move = distribution(generator);
    }
  } else if(King[0] == M && King[1] == M){
    move = 1;
    while(move != 6 || move != 7 || move != 8)
      move = distribution(generator);
    }
  }

  King[0] += move_x[move-1];
  King[1] += move_y[move-1];

  return;

}
