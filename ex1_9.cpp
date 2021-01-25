/**
 * Exercise 1.9: Write a program that uses a while to sum the numbers from
 * 50 to 100.
 */

#include "cstdio"

int main() {
	unsigned int i = 50;
	unsigned int end = 100;
	unsigned int sum = 0;

	while (i <= end) {
		sum += i;
		++i;
	}

	printf("sum: %d\n", sum);
}