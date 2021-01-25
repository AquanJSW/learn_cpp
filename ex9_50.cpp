/**
 * Exercise 9.50: Write a program to process a vector<string>s whose
 * elements represent integral values. Produce the sum of all the elements in
 * that vector. Change the program so that it sums of strings that represent
 * floating-point values.
 *
 */

#include "iostream"
#include "vector"
#include "string"

int main() {
	std::vector<std::string> vs{"1", "3", "5"};
	int sum = 0;
	for (auto &s : vs)
		sum += std::stoi(s);
	std::cout << sum << std::endl;
	std::cout << (double) sum << std::endl;
}