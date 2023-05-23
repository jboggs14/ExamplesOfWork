#pragma once
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class WordOccurrence {


public:
	WordOccurrence(const string& word = "", int num = 0);
	bool matchWord(const string& word); // returns true if word matches stored
	void increment(); // increments number of occurrences
	string getWord() const;
	int getNum() const;

private:
	string word_;
	int num_;
};

WordOccurrence::WordOccurrence(const string& word, int num) {
	string temp = word;
	string s = "";
	//temp is same as word but with all letters lower cased
	for (int i = 0; i < word.size(); i++) {
		temp[i] = tolower(word[i]);
	}



	for (int i = 0; i < temp.size(); i++) {

		if (isalpha(temp[i])) {
			//s only adds a character if it is an alpha character
			s += temp[i];


		}


	}
	//word is only alpha characters and contains no spaces or punctuation
	word_ = s;
	num_ = num;


}

bool WordOccurrence::matchWord(const string& word) {

	string temp = word;
	string s = "";
	//temp is same as word but with all letters lower cased
	for (int i = 0; i < word.size(); i++) {
		temp[i] = tolower(word[i]);
	}



	for (int i = 0; i < temp.size(); i++) {

		if (isalpha(temp[i])) {
			//s only adds a character if it is an alpha character
			s += temp[i];


		}


	}


	//if word_ is the same as the alpha characters of &word, return true
	if (word_.compare(s) == 0) {
		return true;

	}
	else {
		return false;
	}





}void WordOccurrence::increment() {
	num_++;

}
string WordOccurrence::getWord() const {

	return word_;
}
int WordOccurrence::getNum() const {

	return num_;
}
