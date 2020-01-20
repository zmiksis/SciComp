#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <functional>

using namespace std;

int main(int argc, char * argv[]){

  int M = stoi(argv[1]);
  int N = stoi(argv[2]);
  if(M < 3){
    cout << "Board size is too small!\n";
    return 0;
  }

  vector<vector<int>> move(8);
  move[0] = {-1,2};
  move[1] = {1,2};
  move[2] = {-1,-2};
  move[3] = {1,-2};
  move[4] = {2,-1};
  move[5] = {2,1};
  move[6] = {-2,-1};
  move[7] = {-2,1};

  random_device rd;
  int seed_value = rd();
  uniform_int_distribution<int> distribution(0,7);
  mt19937 generator(seed_value);
  auto draw = bind(distribution,generator);

  double avg_moves = 0;
  int move_choice;

  for(int i = 0; i < N; i++){
    vector<int> knight = {0,0};
    vector<int> knightTEMP = {0,0};
    int move_count = 0;
    move_choice = draw();
    knightTEMP[0] += move[move_choice][0];
    knightTEMP[1] += move[move_choice][1];
    while(knightTEMP[0] < 0 || knightTEMP[1] < 0){
      knightTEMP = knight;
      move_choice = draw();
      knightTEMP[0] += move[move_choice][0];
      knightTEMP[1] += move[move_choice][1];
    }
    move_count++;
    knight = knightTEMP;
    while(knight[0] != 0 || knight[1] != 0){
      move_choice = draw();
      knightTEMP[0] += move[move_choice][0];
      knightTEMP[1] += move[move_choice][1];
      while(knightTEMP[0] < 0 || knightTEMP[1] < 0 ||
            knightTEMP[0] > M || knightTEMP[1] > M){
        knightTEMP = knight;
        move_choice = draw();
        knightTEMP[0] += move[move_choice][0];
        knightTEMP[1] += move[move_choice][1];
      }
      move_count++;
      knight = knightTEMP;
    }
    avg_moves += move_count;
  }

  avg_moves /= N;

  cout << avg_moves << endl;

  return 0;

}
