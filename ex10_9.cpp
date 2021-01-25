/**
 * Exercise 10.9: Implement your own version of elimDups. Test your
 * program by printing the vector after you read the input, after the call to
 * unique, and after the call to erase.
 *
 * Exercise 10.11: Write a program that uses stable_sort and isShorter
 * to sort a vector passed to your version of elimDups. Print the vector to
 * verify that your program is correct.
 */

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

std::vector<std::string> read(std::istream &);
bool isShorter(const std::string &, const std::string &);

/**
 * get input from standard input
 */
int main() {
	std::vector<std::string> vs = read(std::cin);

	/// alphabetic sort first
	std::sort(vs.begin(), vs.end());

	/// delete duplicates
	auto vs_end = std::unique(vs.begin(), vs.end());
	/// align the logical end and physical end of vs (not necessary but better)
	vs.erase(vs_end, vs.end());

	/**
	 * stable sort by length
	 * (maintain the lexicographical order within a length)
	 */
	 std::sort(vs.begin(), vs.end(), isShorter);

	 /// output
	 std::cout << std::string(80, '-') << std::endl;
	 for (auto &s : vs)
	 	std::cout << s << std::endl;
}

std::vector<std::string> read(std::istream &is) {
	std::vector<std::string> vs;
	std::string s;

	while (is >> s)
		vs.push_back(s);
	return vs;
}

bool isShorter(const std::string &s1, const std::string &s2) {
	return s1.size() < s2.size();
}
