/**
 * Exercise 3.43: Write three different versions of a program to print the
 * elements of ia. One version should use a range for to manage the
 * iteration, the other two should use an ordinary for loop in one case using
 * subscripts and in the other using pointers. In all three programs write all
 * the types directly. That is, do not use a type alias, auto, or decltype to
 * simplify the code.
 *
 * Exercise 3.44: Rewrite the programs from the previous exercises using a
 * type alias for the type of the loop control variables.
 */

#include "iostream"

using std::cout;
using std::cin;
using std::endl;
using std::end;
using std::begin;

int main() {
	int ia[3][4];
	int i = 0;
	for (int (&row)[4] : ia)
		for (int &col : row)
			col = i++;

	/* version 1 */
	for (const int (&row)[4] : ia)
		for (int col : row)
			cout << col << ' ';
	cout << endl;
	/* version 2 */
	for (int row = 0; row != 3; row++)
		for (int col = 0; col != 4; col++)
			cout << ia[row][col] << ' ';
	cout << endl;
	/* version 3 */
	for (int (*row)[4] = ia; row < ia+3; row++)
		for (int *col = *row; col < *row+4; col++)
			cout << *col << ' ';
	cout << endl;
	/* version 4 */
	typedef int int_array_4[4];
	for (int_array_4 *row = ia; row < ia+3; row++)
		for (int *col = *row; col < *row+4; col++)
			cout << *col << ' ';
	cout << endl;
	return 0;
}