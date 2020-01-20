#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>

using namespace std;

void move(vector<int> &Knight, int M);

int main(){

  int M = 8;
  int trials = 1000;

  double avg_moves = 0;

  for(int i = 0; i < trials; ++i){

    vector<int> Knight{1,1};

    long long int num_moves = 1;
    move(Knight,M);

    while(Knight[0] != 1 || Knight[1] != 1){
      move(Knight,M);
      ++num_moves;
    }

    /*
    while(neither King is captured){
      move King 1
      check for capture
      move king 2
      check for capture
    }
    */

    avg_moves += num_moves;
  }

  avg_moves /= trials;

  cout << avg_moves << endl;

}

void move(vector<int> &Knight, int M){

  // Random move selection
  random_device rd;
  int seed_value = rd();
  mt19937 generator(seed_value);
  uniform_int_distribution<int> distribution(1,8);
  int move_choice = distribution(generator);

  // Possible move choices
  vector<int> move_x{-1,1,2,2,1,-1,-2,-2};
  vector<int> move_y{2,2,1,-1,-2,-2,-1,1};

  vector<int> tempKnight;
  tempKnight = Knight;

  tempKnight[0] += move_x[move_choice-1];
  tempKnight[1] += move_y[move_choice-1];

  if(tempKnight[0] >= 1 && tempKnight[0] <= M &&
      tempKnight[1] >= 1 && tempKnight[1] <= M){
        Knight[0] += move_x[move_choice-1];
        Knight[1] += move_y[move_choice-1];
  } else{
    move(Knight,M);
  }

  return;

}




STRING REVERSE FUNCTION
string str = "abcde";
reverse(str.begin(),str.end());

output: str = "edcba";
