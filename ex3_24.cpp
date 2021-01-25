/**
 * Exercise 3.24: Redo the last exercise from § 3.3.3 (p. 105) using iterators.
 *
 * Exercise 3.20: Read a set of integers into a vector. Print the sum of each
 * pair of adjacent elements. Change your program so that it prints the sum of
 * the first and last elements, followed by the sum of the second and second-
 * tolast, and so on.
 */

#include "iostream"
#include "vector"

#define ADJACENT 0

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
	cout << "Input some integers:" << endl;

	vector<int> vi;
	int temp;
	while (cin >> temp)
		vi.push_back(temp);
#if ADJACENT
	for (auto it_vi = vi.begin(); it_vi <= vi.cend(); it_vi += 2)
		cout << *it_vi + *(it_vi+1) << ' ';
	if ((vi.cend() - vi.cbegin()) / 2)
		cout << *(vi.cend() - 1);
#else
	auto head = vi.begin();
	auto tail = vi.end() - 1;
	for (; head < tail; head++, tail--)
		cout << *head + *tail << ' ';
	if (head == tail)
		cout << *head;
#endif
	cout << endl;
	return 0;
}