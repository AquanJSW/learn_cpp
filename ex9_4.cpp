/**
 * Exercise 9.4: Write a function that takes a pair of iterators to a
 * vector<int> and an int value. Look for that value in the range and return
 * a bool indicating whether it was found.
 */

#include "iostream"
#include "vector"

bool find(std::vector<int>::const_iterator,
		  std::vector<int>::const_iterator, int);

int main() {
	std::vector<int> vi{1, 2, 3, 4, 5, 6};
	std::cout << find(vi.cbegin(), vi.cend(), 8) << std::endl;
}

bool find(std::vector<int>::const_iterator beg,
          std::vector<int>::const_iterator end, int n) {
	for (; beg != end; ++beg)
		if (*beg == n)
			return true;
	return false;
}
