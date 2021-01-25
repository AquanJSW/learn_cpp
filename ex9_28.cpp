/**
 * Exercise 9.28: Write a function that takes a forward_list<string> and
 * two additional string arguments. The function should find the first string
 * and insert the second immediately following the first. If the first string is
 * not found, then insert the second string at the end of the list.
 */

#include "iostream"
#include "forward_list"
#include "string"



int main() {

}

void findInsert(std::forward_list<std::string> &fls,
				std::string &s1, std::string &s2) {
	auto pre = fls.before_begin();
	for (auto cur = fls.begin(); cur != fls.cend(); pre = cur++)
		if (*cur == s1) {
			fls.insert_after(cur, s2);
			return;
		}
	fls.emplace_after(pre, s2);
}