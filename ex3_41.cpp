/**
 * Exercise 3.41: Write a program to initialize a vector from an array of
 * ints.
 * Exercise 3.42: Write a program to copy a vector of ints into an array of
 * ints.
 */

#include "iostream"
#include "vector"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;

int main() {
	int arr[3] = {1, 2, 3};
	vector<int> vec(begin(arr), end(arr));
	cout << "array to vector:" << endl;
	for (auto i : vec)
		cout << i << ' ';
	cout << endl;

	int array[vec.size()];
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		array[it - vec.cbegin()] = *it;
	cout << "vector to array:" << endl;
	for (auto i : array)
		cout << i << ' ';
	cout << endl;

	return 0;
}