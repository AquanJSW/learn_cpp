/**
 * Exercise 5.23: Write a program that reads two integers from the standard
 * input and prints the result of dividing the first number by the second.
 */

#include "iostream"
#include "stdexcept"

int main() {
	std::cout << "Input 2 integers in order for division:" << std::endl;
	int a, b;

	while (std::cin >> a >> b)
		try {
			if (!b)
				throw std::runtime_error("zero divisor.");
			std::cout << "a / b = " << static_cast<double>(a) / b << std::endl;
		} catch (std::runtime_error &err) {
			std::cout << err.what() << std::endl;
			std::cout << "Wanna input again? ('y' for yes, 'n' for no)" <<
				std::endl;
			char c;
			std::cin >> c;
			if (c == 'y')
				continue;
			else
				break;
		}
	return 0;
}