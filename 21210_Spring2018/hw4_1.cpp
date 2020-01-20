#include <iostream>
#include <vector>

using namespace std;

double f_max(const vector<double> &numbers);
double f_min(const vector<double> &numbers);

int main(){
    double num;
    vector<double> numbers;
    
    cout << "Enter a positive real number." << endl;
    while (cin >> num && cin.good()){
        numbers.push_back(num);
        cin.clear();
        cout << "Enter another positive real number, or enter a string to stop." << endl;
    }
    cout << endl;
    cout << "The maximum number entered is " << f_max(numbers) << " and the minimum number is " << f_min(numbers);
    return 0;
}

double f_max(const vector<double> &numbers){
    double largest = numbers[0];
    for (double num : numbers){
        if (num > largest) largest = num;
    }
    return largest;
}

double f_min(const vector<double> &numbers){
    double smallest = numbers[0];
    for (double num : numbers){
        if (num < smallest) smallest = num;
    }
    return smallest; 
}