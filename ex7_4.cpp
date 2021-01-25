/**
 * Exercise 7.4: Write a class named Person that represents the name and
 * address of a person. Use a string to hold each of these elements.
 * Subsequent exercises will incrementally add features to this class.
 *
 * Exercise 7.5: Provide operations in your Person class to return the name
 * and address. Should these functions be const? Explain your choice.
 *
 * Exercise 7.9: Add operations to read and print Person objects to the code
 * you wrote for the exercises in § 7.1.2 (p. 260).
 */

#include "iostream"
#include "string"

struct Person {
	friend void fprint(const Person &);

	const std::string &getName() const {
		return name;
	}
	const std::string &getAddr() const {
		return address;
	}
	std::istream &read(std::istream &is, std::ostream &os = std::cout) {
		os << "Input name first, then address: " << std::endl;
		is >> name >> address;
		return is;
	}
	std::ostream &print(std::ostream &os) const {
		os << "Name: " << name << std::endl;
		os << "Address: " << address << std::endl;
		return os;
	}

	// constructors
	Person() = default;
	Person(const std::string &name, const std::string &a) : name(name), address(a) {};
	explicit Person(std::istream &);

private:
	std::string name, address;
};

Person::Person(std::istream &is) {
	this->read(is);
}

void fprint(const Person &person) {
	std::cout << person.name << ' ' << person.address << std::endl;
}

int main () {
	Person person(std::cin);
	person.print(std::cout);
	person.read(std::cin);
	person.print(std::cout);
}

