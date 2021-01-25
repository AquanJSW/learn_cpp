/**
 * Exercise 8.4: Write a function to open a file for input and read its contents
 * into a vector of strings, storing each line as a separate element in the
 * vector.
 * Exercise 8.5: Rewrite the previous program to store each word in a
 * separate element.
 */

#include <fstream>
#include "iostream"
#include "vector"

#define SIMPLE

int getw(std::string &, std::istream &);

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "usage: " << *argv << " FILE PATH" << std::endl;
		return -1;
	}
	std::ifstream ifs(*++argv);
	if (!ifs) {
		std::cout << *argv << ": read failed." << std::endl;
		return -1;
	}
	std::vector<std::string> vword;
	std::string buf;
#ifndef SIMPLE
	while (getw(buf, ifs)) {
		vword.emplace_back(buf);
		buf.clear();
	}
#else
	while (ifs >> buf)
		vword.emplace_back(buf);
#endif
	/// print
	for (auto beg = vword.begin(); beg != vword.cend(); ++beg)
		std::cout << *beg << std::endl;
}

int getw(std::string &s, std::istream &is) {
	int n = 0;
	int c;
	while (isspace(is.get())) ;
	is.unget();
	while ((c = is.get()) != EOF && !isspace(c)) {
		++n;
		s.push_back(c);
	}
	return n;
}
