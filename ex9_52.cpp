/**
 * Exercise 9.52: Use a stack to process parenthesized expressions. When
 * you see an open parenthesis, note that it was seen. When you see a close
 * parenthesis after an open parenthesis, pop elements down to and including
 * the open parenthesis off the stack. push a value onto the stack to
 * indicate that a parenthesized expression was replaced.
 */

#include "iostream"
#include "stack"
#include "string"

int main() {
	const std::string s(
		"This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over");
	std::stack<char> stkChar;
	constexpr char repl = '#';
	unsigned nParen = 0;

	for (auto &c : s) {
		stkChar.push(c);
		if (c == '(')
			++nParen;
		else if (nParen && c == ')') {
			while (stkChar.top() != '(')
				stkChar.pop();
			stkChar.pop();
			stkChar.push(repl);
			--nParen;
		}
	}

	std::cout << "before: " << s << std::endl;
	std::cout << "after: ";
	std::string buf;
	for (; !stkChar.empty(); stkChar.pop())
		buf.insert(0, 1, stkChar.top());
	std::cout << buf;
}