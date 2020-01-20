#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "Enter three integers" << endl;
    
    cin >> a >> b >> c;

    int tmp;
    
    if(a > b){
        tmp = a;
        a = b;
        b = tmp;
    }
    if(a > c){
        tmp = a;
        a = c;
        c = tmp;
    }
    if(b > c){
        tmp = b;
        b = c;
        c = tmp;
    }
    
    cout << "In ascending order: " << a << " " << b << " " << c << endl;
    
    return 0;
}