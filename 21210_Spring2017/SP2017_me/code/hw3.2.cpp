#include <iostream>
#include <string>
using namespace std;

string getmonth(int m)
{
    string month;
    switch(m){
      case 1:
        month = "January";
        break;
      case 2:
        month = "February";
        break;
      case 3:
        month = "March";
        break;
      case 4:
        month = "April";
        break;
      case 5:
        month = "May";
        break;
      case 6:
        month = "June";
        break;
      case 7:
        month = "July";
        break;
      case 8:
        month = "August";
        break;
      case 9:
        month = "September";
        break;
      case 10:
        month = "October";
        break;
      case 11:
        month = "November";
        break;
      case 12:
        month = "December";
        break;
      default:
        month = "Invalid month!";
        break;                        
    }
    return month;
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