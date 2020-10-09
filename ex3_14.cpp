/**
 * Exercise 3.14: Write a program to read a sequence of ints from cin and
 * store those values in a vector.
 *
 * Exercise 3.15: Repeat the previous program but read strings this time.
 */

#include "iostream"
#include "vector"
#include "string"

#define VER_1

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() 
#ifdef VER_0
	vector<int> vi;
	int i;

	while (cin >> i)
		vi.push_back(i);

	cout << vi.size() << endl;
#else
	vector<string> sv;
	string buf;

	while (cin >> buf)
		sv.push_back(buf);
	cout << sv.size() << endl;
#endif
	return 0;
}