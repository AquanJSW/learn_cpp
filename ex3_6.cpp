/**
 * Exercise 3.6: Use a range for to change all the characters in a string to X.
 *
 * Exercise 3.8: Rewrite the program in the first exercise, first using a while
 * and again using a traditional for loop. Which of the three approaches do
 * you prefer and why?
 */

#include "iostream"
#include "string"

#define WAY_2

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	string str;

	cout << "Input a string:" << endl;
	cin >> str;
#ifdef WAY_0
	for (char &c : str)
		c = 'X';
#elif defined(WAY_1)
	const auto size = str.size();
	unsigned i = 0;
	while (i < size)
		str[i++] = 'X';
#elif defined(WAY_2)
	const auto size = str.size();
	for (unsigned i = 0; i < size; i++)
		str[i] = 'X';
#endif
	cout << "After converting:\n" << str << endl;
	return 0;
}