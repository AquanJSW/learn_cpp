#include "iostream"
#include "vector"
#include "string"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
	vector<string> vs{"a"};
	auto iter_vs = vs.cbegin();
	cout << (*iter_vs).empty();
}

