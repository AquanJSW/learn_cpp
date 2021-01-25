/**
 * Exercise 1.11: Write a program that prompts the user for two integers.
 * Print each number in the range specified by those two integers.
 */

#include "iostream"
#include "string"

using namespace std;

void prt_range(signed start, signed end) {
	for (signed i = start+1; i != end; ++i)
		printf("%d ", i);
	putchar('\n');
}

int main() {
	printf("Give me two integers!\n");

	signed i, j;
	cin >> i >> j;

	if (i > j) {
		prt_range(j, i);
		return 0;
	}
	prt_range(i, j);
}