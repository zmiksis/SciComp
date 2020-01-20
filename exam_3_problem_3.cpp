#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
using namespace std;

void move(vector<int> &King, int M, int move_choice, bool tryagain);
bool capture(vector<int> &King1, vector<int> &King2);
long long int summation(const vector<int> &x);

int main(int argc, char* argv[]){
  int M = stoi(argv[1]);
  double N = stod(argv[2]);

  if(M < 2){
    cout << "The board is too small! Board size must be at least 2x2!" << endl;
    return 0;
  }

  random_device rd;
  int seed_value = rd();
  mt19937 generator(seed_value);
  uniform_real_distribution<int> distribution(1, 8);
  int move_choice;

  vector<int> num_moves(N-1);

  for(int i = 0; i < N; i++){

    vector<int> King1(2,0);
    vector<int> King2(2,0);

    bool tryagain = true;

    King1[0] = 1;
    King1[1] = 1;

    King2[0] = M;
    King2[1] = M;

    int trialmoves = 1;

    move_choice = distribution(generator);
    move(King1, M, move_choice, tryagain);
    move_choice = distribution(generator);
    move(King2, M, move_choice, tryagain);

    bool captest = false;

    while (captest == false){
      move_choice = distribution(generator);
      move(King1, M, move_choice, tryagain);
      while(tryagain == false){
        move_choice = distribution(generator);
        move(King1, M, move_choice, tryagain);
      }
      captest = capture(King1, King2);
      trialmoves++;
      move_choice = distribution(generator);
      move(King2, M, move_choice, tryagain);
      while(tryagain == false){
        move_choice = distribution(generator);
        move(King2, M, move_choice, tryagain);
      }
      captest = capture(King1, King2);
      trialmoves++;
    }
    num_moves[i] = trialmoves;
  }

  long long int totalmoves = summation(num_moves);
  long double averagemoves = totalmoves/N;

  cout << "The expected number of moves is approximately " << averagemoves << endl;

  return 0;
}

bool capture(vector<int> &King1, vector<int> &King2){
  bool captured = false;
  if((King1[0] == King2[0]) && (King1[1] == King2[1])){
    captured = true;
  }
  return captured;
}

void move(vector<int> &King, int M, int move_choice, bool tryagain){

  vector<int> move_x = {-1, 0, 1, 1, 1, 0, -1, -1};
  vector<int> move_y = {1, 1, 1, 0, -1, -1, -1, 0};

  vector<int> tempKing(2,0);
  tempKing = King;

  tempKing[0] += move_x[move_choice-1];
  tempKing[1] += move_y[move_choice-1];

  if((tempKing[0] >= 1) && (tempKing[0] <= M) && (tempKing[1]>= 1) && (tempKing[1] <= M)){
    King[0] += move_x[move_choice-1];
    King[1] += move_y[move_choice-1];
    tryagain = true;
  } else {
    tryagain = false;
  }
}

long long int summation(const vector<int> &x){
  long long int total = 0;
  for (int i = 1; i < x.size(); i++) {
       total += x[i];
  }
  return total;
}
