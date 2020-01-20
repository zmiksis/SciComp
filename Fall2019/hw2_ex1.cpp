#include <iostream>

using namespace std;

int main(){

  int a, b, c;
  cout << "Please input integer a: ";
  cin >> a;
  cout << "Please input integer b: ";
  cin >> b;
  cout << "Please input integer c: ";
  cin >> c;

  if(a >= b && a >= c){
    if(b >= c){
      cout << "Integers are " << a << ", " << b << ", " << c << endl;
    }
    else if(c >= b){
      cout << "Integers are " << a << ", " << c << ", " << b << endl;
    }
  }

}
