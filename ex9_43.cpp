/**
 * Exercise 9.43: Write a function that takes three strings, s, oldVal, and
 * newVal. Using iterators, and the insert and erase functions replace all
 * instances of oldVal that appear in s by newVal. Test your function by
 * using it to replace common abbreviations, such as “tho” by “though” and
 * “thru” by “through”.
 */

#include "iostream"
#include "string"
#include "sstream"
#include "fstream"

#define HASH_TAB_SIZE 101
#define WAY 2

typedef struct {
	std::string oldVal;
	std::string newVal;
} Pair;

Pair *hashTab[HASH_TAB_SIZE];

bool readPairs(std::ifstream &);
const std::string &format(std::string &);
unsigned hash(const std::string &);
void addPair(std::string &, std::string &);

int main(int argc, char **argv) {
	/// dealing with arguments
	if (argc != 3) {
		std::cerr << "usage: " << *argv <<
				" S_FILE PAIRS_FILE" << std::endl;
		return -1;
	}
	std::ifstream ifs_s(argv[1]);
	std::ifstream ifs_pairs(argv[2]);
	if (!ifs_pairs || !ifs_s) {
		std::cerr << argv[0] << ": failed reading files." << std::endl;
		return -1;
	}

	/// read oldVal:newVal pairs
	if (!readPairs(ifs_pairs)) {
		std::cerr << argv[0] <<
				": no valid data! Each line's format of file " <<
				argv[2] << ": oldVal newVal" << std::endl;
		return -1;
	}
	std::string line;

	// ifs_pairs.seekg(0);
	// /// output the content of files
	// std::cout << "key pairs: " << std::endl;
	// while (std::getline(ifs_pairs, line))
	// 	std::cout << line << std::endl;
	// ifs_pairs.seekg(0);
	// std::cout << "origin: " << std::endl;
	// while (std::getline(ifs_s, line))
	// 	std::cout << line << std::endl;
	// ifs_s.seekg(0);

	/// output after formatting
	while (std::getline(ifs_s, line))
		std::cout << format(line) << std::endl;
}

/// return false only if no valid data
bool readPairs(std::ifstream &ifs) {
	std::string line, oldVal, newVal;
	while (std::getline(ifs, line)) {
		std::istringstream iss(line);
		if (!(iss >> oldVal >> newVal)) {
			std::cerr << "warning: exist invalid data" << std::endl;
			continue;
		}
		addPair(oldVal, newVal);
	}
	if (oldVal.empty())
		return false;
	return true;
}

/// add oldVal:newVal pair into hashPairTab
void addPair(std::string &oldVal, std::string &newVal) {
	unsigned hashVal = hash(oldVal);
	hashTab[hashVal] = (Pair *) malloc(sizeof(Pair));
	hashTab[hashVal]->oldVal = oldVal;
	hashTab[hashVal]->newVal = newVal;
}

unsigned hash(const std::string &str) {
	unsigned hashVal = 0;
	for (const auto &c : str)
		hashVal = c + 31 * hashVal;
	return hashVal % HASH_TAB_SIZE;
}

const std::string &format(std::string &str) {
	for (auto iter = str.begin(); iter != str.cend(); ) {
		for (; isspace(*iter); ++iter) ;
		if (!isalpha(*iter) && iter != str.cend()) {
			++iter;
			continue;
		}
		std::string buf;
		while (isalpha(*iter))
			buf.push_back(*iter++);
		unsigned hashVal= hash(buf);
		if (hashTab[hashVal]) { /// found
			iter = str.erase(iter-buf.size(), iter);
			iter = str.insert(iter, hashTab[hashVal]->newVal.cbegin(),
					 hashTab[hashVal]->newVal.cend());
			std::advance(iter, hashTab[hashVal]->newVal.size());
		}
	}
	return str;
}
