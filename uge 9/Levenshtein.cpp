#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int recursiveLevelshteinComparison(string first_word, string second_word, int first_index, int second_index){
	
	int sub_string_distance = 0;
	
	if(first_index == 0){
		return second_index;
	}
	if(second_index == 0){
		return first_index;
	}
	if(first_word[first_index-1] != second_word[second_index-1]){
		sub_string_distance = 1;
	}
	
	int first_word_deletion = recursiveLevelshteinComparison(first_word, second_word, first_index-1, second_index);
	int second_word_deletion = recursiveLevelshteinComparison(first_word, second_word, first_index, second_index-1);
	int both_deletion = recursiveLevelshteinComparison(first_word, second_word, first_index-1, second_index-1);
	
	return min({first_word_deletion + 1, second_word_deletion + 1, both_deletion + sub_string_distance});
}

int main() {
	string first_word = "";
	string second_word = "";
	cin >> first_word;
	cin >> second_word;
	int distance = recursiveLevelshteinComparison(first_word, second_word, first_word.length(), second_word.length());
	cout << distance;
}

