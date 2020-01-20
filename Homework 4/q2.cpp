#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int max(const vector<int> &val_vec);
int min(const vector<int> &val_vec);

int main(){

  int max_score;
  int min_score;

  vector<string> names;
  vector<int> scores;

  {
    int temp_score;
    string temp_name;
    cout << "Enter the name and score for the student: ";
    while(cin >> temp_name >> temp_score){
      if(temp_name == "EndInput"){
        break;
      }
      if(temp_score < 0 || temp_score > 100){
        break;
      }
      bool dup_name = false;
      for(int i = 0; i < names.size(); ++i){
        if(temp_name == names[i]){
          dup_name = true;
          break;
        }
      }
      if(dup_name){
        break;
      }
      names.push_back(temp_name);
      scores.push_back(temp_score);
      cout << "Enter the name and score for another student: ";
    }
  }

  min_score = min(scores);
  max_score = max(scores);

  cout << "The maximum score is: " << max_score << endl;
  for(int i = 0; i < scores.size(); ++i){
    if(scores[i] == max_score){
      cout << names[i] << endl;
    }
  }
  cout << "The minimum score is: " << min_score << endl;
  for(int i = 0; i < scores.size(); ++i){
    if(scores[i] == min_score){
      cout << names[i] << endl;
    }
  }

}

int min(const vector<int> &val_vec){
  int min_value = val_vec[0];
  for(int i = 1; i < val_vec.size(); ++i){
    if(min_value >= val_vec[i]){
      min_value = val_vec[i];
    }
  }
  return min_value;
}

int max(const vector<int> &val_vec){
  int max_value = val_vec[0];
  for(int i = 1; i < val_vec.size(); ++i){
    if(max_value <= val_vec[i]){
      max_value = val_vec[i];
    }
  }
  return max_value;
}
