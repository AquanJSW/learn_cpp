/**
 * Exercise 10.1: The algorithm header defines a function named count
 * that, like find, takes a pair of iterators and a value. count returns a count
 * of how often that value appears. Read a sequence of ints into a vector
 * and print the count of how many elements have a given value.
 *
 * Exercise 10.2: Repeat the previous program, but read values into a list of
 * strings.
 *
 * Exercise 10.3: Use accumulate to sum the elements in a vector<int>.
 */

#include "algorithm"
#include "iostream"
#include "vector"
#include "list"
#include "string"

int main() {
	const std::vector<int> vi{3, 1, 3, 4, 5, 3, 2, 5, 6, 3};
	const std::list<std::string> ls{"Joe", "is", "Joe", "himself"};
	constexpr int ti = 3;
	constexpr char ts[] = "Joe";

	std::cout << std::count(vi.cbegin(), vi.cend(), ti) << std::endl;
	std::cout << std::count(ls.cbegin(), ls.cend(), ts) << std::endl;
	std::cout << std::accumulate(vi.cbegin(), vi.cend(), 0) << std::endl;
}