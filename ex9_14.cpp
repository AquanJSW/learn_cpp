/**
 * Exercise 9.14: Write a program to assign the elements from a list of
 * char* pointers to C-style character strings to a vector of strings.
 */

#include "iostream"
#include "list"
#include "vector"
#include "string"

#define PNE(cmd) std::cout << #cmd ": " << cmd << std::endl

int main() {
	std::list<const char *> lpc{"May", "Joe"};
	std::vector<std::string> vs;
	vs.assign(lpc.cbegin(), lpc.cend());
}