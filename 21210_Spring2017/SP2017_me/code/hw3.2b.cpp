#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getmonth(int m)
{
    vector<string> months={"January","February","March","April","May","June","July","August","September","October","November","December"};
    return months[m-1];
}

int main()
{
  int day, monthnum, year;
  cout << "Enter a day:" << endl;
  cin >> day;
  cout << "Enter a month:" << endl;
  cin >> monthnum;
  cout << "Enter a year:" << endl;
  cin >> year;
  cout << endl;
  cout << getmonth(monthnum) << " " << day << ", " << year;
  return 0;
}