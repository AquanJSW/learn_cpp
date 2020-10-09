/**
 * Exercise 3.10: Write a program that reads a string of characters including
 * punctuation and writes what was read but with the punctuation removed.
 */

#include "iostream"
#include "string"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	string str, buf;

	cout << "Input:" << endl;
	while (cin >> buf)
		str += buf;
	for (auto c : str)
		if (!ispunct(c))
			cout << c;
	cout << endl;
	return 0;
}