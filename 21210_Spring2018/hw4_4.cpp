#include <iostream>
#include <iomanip>

using namespace std;

bool primetest(int k);

int main()
{
    long long int N;
    double sum=0.0;
    cout << "Enter a large positive integer N to evaluate a sum of reciprocals of twin primes up to N." << endl;
    cin >> N;
    
    for (int p=2; p<=N; p++){
        if (primetest(p) && primetest(p+2)){
            sum += (1.0/p) + 1.0/(p+2);
        }
    }
    cout << "The sum of reciprocals of twin primes up to " << N << " is ";
    cout << fixed << setprecision(12) << sum << endl;
    return 0;
}

bool primetest(int k){
    if (k==1) return false;
    if ((k%2 == 0) && (k!=2)) return false;
    if (k >= 2){
        for (int i=3; i*i<= k; i+=2){
            if ((k%i)==0) return false;
        }
    }
    return true;
}