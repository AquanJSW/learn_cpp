/**
 * Exercise 9.49: A letter has an ascender if, as with d or f, part of the
 * letter extends above the middle of the line. A letter has a descender if, as
 * with p or g, part of the letter extends below the line. Write a program that
 * reads a file containing words and reports the longest word that contains
 * neither ascenders nor descenders.
 */

#include "iostream"
#include "string"
#include "fstream"
#include "vector"

#define ASCENDERS "tidfhlbjk"
#define DESCENDERS "qypgj"

struct File {
	std::string name;
	std::ifstream ifs;
	explicit File(const char *name_) : name(name_), ifs(name_) { }
};

std::vector<File> readArgs(int &, char **&);
std::string findPlain(std::ifstream &);

int main(int argc, char **argv) {
	const char *prog = *argv;
	std::vector<File> vFile;
	vFile = readArgs(argc, argv);
	if (vFile.empty()) {
		std::cout << "usage: " << prog << " FILE1 ..." << std::endl;
		return -1;
	}

	for (auto &file : vFile) {
		std::cout << file.name << ": ";
		std::string outStr = findPlain(file.ifs);
		if (outStr.empty()) {
			std::cout << "no words but ascenders or descenders." << std::endl;
			continue;
		}
		std::cout << outStr << std::endl;
	}
}

/// dealing with arguments
std::vector<File> readArgs(int &argc, char **&argv) {
	std::vector<File> vFile;
	std::ifstream ifs;
	while (--argc) {
		ifs.open(*++argv);
		if (!ifs) {
			std::cerr << "warning: failed reading file '" <<
				         *argv << "'" << std::endl;
			ifs.close();
			continue;
		}
		ifs.close();
		vFile.emplace_back(*argv);
	}
	return vFile;
}

std::string findPlain(std::ifstream &ifs) {
	std::string word, outWord;
	while (ifs >> word) {
		if (word.find_first_of(ASCENDERS DESCENDERS) == std::string::npos &&
			word.size() > outWord.size())
			outWord = word;
	}
	return outWord;
}
