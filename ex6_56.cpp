/**
 * Exercise 6.54: Write a declaration for a function that takes two int
 * parameters and returns an int, and declare a vector whose elements have
 * this function pointer type.
 *
 * Exercise 6.55: Write four functions that add, subtract, multiply, and divide
 * two int values. Store pointers to these values in your vector from the
 * previous exercise.
 *
 * Exercise 6.56: Call each element in the vector and print their result.
 */

#include "iostream"
#include "vector"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

int main() {
	vector<int (*)(int, int)> calc = {add, subtract, multiply, divide};

	cout << "Input 2 integers:" << endl;
	int a, b;
	while (cin >> a >> b) {
		cout << "add: " << calc[0](a, b) << endl;
		cout << "subtract: " << calc[1](a, b) << endl;
		cout << "multiply: " << calc[2](a, b) << endl;
		cout << "divide: " << calc[3](a, b) << endl;
	}
}

int add(int a, int b) {
	return a+b;
}

int subtract(int a, int b) {
	return a-b;
}

int multiply(int a, int b) {
	return a*b;
}

int divide(int a, int b) {
	return a/b;
}