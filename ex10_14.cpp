/**
 * Exercise 10.14: Write a lambda that takes two ints and returns their sum.
 *
 * Exercise 10.15: Write a lambda that captures an int from its enclosing
 * function and takes an int parameter. The lambda should return the sum of
 * the captured int and the int parameter.
 *
 * Exercise 10.21: Write a lambda that captures a local int variable and
 * decrements that variable until it reaches 0. Once the variable is 0
 * additional calls should no longer decrement the variable. The lambda should
 * return a bool that indicates whether the captured variable is 0.
 */

#include "iostream"

int main() {
	auto lambda = [] (const int &i1, const int &i2) {return i1+i2;};

	int i = 24;
	auto lambda1 = [i] (const int &arg) {return i + arg;};

	auto lambda2 = [&i] () -> bool {
		if (i < 0)
			return false;
		while (i)
			--i;
		return true;
	}
}