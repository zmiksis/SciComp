#include <iostream>
#include <string>
#include <vector>

using namespace std;

string combine_date(int day, int month, int year);

int main(){

  string full_date = combine_date(29,10,1929);
  cout << full_date << endl;

  return 0;

}

string combine_date(int day, int month, int year){

  vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};

  string date = months[month - 1] + " " + to_string(day) + ", " + to_string(year);
  return date;

}
