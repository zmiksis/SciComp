#include <iostream>

using namespace std;

int main () {

  int a, b, c;

  cout << "Please enter three integers, separated by spaces: ";
  cin >> a >> b >> c;

  if (a < b && b < c){
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
  } else if (b < a && a < c){
    cout << "b = " << b << endl;
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
  } else if (b < c && c < a){
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "a = " << a << endl;
  } else if (a < c && c < b){
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
    cout << "b = " << b << endl;
  } else if (c < a && a < b){
    cout << "c = " << c << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
  } else if (c < b && b < a){
    cout << "c = " << c << endl;
    cout << "b = " << b << endl;
    cout << "a = " << a << endl;
  }

  return 0;

}
