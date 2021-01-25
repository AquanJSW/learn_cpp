/**
 * Exercise 8.1: Write a function that takes and returns an istream&. The
 * function should read the stream until it hits end-of-file. The function
 * should print what it reads to the standard output. Reset the stream so that
 * it is valid before returning the stream.
 */

#include "iostream"

using std::cout;
using std::cin;
using std::endl;
using std::istream;

auto read(istream &is) -> istream &;

int main() {
	read(cin);
}

auto read(istream &is) -> istream & {
	char c;
	do {
		is >> c;
		if (is.fail() || is.bad())
			is.setstate(is.rdstate() & ~is.badbit & ~is.failbit);
		else
			cout << c;
	} while (!is.eof());
	return is;
}