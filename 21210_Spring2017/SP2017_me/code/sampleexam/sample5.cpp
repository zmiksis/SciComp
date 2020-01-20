#include <iostream>
using namespace std;

int main(){
    int number, counter=0, sum=0;
    
    cout << "Enter as many positive integers as you wish. To stop, enter zero or a negative integer" << endl;
    
    while(true){
        cin >> number;
        if (number <= 0) break;
        sum += number;
        counter++;
    }
    
    double average = (float)sum/counter;
    
    cout << "Sum: " << sum << " and " << "Average: " << average << endl;
    
    return 0;
}
