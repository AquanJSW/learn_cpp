/**
 * Exercise 9.18: Write a program to read a sequence of strings from the
 * standard input into a deque. Use iterators to write a loop to print the
 * elements in the deque.
 *
 * Exercise 9.19: Rewrite the program from the previous exercise to use a
 * list. List the changes you needed to make.
 */

#include "iostream"
#include "deque"
#include "list"
#include "string"

#define LIST

int main() {
	std::string bufs;
#ifndef LIST
	std::deque<std::string> ds;
	while (std::cin >> bufs)
		ds.emplace_back(bufs);
	for (auto beg = ds.begin(); beg != ds.cend(); ++beg)
		std::cout << *beg << std::endl;
#else
	std::list<std::string> ls;
	while (std::cin >> bufs)
		ls.emplace_back(bufs);
	for (auto beg = ls.begin(); beg != ls.cend(); ++beg)
		std::cout << *beg << std::endl;
#endif
}