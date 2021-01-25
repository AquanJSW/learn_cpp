/**
 * Exercise 9.26: Using the following definition of ia, copy ia into a vector
 * and into a list. Use the single-iterator form of erase to remove the
 * elements with odd values from your list and the even values from your
 * vector.
 * int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
 *
 * Exercise 9.27: Write a program to find and remove the odd-valued
 * elements in a forward_list<int>.
 */

#include "iostream"
#include "vector"
#include "list"
#include "forward_list"

int main() {
	const int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	std::vector<int> vi;
	std::list<int> li;
	std::forward_list<int> fli;
	auto fli_it = fli.before_begin();
	/// initialization
	for (const int &n : ia) {
		vi.emplace_back(n);
		li.emplace_back(n);
		fli.emplace_after(fli_it, n);
		if (fli_it == fli.before_begin()) {
			fli_it = fli.begin();
			continue;
		}
		++fli_it;
	}

	for (auto it = vi.begin(); it != vi.cend(); ) {
		if (*it % 2) {
			++it;
			continue;
		}
		it = vi.erase(it);
	}
	std::cout << "vector with evens: ";
	for (const int &n : vi)
		std::cout << n << " ";
	std::cout << std::endl;

	for (auto it = li.begin(); it != li.cend(); ) {
		if (*it % 2) {
			it = li.erase(it);
			continue;
		}
		++it;
	}
	std::cout << "list with odds: ";
	for (const int &n : li)
		std::cout << n << " ";
	std::cout << std::endl;

	for (auto cur = fli.begin(), pre = fli.before_begin(); cur != fli.cend();) {
		if (*cur % 2) {
			cur = fli.erase_after(pre);
			continue;
		}
		pre = cur++;
	}
	std::cout << "forward_list with evens: ";
	for (const int &n : fli)
		std::cout << n << " ";
	std::cout << std::endl;
}