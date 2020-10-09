/**
 * Exercise 3.17: Read a sequence of words from cin and store the values a
 * vector. After you’ve read all the words, process the vector and change
 * each word to uppercase. Print the transformed elements, eight words to a
 * line.
 */

#include "iostream"
#include "string"
#include "vector"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

int main() {
	cout << "Input some words:" << endl;

	vector<string> vs;
	string temp;
	unsigned size = 0;
	while (cin >> temp) {
		vs.push_back(temp);
		size++;
	}

	for (auto &s : vs)
		for (auto &c : s)
			c = toupper(c);

	for (unsigned i = 0; i < size; i++) {
		cout << vs[i] << ' ';
		if (i % 8 == 7)
			cout << '\n';
	}
	cout << endl;
	return 0;
}