#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "Enter three integers" << endl;
    
    cin >> a >> b >> c;

    if(a > b){
        swap(a,b);
    }
    if(a > c){
        swap(a,c);
    }
    if(b > c){
        swap(b,c);
    }
    
    cout << "In ascending order: " << a << " " << b << " " << c << endl;
    
    return 0;
}
