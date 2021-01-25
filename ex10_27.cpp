/**
 * Exercise 10.27: In addition to unique (§ 10.2.3, p. 384), the library
 * defines function named unique_copy that takes a third iterator denoting a
 * destination into which to copy the unique elements. Write a program that
 * uses unique_copy to copy the unique elements from a vector into an
 * initially empty list.
 */

#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int main() {
	vector<int> viS{1, 4, 3, 2, 2, 5, 2, 3, 6, 1};
	vector<int> viD;

	sort(viS.begin(), viS.end());
	unique_copy(viS.cbegin(), viS.cend(), back_inserter(viD));

	/// output
	for (auto iter = viD.begin(); iter != viD.cend(); ++iter)
		cout << *iter << ' ';
}