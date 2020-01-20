//
// Just for extra practice. Illustrates the use of a function call.
// Notice the call by reference for a, b and c to ensure they are updated.
#include <iostream>
using namespace std;

void sorter(int &a, int &b, int &c){
    if(a > b){
        swap(a,b);
    }
    if(a > c){
        swap(a,c);
    }
    if(b > c){
        swap(b,c);
    }
    return;
}

int main(){
    int a, b, c;
    cout << "Enter three integers" << endl;
    
    cin >> a >> b >> c;
    sorter(a,b,c);
    
    cout << "In ascending order: " << a << " " << b << " " << c << endl;
    
    return 0;
}
