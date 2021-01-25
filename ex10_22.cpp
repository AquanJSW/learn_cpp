/**
 * Exercise 10.22: Rewrite the program to count words of size 6 or less using
 * functions in place of the lambdas.
 */

#include "algorithm"
#include "string"
#include "vector"
#include "iostream"
#include "functional"

using namespace std;
using namespace std::placeholders;

bool isSatisfy(const string &, const int &);

int main() {
	std::vector<std::string> vs{"a", "an", "this", "forward", "back",
	                            "lexicographical", "future"};
	constexpr int threshold = 6;

	/// print origin
	cout << "origin: ";
	for (auto &s : vs)
		cout << s << endl;

	cout << string(80, '-') << endl;

	/// count
	cout << "the count of words that no longer than 6: ";
	cout << count_if(vs.cbegin(), vs.cend(), bind(isSatisfy, _1, threshold)) <<
			endl;
}

bool isSatisfy(const string &s, const int &n) {
	return s.size() <= n;
}
