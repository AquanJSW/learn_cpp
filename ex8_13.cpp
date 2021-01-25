/**
 * Exercise 8.13: Rewrite the phone number program from this section to read
 * from a named file rather than from cin.
 */

#include "iostream"
#include "vector"
#include "sstream"
#include "fstream"

void validate(const std::string &);

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "usage: " << *argv << " ADDRESS_BOOK_PATH" << std::endl;
		return -1;
	}
	std::ifstream ifs(*++argv);
	if (!ifs) {
		std::cout << *argv << ": read failed." << std::endl;
		return -1;
	}
	std::string bufl;
	while (std::getline(ifs, bufl))
		validate(bufl);
}

struct Person {
	std::string name;
	std::vector<std::string> phones;
};

inline bool valid(const std::string &);

void validate(const std::string &line_) {
	std::istringstream line(line_);
	Person person;
	line >> person.name; /// get name
	std::string phone;
	while (line >> phone) {
		if (!valid(phone)) {
			std::cerr << "Warning: Wrong phone number: " << person.name <<
			          ": " << phone << std::endl;
			return;
		}
		person.phones.emplace_back(phone);
	}
	std::cout << person.name << ": ";
	for (const auto &num : person.phones)
		std::cout << num << " ";
	std::cout << std::endl;
}

inline bool valid(const std::string &phone) {
	return phone.size() == 3;
}
