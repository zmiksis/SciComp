#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool data_exists(const vector<string> &names, const string &student_name);
int index_of_max(const vector<int> &vec);
int index_of_min(const vector<int> &vec);

int main(){
	vector<string> names;
	vector<int> scores;
	bool stopped = false;
	while(!stopped){
	    string student_name;
		cout << "Please enter the student's name: ";
		cin >> student_name;
		if(student_name == "EndInput"){
			stopped = true;
		}else{
		    // Good name, let's continue by checking if the name is already stored
		    bool data_already_exists = data_exists(names, student_name);
		    if (!data_already_exists){
		        // Unique name, so let's get the score
		        int test_score;
		        cout << "Please enter a test score for "<< student_name <<" as a non-negative integer less than 101: ";
		        cin >> test_score;
		        // Is this score any good? Or did the user enter a non-numeric value? i.e. cin is not good.
		        if(test_score < 0 || test_score > 100 || !cin.good()){
				    stopped = true;
			    }else{
			        // The name and score is good, save them
	                names.push_back(student_name);
	                scores.push_back(test_score);
			    }
	        }else{
	            // Student data is already stored
	            stopped = true;
	        }
		}
	}
	// Did we end up storing any student data?
    if (names.size() != 0){
        // Yes we stored at least one.
        int largest_index = index_of_max(scores);
        int smallest_index = index_of_min(scores);
        // We will use the index for largest and smallest scores, to connect with the students names
        // since the data is stored in the same order
        cout << endl;
	    cout << "The student with the lowest score is " << names[smallest_index] << endl;
	    cout << "The student with the highest score is " << names[largest_index] << endl;
    }else{
        // No, the data is empty.
        cout << endl;
        cout << "No student data was recorded" << endl;
    }
    return 0;
}

// Does this student name already exist in the collection of names?
bool data_exists(const vector<string> &names, const string &student_name){
	for(string name : names){
		if(name == student_name){
			return true;
		}
	}
	return false;
}

// Fetch the corresponding index to the largest score
// We need to check for a maximum over integers, not doubles
int index_of_max(const vector<int> &vec){
	int largest_index = 0; // Assume it's the first one
	for(int i=0; i<vec.size(); i++){
		if (vec[i] >= vec[largest_index]){
		    largest_index = i;
		}
	}
	return largest_index;
}

// Fetch the corresponding index to the smallest score
// We need to check for a minimum over integers, not doubles
int index_of_min(const vector<int> &vec){
	int smallest_index = 0; // Assume it's the first one
	for(int i=0; i<vec.size(); i++){
		if (vec[i] <= vec[smallest_index]){
		    smallest_index = i;
		}		
	}
	return smallest_index;
}