/**
 * Exercise 9.20: Write a program to copy elements from a list<int> into
 * two deques. The even-valued elements should go into one deque and the
 * odd ones into the other.
 */

#include "iostream"
#include "list"
#include "deque"

int main() {
	std::list<int> li{1, 2, 3, 4, 5, 6};
	std::deque<int> dei, doi;
	for (const auto &n : li)
		if (n % 2)
			doi.emplace_back(n);
		else
			dei.emplace_back(n);

	std::cout << "even: ";
	for (const auto &n : dei)
		std::cout << n << " ";
	std::cout << std::endl << "odd: ";
	for (const auto &n : doi)
		std::cout << n << " ";
	std::cout << std::endl;
}