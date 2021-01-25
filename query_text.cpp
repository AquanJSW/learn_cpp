/**
 * Chapter 12.3: Using the library: A Text-Query Program
 */

#include "iostream"
#include "fstream"
#include "sstream"
#include "vector"
#include "map"
#include "set"
#include "cstring"
#include "memory"

using namespace std;

/// Argument parser
const char *argparse(const int &argc, char **&argv) {
	constexpr char HELP[] = "Given a file, show the line and its number that a"
	                        "specified word appeared.\n"
	                        "usage: query_text [-h] FILE\n"
	                        "OPTIONS:\n"
	                        "\t-h:\n"
	                        "\t\tshow help.";
	if (argc == 1) {
		/// no argument error
		cout << "error: no argument." << endl;
		cout << HELP << endl;
		return nullptr;
	} else if (!strcmp(argv[1], "-h")) {
		/// show help message
		cout << HELP << endl;
		return nullptr;
	} else {
		return argv[1];
	}
}

class QueryText {
public:
	explicit QueryText(ifstream &);

	void add_word(const string &word);

	void print_result(const string &word) const;

private:
	vector<string> lines;
	map<string, shared_ptr<set<unsigned>>> wn;

	shared_ptr<set<unsigned>> find_num(const string &word);
};

/// Constructor: saving the file into a vector by lines
QueryText::QueryText(ifstream &ifs) {
	string buf;
	while (getline(ifs, buf))
		lines.push_back(buf);
}

/// Add a word for query
inline void QueryText::add_word(const string &word) {
	wn.insert({word, find_num(word)});
}

/// Find the line numbers that the word appears.
inline shared_ptr<set<unsigned>> QueryText::find_num(const string &word) {
	shared_ptr<set<unsigned>> nums(new set<unsigned>);
	for (unsigned i = 0; i < lines.size(); ++i)
		if (lines.at(i).find(word) != string::npos)
			nums->insert(i);
	return nums;
}

/// Print result
inline void QueryText::print_result(const string &word) const {
	if (wn.find(word) == wn.cend()) {
		cout << '\"' << word << "\" " << "has not been queried yet." << endl;
		return;
	}
	cout << '\"' << word << "\" " << "appears " << wn.at(word)->size() << \
            " times by lines:" << endl;
	for (auto num : *wn.at(word)) {
		cout << "line " << num + 1 << ": " << lines.at(num) << endl;
	}
	cout << endl;
}

int main(int argc, char **argv) {
	auto file = argparse(argc, argv);

	if (!file)
		/// file == nullptr
		return -1;

	ifstream ifs(file);

	if (!ifs) {
		/// read failed
		cout << "error: read failed." << endl;
		return -1;
	}

	QueryText qt(ifs);
	string word;
	while (true) {
		cout << "Type a word to query or a 'q' to quit:" << endl;
		if (!(cin >> word) || word == "q")
			break;
		qt.add_word(word);
		qt.print_result(word);
	}
}