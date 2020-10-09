/**
 * Exercise 3.2: Write a program to read the standard input a line at a time.
 * Modify your program to read a word at a time.
 */

#include "iostream"
#include <string>

#define LIN

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
#ifdef LINE
	string s;

	while (getline(cin, s))
		cout << s << endl;
	return 0;
#else
	string word;

	while (cin >> word)
		cout << word << endl;
	return 0;
#endif
}