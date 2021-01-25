/**
 * Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive,
 * into three other containers. Use an inserter, a back_inserter, and a
 * front_inserter, respectively to add elements to these containers. Predict
 * how the output sequence varies by the kind of inserter and verify your
 * predictions by running your programs.
 */

#include "iostream"
#include "vector"
#include "algorithm"
#include "deque"

using namespace std;

void print(const vector<int> &);
void print(const deque<int> &);

int main() {
	const vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
	deque<int> vi1, vi2, vi3;
	copy(vi.cbegin(), vi.cend(), inserter(vi1, vi1.begin()));
	copy(vi.cbegin(), vi.cend(), back_inserter(vi2));
	copy(vi.cbegin(), vi.cend(), front_inserter(vi3));
	cout << "vi: ";
	print(vi);
	cout << endl;
	cout << "vi1: ";
	print(vi1);
	cout << endl;
	cout << "vi2: ";
	print(vi2);
	cout << endl;
	cout << "vi3: ";
	print(vi3);
	cout << endl;
}

void print(const vector<int> &vi) {
	for (auto iter = vi.begin(); iter != vi.cend(); ++iter)
		cout << *iter << ' ';
}
void print(const deque<int> &vi) {
	for (auto iter = vi.begin(); iter != vi.cend(); ++iter)
		cout << *iter << ' ';
}
