#pragma once
#include <string>
#include <iostream>
#include "WordOccurance.h"
using namespace std;
class WordList {

public:
	// add copy constructor, destructor, overloaded assignment

	WordList(const WordList& org);//copy constructor
	~WordList();//destructor
	WordList& operator = (const WordList& rhs);//overloaded assignment


	WordList();
	WordList(const string& word);

	void addWord(const string& word);
	void printList();
private:
	// a dynamically allocated array of WordOccurrences
	// may or may not be sorted
	WordOccurrence* wordArray_;

	int size_;
};

WordList::WordList(const WordList& org) {
	size_ = org.size_;

	wordArray_ = new WordOccurrence[org.size_];
	//copy each element of org.wordArray_ to this.wordArray_
	for (int i = 0; i < size_; i++) {
		wordArray_[i] = WordOccurrence(org.wordArray_[i].getWord(), org.wordArray_[i].getNum());

	}


}WordList::~WordList() {
	//executed when wordList object goes out of scope (program ends)
	delete[] wordArray_;

}


WordList& WordList::operator = (const WordList& rhs) {

	//protect against self assignment
	if (this != &rhs) {
		size_ = rhs.size_;
		delete[] wordArray_;
		wordArray_ = new WordOccurrence[rhs.size_];
		for (int i = 0; i < size_; i++) {
			wordArray_[i] = WordOccurrence(rhs.wordArray_[i].getWord(), rhs.wordArray_[i].getNum());

		}


	}

	return *this;
}

WordList::WordList() {
	//create array with size 0
	wordArray_ = new WordOccurrence[0];
	size_ = 0;

}WordList::WordList(const string& word) {
	//create array with size 1 with string &word and count 1
	wordArray_ = new WordOccurrence[1];
	wordArray_[0] = WordOccurrence(word, 1);
	size_ = 1;

}


void WordList::addWord(const string& word) {
	//if word already exists in array, increment number of occurrences
	for (int i = 0; i < size_; i++) {
		if (wordArray_[i].matchWord(word)) {
			wordArray_[i].increment();
			return;
		}


	}
	//if word contains at least one alpha character, increase array size by one and add new word occurrence
	for (int i = 0; i < word.size(); i++) {
		if (isalpha(word[i])) {//if word contains at least one alpha character
			size_++;

			WordOccurrence* newArray;
			newArray = new WordOccurrence[size_];//create array with one bigger size

			for (int i = 0; i < size_ - 1; i++) {
				//copy contents of original array
				newArray[i] = WordOccurrence(wordArray_[i].getWord(), wordArray_[i].getNum());

			}
			//add the new word to the last element of the array
			newArray[size_ - 1] = WordOccurrence(word, 1);

			delete[]wordArray_;
			wordArray_ = newArray;

			break;
		}



	}


}



void WordList::printList() {
	int maxIndex = 0;
	WordOccurrence temp;

	//selection sort descending order
	for (int i = 0; i < size_ - 1; i++) {
		maxIndex = i;
		for (int j = i + 1; j < size_; j++) {
			if (wordArray_[j].getNum() > wordArray_[maxIndex].getNum()) {
				maxIndex = j;

			}

		}temp = wordArray_[i];
		wordArray_[i] = wordArray_[maxIndex];
		wordArray_[maxIndex] = temp;
	}

	//print contents in descendng order based on count
	for (int i = 0; i < size_; i++) {

		cout << wordArray_[i].getWord() << ": ";
		cout << wordArray_[i].getNum() << endl;


	}

}