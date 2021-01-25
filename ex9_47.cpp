/**
 * Exercise 9.47: Write a program that finds each numeric character and then
 * each alphabetic character in the string "ab2c3d7R4E6". Write two
 * versions of the program. The first should use find_first_of, and the
 * second find_first_not_of.
 */

#include "iostream"
#include "string"

int main() {
	std::string s("ab2c3d7R4E6");
	const std::string digits("01234567890");
	std::string alphas;
	for (char c = 'A'; c <= 'Z'; ++c) {
		alphas.push_back(c);
		alphas.push_back(c+32);
	}

	std::cout << "positions of digits: ";
	for (std::string::size_type pos = 0;
		 (pos = s.find_first_of(digits, pos)) != std::string::npos; ++pos)
		std::cout << pos << " ";
	std::cout << std::endl;
	std::cout << "positions of alphas: ";
	for (std::string::size_type pos = 0;
	     (pos = s.find_first_of(alphas, pos)) != std::string::npos; ++pos)
		std::cout << pos << " ";
	std::cout << std::endl;
}