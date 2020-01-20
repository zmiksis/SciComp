#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <functional>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
    if(argc < 4){
        cout<<"You didn't enter a command."<<endl;
        return 0;
    }

      int d = stoi(argv[1]);    //number of dimensions
      int K = stoi(argv[2]);   //number of steps to take on each walk
	    int N = stoi(argv[3]);   //number of trials

      random_device rd;
      int seed_value = rd();

      mt19937 generator(seed_value);
      uniform_int_distribution<int> distribution(0, d-1);
      auto select_axis = bind(distribution, generator);
      bernoulli_distribution bernie(0.5);
      auto select_direction = bind(bernie, generator);
      double avgdist = 0.0;
     
      for(int i = 1; i < N+1; i++){   
         int axis=0;              
         vector<int> location (d);
         for (int j = 1; j < K+1; j++){
                    if (d > 1){
                      axis = select_axis();
                    } else {
                      axis = 0;
                    }
                    int direction = 2*select_direction() - 1;
                    location[axis] = location[axis] + direction;
              }
         double distance = 0.0;

         for (int k = 0; k < d; k++){
              distance += pow(location[k],2);
         }
         avgdist += pow(distance,0.5);

      }
      cout << "The average (Euclidean) distance of the location of the particle to the origin after N steps of this random walk is" << avgdist/N << endl;

return 0;

}
