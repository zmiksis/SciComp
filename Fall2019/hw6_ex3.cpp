#include <iostream>
#include <random>

using namespace std;

int main(){

  // Take inputs for following values
  double a = 1;
  double b = 0;
  double N = 100000;

  random_device rd;
  int seed_value = rd();

  mt19937 generator(seed_value);

  uniform_real_distribution<double> distribution(-1,1);

  double x;
  double y;
  double dist;
  double total_dist = 0;

  int num_successes = 0;
  while(num_successes < N){
    // Draw random point (x,y)
    x = distribution(generator);
    y = distribution(generator);
    // Check it is in the unit disk
    if(pow(x,2) + pow(y,2) <= 1.){
      // Compute distance to (a,b)
      dist = sqrt(pow(x-a,2) + pow(y-b,2));
      total_dist += dist;
      ++num_successes;
    }
  }

  // Compute average distance
  total_dist /= N;

  cout << total_dist << endl;

}
