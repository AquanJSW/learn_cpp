/**
 * Exercise 10.13: The library defines an algorithm named partition that
 * takes a predicate and partitions the container so that values for which the
 * predicate is true appear in the first part and those for which the predicate
 * is false appear in the second part. The algorithm returns an iterator just
 * past the last element for which the predicate returned true. Write a function
 * that takes a string and returns a bool indicating whether the string has five
 * characters or more. Use that function to partition words. Print the elements
 * that have five or more characters.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

bool haveFiveOrMoreChar(std::string &);

int main() {
	std::vector<std::string> vs{"a", "an", "this", "forward", "back",
							    "lexicographical", "future"};
	auto iter = std::partition(vs.begin(), vs.end(), haveFiveOrMoreChar);

	/// output
	std::cout << "have five or more characters: " << std::endl;
	for (auto beg = vs.begin(); beg != iter; ++beg)
		std::cout << *beg << std::endl;
}

bool haveFiveOrMoreChar(std::string &str) {
	return str.size() >= 5;
}
