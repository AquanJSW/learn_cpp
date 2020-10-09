/**
 * Exercise 3.4: Write a program to read two strings and report whether the
 * strings are equal. If not, report which of the two is larger. Now, change
 * the program to report whether the strings have the same length, and if
 * not, report which is longer.
 */

#include "iostream"
#include "string"

#define PART_

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	string s0, s1;

	cout << "Input two strings:" << endl;
	cin >> s0 >> s1;

#ifdef PART_1
	cout << "Larger string: " << (s0 > s1 ? s0 : s1);
	return 0;
#else
	if (s0 != s1)
		cout << "Larger string: " << (s0 > s1 ? s0 : s1);
	return 0;
#endif
}