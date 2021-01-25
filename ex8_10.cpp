/**
 * exercise 8.10: Write a program to store each line from a file in a
 * vector<string>. Now use an istringstream to read each element from
 * the vector a word at a time.
 */

#include <fstream>
#include "sstream"
#include "iostream"
#include "vector"

#define PNE(cmd) std::cout << #cmd ": " << cmd << std::endl

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "usage: " << *argv << " FILE_PATH" << std::endl;
		return -1;
	}
	std::ifstream ifs(*++argv);
	if (!ifs) {
		std::cout << *argv << ": read failed." << std::endl;
		return -1;
	}
	std::vector<std::string> vw, vl;
	std::string bufl;
	std::string bufw;
	while (std::getline(ifs, bufl)) {
		vl.emplace_back(bufl);
		std::istringstream iss(bufl);
		while (iss >> bufw)
			vw.emplace_back(bufw);
	}
	PNE(vl.size());
	PNE(vw.size());
}
