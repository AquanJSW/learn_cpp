/**
 * Exercise 3.5: Write a program to read strings from the standard input,
 * concatenating what is read into one large string. Print the concatenated
 * string. Next, change the program to separate adjacent input strings by a
 * space.
 */

#include "iostream"
#include "string"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	string s, s0;

	while (cin >> s0)
		s += s0 + " ";
	cout << s << endl;
	return 0;
}
