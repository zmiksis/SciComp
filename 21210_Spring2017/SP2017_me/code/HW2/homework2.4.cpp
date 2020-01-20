// 
// Alternatives:
// - you can use the literal value for pi rathan than arc-cosine
// - you can omit the checks for proper input
// - you can use an if statement to alternate the sign, instead of using cmath pow
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  //const double pi = 3.14159265358;
  static constexpr double pi = acos(-1);
  int k=1,N;
  float tol=0.0;
  double pisum = 0;
  
  while (tol <=0 || tol >= 1){
    cout << "What is the error tolerance? " << endl;

    if(!(cin >> tol)){
		cout << "You did not enter a number. Program will now exit!" << endl;
        return 1;
    }
    
    if (0 < tol && tol < 1){
        break;
    }else{
        cout << "Error tolerance must be between 0 and 1. Try a very small positive number.\n" << endl;
    }
  }

  N = ceil(2.0/tol + 0.5); // Maximum iterations needed to converge
  
  for (k=1; k<=N; k++){
      pisum = pisum + 4.0*pow(-1,k-1)/(2.0*k - 1);
      if (abs(pi-pisum) <= tol) break;
  }
  
  cout << endl;
  cout << "pi=" << pisum << endl;
  cout << "Number of terms used:" << k << " with a tolerance of " << tol << endl;
  
  return 0;
}