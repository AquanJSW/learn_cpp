/**
 * Exercise 8.4: Write a function to open a file for input and read its contents
 * into a vector of strings, storing each line as a separate element in the
 * vector.
 */

#include <fstream>
#include "iostream"
#include "vector"
#include "string"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

int main(int argc, char **argv) {
	if (argc == 1) {
		cout << "usage: " + string(*argv) + " FILE_PATH" << endl;
		return -1;
	}
	ifstream ifs(*++argv);
	if (!ifs) {
		cout << "read failed!" << endl;
		return -1;
	}
	vector<string> vline;
	string s;
	while (std::getline(ifs, s))
		vline.emplace_back(s);

	for (auto beg = vline.begin(); beg != vline.cend(); ++beg)
		cout << *beg << endl;
}