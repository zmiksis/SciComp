#include <iostream>
#include <random>
#include <functional>

using namespace std;

int main(){

  // Take inputs as command line arguments
  double a = 1;
  double b = 0;
  int N = 10000;

  random_device rd;
  int seed_value = rd();

  mt19937 generator(seed_value);
  uniform_real_distribution<double> distribution(-1,1);
  auto draw = bind(distribution,generator);

  double x, y, dist;
  double avg_distance = 0;

  int num_successes = 0;
  while(num_successes < N){
    x = draw();
    y = draw();
    if(pow(x,2) + pow(y,2) <= 1.){
      dist = sqrt(pow(x-a,2) + pow(y-b,2));
      avg_distance += dist;
      num_successes++;
    }
  }

  avg_distance /= N;
  cout << avg_distance << endl;

}
