#include <iostream>
#include <random>
#include <functional>
#include <vector>

using namespace std;

int main(){

  // Set these as user inputs;
  int d = 3;
  int K = 100;
  int N = 100000;

  vector<int> point(d,0);

  random_device rd;
  int seed_value = rd();
  mt19937 generator(seed_value);

  // Select dimension
  uniform_int_distribution<int> distribution1(0,d-1);
  // Select direction
  uniform_int_distribution<int> distribution2(0,1);

  auto draw1 = bind(distribution1,ref(generator));
  auto draw2 = bind(distribution2,ref(generator));


  int direction, dimension;

  double avg_distance = 0;

  for(int i = 0; i < N; i++){

    // Set point location to origin
    for(int j = 0; j < point.size(); j++){
      point[j] = 0;
    }

    // Move the point K steps
    for(int j = 0; j < K; j++){
      // Select dimension and direction
      dimension = draw1();
      direction = draw2();

      if(direction == 0){
        point[dimension] -= 1;
      }else{
        point[dimension] += 1;
      }
    }

    double distance = 0;
    for(int  j = 0; j < point.size(); j++){
      distance += pow(point[j],2);
    }
    distance = sqrt(distance);
    avg_distance += distance;

  }

  avg_distance /= N;

  cout << avg_distance << endl;

  return 0;

}
