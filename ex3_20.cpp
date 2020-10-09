/**
 * Exercise 3.20: Read a set of integers into a vector. Print the sum of each
 * pair of adjacent elements. Change your program so that it prints the sum of
 * the first and last elements, followed by the sum of the second and second-
 * tolast, and so on.
 */

#include "iostream"
#include "vector"

#define ADJACENCY 0

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
	cout << "Input some integers:" << endl;

	vector<int> vi;
	int temp;
	unsigned size = 0;
	while (cin >> temp) {
		vi.push_back(temp);
		size++;
	}

#if ADJACENCY == 1
	cout << "Adjancent sum:" << endl;
	for (unsigned i = 0; i < size; i++)
		if (i % 2)
			cout << vi[i] + vi[i-1] << ' ';
	if (size % 2)
		cout << vi[size-1];
#else
	cout << "First-last sum:" << endl;
	for (unsigned i = 0; i < size / 2; i++)
		cout << vi[i] + vi[size-i-1] << ' ';
	if (size % 2)
		cout << vi[size / 2];
#endif
	cout << endl;
	return 0;
}