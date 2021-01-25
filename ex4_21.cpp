/**
 * Exercise 4.21: Write a program to use a conditional operator to find the
 * elements in a vector<int> that have odd value and double the value of
 * each such element
 */

#include "iostream"
#include "vector"

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

	for (int &i : vi)
		i *= i % 2 ? 2 : 1;
	for (const int i : vi)
		cout << i << ' ';
	cout << endl;
	return 0;
}