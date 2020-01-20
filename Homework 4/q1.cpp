#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

double max(const vector<double> &val_vec);
double min(const vector<double> &val_vec);

int main(){

  double min_value;
  double max_value;

  vector<double> x_vals;

  {
    double temp;
    cout << "Enter a real number (or string to exit): ";
    while(cin >> temp){
      x_vals.push_back(temp);
      cout << "Enter another real number (or string to exit): ";
    }
  }

  min_value = min(x_vals);
  max_value = max(x_vals);

  cout << "The maximum value is: " << max_value << endl;
  cout << "The minimum value is: " << min_value << endl;

  return 0;

}

double min(const vector<double> &val_vec){
  double min_value = val_vec[0];
  for(int i = 1; i < val_vec.size(); ++i){
    if(min_value >= val_vec[i]){
      min_value = val_vec[i];
    }
  }
  return min_value;
}

double max(const vector<double> &val_vec){
  double max_value = val_vec[0];
  for(int i = 1; i < val_vec.size(); ++i){
    if(max_value <= val_vec[i]){
      max_value = val_vec[i];
    }
  }
  return max_value;
}
