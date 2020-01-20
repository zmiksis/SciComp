// This file contains two possible solutions to problem 1b,
// and an additional method for accomplishing the task which technically does not
// satisfy the conditions of the problem, but might be worth seeing.

// The second version of the solution is more complicated,
// but it could be more efficient for large inputs
// because it does not have to resize the vector of even elements

// The third version is another way of accomplishing the same general task.
// You could make the task even more efficient by having the function not return a value
// but instead pass the vector which will contain the even values by reference and modify that vector directly.
// Version 3 does not actually meet the requirements of the question because it does not actually use the return statement.



// For the actual exam problem, you just have to write the function,
// you do not need includes, using namespace std, or the main routine.
// Those parts of the program are just for demonstration.

#include <iostream>
// For the function to work, you would need to #include <vector>
// but you do not have to mention this as part of the solution on the exam
#include <vector>


using namespace std;

vector<int> get_even_elements_version_1(const vector<int> &v);
vector<int> get_even_elements_version_2(const vector<int> &v);
void get_even_elements_version_3(vector<int> &even_vec, const vector<int> &v);


int main()
{

	vector<int> test_vec = {1, 3, 2, 6, 3, 4, 7, 10, 3, 10};
	vector<int> even_vec;
	

	// Uncomment the appropriate line (and comment out the other two) to try each version
	// even_vec = get_even_elements_version_1(test_vec);
	// even_vec = get_even_elements_version_2(test_vec);
	get_even_elements_version_3(even_vec, test_vec);


	cout << endl << "The even elements of your vector were: " << endl;
	for (int elem : even_vec){
		cout << elem << endl;
	}
	cout << endl;

}



// This is the easiest solution to write, and is worth full credit.
// If you can produce something like this, you are in good shape.
vector<int> get_even_elements_version_1(const vector<int> &v){
	
	// You need a variable to store the evenitive elements that you can return later
	vector<int> even_vec;

	// I have used a range-for loop here, but you could iterate using indices if you like
	for (int elem : v){
		// Any time you encounter an even element, add it to the back of even_vec
		if (elem % 2 == 0){
			even_vec.push_back(elem);
		}
	}

	return even_vec;
}


// This version might be more efficient for larger arrays,
// since it might avoid resizing even_vec possibly a large number of times.
// This is not likely to be an issue for a vector of integers in practical use,
// but if the vector contained more complicated types it could be worth considering.
// If the condition were more difficult to check than evenness, this sort of implementation
// might actually be less efficient, since it performs two passes through the vector.
// If efficiency is your top priority, you will have to balance such considerations.
vector<int> get_even_elements_version_2(const vector<int> &v){

	// First, count how many even elements there are
	int count = 0;
	for (int elem : v){
		if (elem % 2 == 0) {
			count += 1;
		}
	}
	
	// Now, create a vector to contain the even elements that already has the correct size
	vector<int> even_vec(count);
	
	// Keep track of where you are in even_vec using an index i, 
	// moving the index forward each time you set an entry
	int i;
	for(int elem : v){
		if (elem % 2 == 0) {
			even_vec[i] = elem;
			i += 1;
		}
	}
	
	return even_vec;
}


// This version does not technically meet the requirements of the problem,
// but might be a reasonable implementation in practice,
// because it avoid passing back a large vector that would be copied into an appropriate lvalue.
// Instead, it just modifies one of its arguments directly.
void get_even_elements_version_3(vector<int> &even_vec, const vector<int> &v){

	// First, count how many even elements there are
	int count = 0;
	for (int elem : v){
		if (elem % 2 == 0) {
			count += 1;
		}
	}
	
	// Now, resize the vector that you passed in to be the correct size
	even_vec.resize(count);	
	
	// Keep track of where you are in the vector using an index i, 
	// moving the index forward each time you set an entry
	int i;
	for(int elem : v){
		if (elem % 2 == 0) {
			even_vec[i] = elem;
			i += 1;
		}
	}
	
	// Do not return a value, you have modified the vector even_vec directly, which was passed by reference
	return;
}



