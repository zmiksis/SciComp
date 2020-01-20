#include <iostream>
#include <random>

using namespace std;

int main(){

  // Following values come from user inputs
  int d = 3; // Number of dimensions
  int K = 100; // Number of steps
  int N = 100000; // Number of trials

  // Initialize point at origin in d dimensions
  vector<int> point(d);

  random_device rd;
  int seed_value = rd();
  mt19937 generator(seed_value);

  // Selects dimension
  uniform_int_distribution<int> distribution1(0,d-1);
  // Selects direction
  uniform_int_distribution<int> distribution2(0,1);

  int direction;
  int dimension;

  double avg_distance = 0;

  for(int j = 0; j < N; ++j){

    // Put point at origin
    for(int i = 0; i < point.size(); ++i){
      point[i] = 0;
    }

    for(int i = 0; i < K; ++i){
      // Select dimension and direction
      dimension = distribution1(generator);
      direction = distribution2(generator);
      // Move point
      if(direction == 0){
        point[dimension] -= 1;
      } else{
        point[dimension] += 1;
      }
    }

    // Compute distance
    double distance = 0;
    for(int i = 0; i < point.size(); ++i){
      distance += pow(point[i],2);
    }
    distance = sqrt(distance);

    avg_distance += distance;

  }

  // Compute average after trials are done
  avg_distance /= N;

  cout << avg_distance << endl;

}
