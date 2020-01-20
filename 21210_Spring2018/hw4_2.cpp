#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	vector<string> names;
	vector<int> scores;

	while(true){
	    // There will be many opportunities to break out of the while loop, so it will not go on forever.
	    string name;
		cout << "Please enter the student's name: ";
		cin >> name;
		
		// Did the user enter EndInput?
		if(name == "EndInput") break; // User literally entered "EndInput"? Break out.
		
	    // It's a good name, let's continue by checking if the name is already stored in the collection
	    bool name_exists = false; // Let's assume the name doesn't exist already
	    for(string item : names){ // Go over all the names we have. See if this name is already stored.
			if(item == name){
				name_exists = true;
			}
		}
		if (name_exists) break;  // Name already exists? Break out of the while loop.
	    
	    // Unique name, so let's get the score
	   int score;
	   cout << "Test score for " << name << " as a whole number percentage. ";
	   cin >> score;
	   
	   // Is this score any good? Or did the user enter a non-numeric value? i.e. cin is not good.
	   if(score < 0 || score > 100 || !cin.good()) break; // Illegal test score? Break out.
	    
		// The name and score are both good, save them in the collection
        names.push_back(name);
        scores.push_back(score);
	}
	
	// Did we end up storing any student data?
    if (names.size() != 0){
        // Yes we stored at least one.
        // Assume the first score is the smallest and the largest
        int highest_score=scores[0];
        int lowest_score=scores[0];
        // There are other (in-built) ways to find a maximum or minimum element in a vector.
        // We will for-loop over all scores to find the actual smallest and largest scores, and get the corresponding index
        for (int score : scores){ // Begin to look through all scores
			if (score > highest_score){ // If a greater score is found, we need to update
		    	highest_score = score;  // This is now the highest score
			}
			if (score < lowest_score){ // If a smaller score is found, we need to update
		    	lowest_score = score; // This is now the smallest score
			}			
		}
		// Now that we know the lowest_score and highest_score, we can find the indexes for those who own the scores
		vector<string> high_scorers;
		vector<string> low_scorers;
		// Get all high and low scorers
		for (int i=0; i<scores.size(); i++){
			if (scores[i] == highest_score) {
			    high_scorers.push_back(names[i]);
			}
			if (scores[i] == lowest_score) {
			    low_scorers.push_back(names[i]);
			}
		}
		cout << "The highest score is " << highest_score << ", scored by:" << endl;

		for (int i=0; i<high_scorers.size(); i++){
			cout << high_scorers[i];
			if (i < high_scorers.size()-1) cout << ", ";
		}
		cout << endl;

		cout << "The lowest score is " << lowest_score << ", scored by:" << endl;
		for (int i=0; i<low_scorers.size(); i++){
			cout << low_scorers[i];
			if (i < low_scorers.size()-1) cout << ", ";
		}
		cout << endl;
    }else{
        // No, the data record is empty. Oops.
        cout << endl;
        cout << "No student names or scores have been recorded" << endl;
    }
    return 0;
}