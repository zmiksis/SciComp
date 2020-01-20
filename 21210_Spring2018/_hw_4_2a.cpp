#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<string> names;
	vector<int> scores;
	while(true){
	    // There will be many opportunities to break out of the while loop, so it will not go on forever.
	    string student_name;
		cout << "Please enter the student's name: ";
		cin >> student_name;
		
		// Did the user enter EndInput?
		if(student_name == "EndInput") break; // User literally entered "EndInput"? Break out.
		
	    // It's a good name, let's continue by checking if the name is already stored in the collection
	    bool name_exists = false; // Let's assume the name doesn't exist already
	    for(string name : names){ // Go over all the names we have. See if this name is already stored.
			if(name == student_name){
				name_exists = true;
			}
		}
		if (name_exists) break;  // Name already exists? Break out of the while loop.
	    
	    // Unique name, so let's get the score
	   int test_score;
	   cout << "Please enter a test score for "<< student_name <<" as a whole number between 0 and 100. ";
	   cin >> test_score;
	   
	   // Is this score any good? Or did the user enter a non-numeric value? i.e. cin is not good.
	   if(test_score < 0 || test_score > 100 || !cin.good()) break; // Illegal test score? Break out.
	    
		// The name and score are both good, save them in the collection
        names.push_back(student_name);
        scores.push_back(test_score);
	}
	
	// Did we end up storing any student data?
    if (names.size() != 0){
        // Yes we stored at least one.
        // Assume the first element is the smallest and the largest
        int largest_index = 0;
        int smallest_index = 0;
        // There are other (in-built) ways to find a maximum or minimum element in a vector.
        // We will for-loop over all scores to find the actual smallest and largest scores, and get the corresponding index
        for(int i=1; i<scores.size(); i++){ // Start loop at one since we already assume score[0] is smallest / largest
			if (scores[i] >= scores[largest_index]){ // If a greater score is found, we need to update
		    	largest_index = i;  // This is now the largest index
			}
			if (scores[i] <= scores[smallest_index]){ // If a smaller score is found, we need to update
		    	smallest_index = i; // This is now the smallest index
			}			
		}
		// Now that we know the smallest_index and largest_index, we can find the corresponding student attached to that index
        // since the data is stored in the same order
        cout << endl;
	    cout << "The student with the lowest score is " << names[smallest_index] << endl;
	    cout << "The student with the highest score is " << names[largest_index] << endl;
    }else{
        // No, the data record is empty. Boo.
        cout << endl;
        cout << "No student data was recorded" << endl;
    }
    return 0;
}