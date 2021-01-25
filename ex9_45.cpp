/**
 * Exercise 9.45: Write a function that takes a string representing a name
 * and two other strings representing a prefix, such as “Mr.” or “Ms.” and a
 * suffix, such as “Jr.” or “III”. Using iterators and the insert and append
 * functions, generate and return a new string with the suffix and prefix
 * added to the given name.
 *
 * Exercise 9.46: Rewrite the previous exercise using a position and length to
 * manage the strings. This time use only the insert function.
 */

#include "iostream"
#include "string"

#define WAY 2

std::string &func(std::string &name, const std::string &prefix,
                  const std::string &suffix);
std::string &func(const std::string &name, const std::string &prefix,
                  const std::string &suffix);

int main() {
	std::cout << func("May", "Ms.", "II") << std::endl;
}

std::string &func(std::string &name, const std::string &prefix,
				  const std::string &suffix) {
	name.insert(0, prefix);
#if WAY == 1
	name.append(suffix.cbegin(), suffix.cend());
#else
	name.insert(name.size(), suffix);
#endif
	return name;
}

std::string &func(const std::string &name, const std::string &prefix,
                  const std::string &suffix) {
	return func(const_cast<std::string &>(name), prefix, suffix);
}
