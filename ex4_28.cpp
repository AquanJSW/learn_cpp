/**
 * Exercise 4.28: Write a program to print the size of each of the built-in
 * types.
 */

#include "iostream"
#include "string"
#include "vector"

#define SIZE(str) cout << "sizeof(" << #str << "): " << sizeof(str) << endl

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main() {
	SIZE(bool);
	SIZE(char);
	SIZE(short);
	SIZE(int);
	SIZE(long);
	SIZE(long long);
	SIZE(float);
	SIZE(double);
	SIZE(long double);
	return 0;
}