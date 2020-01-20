#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


bool is_palindrome(const string &s);

int main(int argc, char* argv[]){
	ifstream ifs(argv[1]);

	map<int, int> one_step_palindromes;
	int temp;
	string s;
	string reverse_s;
	string sum;
	while(ifs >> temp){
		s = to_string(temp);
		reverse_s = s;
		reverse(reverse_s.begin(), reverse_s.end());
		sum = to_string(stoi(s) + stoi(reverse_s));
		if(is_palindrome(sum)){
			cout << s << endl;
			one_step_palindromes[stoi(s)] += 1;
		}
	}

	long long int total = 0;
	long long int total_unique = 0;
	long long int count_unique = one_step_palindromes.size();
	long long int count = 0;

	for(auto kv:one_step_palindromes){
		count += kv.second;
		total += kv.second * kv.first;
		total_unique += kv.first;
	}

	cout << "Total is: " << total << endl;
	cout << "Count is: " << count << endl;
	cout << "Total Unique is: " << total_unique << endl;
	cout << "Count Unique is: " << count_unique << endl;

	return 0;
	
}








bool is_palindrome(const string &s){
	for(int i = 0; i < s.size(); i++){
		if (s[i] != s[s.size()-1-i]){
			return false;
		}
	}
	return true;
}
