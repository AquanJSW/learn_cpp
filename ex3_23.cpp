/**
 * Exercise 3.23: Write a program to create a vector with ten int elements.
 * Using an iterator, assign each element a value that is twice its current
 * value. Test your program by printing the vector.
 */

#include "iostream"
#include "vector"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
	vector<int> vi;
	for (int i = 0; i != 10; i++)
		vi.push_back(i);
	for (auto it_vi = vi.begin(); it_vi != vi.cend(); it_vi++) {
		*it_vi *= 2;
		cout << *it_vi << ' ';
	}
	cout << endl;
	return 0;
}