

#include <iostream>
#include <fstream>
#include <cstring>
#include "WordList.h" // class definitions 
using namespace std;

void testfunc(WordList myList); // function to test pass-by-value for WordList class 
int main() {

	WordList wl;

	// testing regular member functions 
	wl.addWord("one");
	wl.addWord("one"); // adding duplicate 
	wl.addWord("two");
	wl.addWord("three");
	cout << "word list is:\n";
	wl.printList();
	cout << endl;
	WordList wl2, wl3;

	wl3 = wl2 = wl; // testing overloaded assignment 
	wl3 = wl3; // testing protection against self-assingment 
	testfunc(wl); // testing copy constructor 
	cout << endl;
	wl.printList(); // if destructor is implemented correctly 
	// this should print properly after testfunc completes 

//testing reading from a file
	WordList w4;
	ifstream file1;
	string word;
	file1.open("file1.txt");

	if (file1.fail()) {
		cout << "Error opening file1.txt";
		cout << endl;

	}

	while (file1 >> word) {
		//add each word of file1 to the word list
		w4.addWord(word);

	}
	cout << endl;
	cout << "word list is:\n";
	w4.printList();
	cout << endl;


	file1.close();


	return 0;
}


void testfunc(WordList myList)
{
	// copy constructor is invoked on "myList" 
	cout << "word list in testfunc: \n";
	myList.printList();
} // destructor is invoked when "myList" goes out of scope

