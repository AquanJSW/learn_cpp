/**
 * Exercise 9.41: Write a program that initializes a string from a
 * vector<char>.
 */

#include <z3.h>
#include "iostream"
#include "vector"
#include "string"

int main() {
	const char pc[] = "Pointer";
	std::vector<char> vc{'H', 'e', 'l', 'l', 'o'};
	std::string s(vc.begin(), vc.end());
	s.erase(1, 2);
	std::cout << s << std::endl;
}