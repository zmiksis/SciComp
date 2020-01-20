#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

double max(const vector<double> &vals);
double min(const vector<double> &vals);

int main(){

  vector<double> user_vals;

  {
    double temp;
    cout << "Please enter a value: ";
    while(cin >> temp){
      user_vals.push_back(temp);
      cout << "Please enter another value: ";
    }
  }

  double max_value = max(user_vals);
  double min_value = min(user_vals);

  cout << "The maximum value is " << max_value << endl;
  cout << "The minimum value is " << min_value << endl;


}

double max(const vector<double> &vals){

  double maximum = vals[0];
  for(int i = 1; i < vals.size(); ++i){
    if(maximum <= vals[i]){
      maximum = vals[i];
    }
  }

  return maximum;

}

double min(const vector<double> &vals){

  double minimum = vals[0];
  for(int i = 1; i < vals.size(); ++i){
    if(minimum >= vals[i]){
      minimum = vals[i];
    }
  }

  return minimum;

}
