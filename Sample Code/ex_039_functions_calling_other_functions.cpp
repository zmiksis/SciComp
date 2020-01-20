#include <iostream>

using namespace std;

int simple_function_1(int a);
int simple_function_2(int a);

int main(){
	
	int a = 2;
	int res = simple_function_1(a);
	
	cout << "The value of a is " << a << " and the result of calling simple_function_1 is " << res << endl;


	return 0;
}



int simple_function_1(int a){
	int b = a + 1;
	return 2 + simple_function_2(b + a);
}

int simple_function_2(int a){
	return a * a + 1;
}
