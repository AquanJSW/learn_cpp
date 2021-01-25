/**
 * Exercise 3.25: Rewrite the grade clustering program from § 3.3.3 (p. 104)
 * using iterators instead of subscripts.
 */

#include "iostream"
#include "vector"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
	cout << "Input grades:" << endl;

	vector<unsigned> gradeClusters(11);
	double grade;
	while (cin >> grade)
		if (grade >= 0 && grade <= 100)
			(*(gradeClusters.begin() + (unsigned) grade / 10))++;
		else {
			fprintf(stderr, "invalid grade.\n");
			return 1;
		}

	for (unsigned i = 0; i != 10; i++)
		printf("%2d-%2d ", 10 * i, 10 * i + 9);
	printf("%5d\n", 100);
	for (auto it = gradeClusters.begin(); it != gradeClusters.cend(); it++)
		printf("%5d ", *it);
	cout << endl;
	return 0;
}