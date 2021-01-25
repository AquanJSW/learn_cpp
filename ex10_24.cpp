/**
 * Exercise 10.24: Use bind and check_size to find the first element in a
 * vector of ints that has a value greater than the length of a specified
 * string value.
 */

#include "iostream"
#include "functional"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;
using namespace std::placeholders;

int main() {
	const string str = "HELLO";
	const vector<int> vi{6, 2, 5, 4, 1, 6, 7};

	/// origin data print
	cout << "string: " << str << endl;
	cout << "vi: ";
	for (auto iter = vi.begin(); iter != vi.cend(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	/// find
	cout << "out: " <<
			find(vi.cbegin(), vi.cend(), str.size()) - vi.cbegin() << endl;
}