/**
 * Exercise 10.20: The library defines an algorithm named count_if. Like
 * find_if, this function takes a pair of iterators denoting an input range and
 * a predicate that it applies to each element in the given range. count_if
 * returns a count of how often the predicate is true. Use count_if to rewrite
 * the portion of our program that counted how many words are greater than
 * length 6.
 */

#include "iostream"
#include "algorithm"
#include "vector"
#include "string"

int main() {
	std::vector<std::string> vs{"a", "an", "this", "forward", "back",
	                            "lexicographical", "future"};
	constexpr int threshold = 6;
	std::cout << "origin: " << std::endl;
	std::for_each(vs.begin(), vs.end(),
			   [] (const std::string &s) {std::cout << s << std::endl;});
	std::cout << "the count of words that longer than " << threshold << ": ";
	std::cout << std::count_if(vs.cbegin(), vs.cend(),
							[&] (const std::string &s)
							{return s.size() > threshold;}) << std::endl;
}