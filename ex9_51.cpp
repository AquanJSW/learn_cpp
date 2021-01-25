/**
 * Exercise 9.51: Write a class that has three unsigned members
 * representing year, month, and day. Write a constructor that takes a string
 * representing a date. Your constructor should handle a variety of date
 * formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.
 */

#include "iostream"
#include "string"
#include "vector"

#define HASH_TAB_SIZE 23

struct Date {
	Date() = default;
	explicit Date(const std::string &);
	constexpr unsigned getYear() const { return year; }
	constexpr unsigned getMonth() const { return month; }
	constexpr unsigned getDay() const { return day; }
private:
	unsigned year, month, day;
};
enum {MDY, YMD};
struct Month {
	std::string name;
	unsigned n;
	Month *next;
};
Month *hashTab[HASH_TAB_SIZE];

std::vector<unsigned> interpret(const std::string &);
unsigned hash(const std::string &);
unsigned findHash(const std::string &);
int tell(const std::vector<unsigned> &);
bool validDay(const unsigned &, const unsigned &, const unsigned &);
void initHashTab();

int main() {
	initHashTab();
	std::string line;
	while (std::getline(std::cin, line)) {
		Date date(line);
		std::cout << "month: " << date.getMonth() << " day: " <<
			date.getDay() << " year: " << date.getYear() << std::endl;
	}
}

Date::Date(const std::string &str) {
	std::vector<unsigned> rawDate;
	rawDate = interpret(str);
	switch (tell(rawDate)) {
		case MDY:
			month = rawDate[0];
			day = rawDate[1];
			year = rawDate[2];
			break;
		case YMD:
			year = rawDate[0];
			month = rawDate[1];
			day = rawDate[2];
			break;
		default:
			std::cerr << "unrecognised date" << std::endl;
	}
}

std::vector<unsigned> interpret(const std::string &str) {
	std::vector<unsigned> rawDate;
	auto iter = str.begin();
	while (iter != str.cend()) {
		while (!isalnum(*iter))
			++iter;
		std::string buf;
		for (; isalnum(*iter); ++iter)
			buf.push_back(*iter);
		/// is month
		if (isalpha(buf[0])) {
			/// not found
			unsigned n;
			if (!(n = findHash(buf))) {
				rawDate.clear();
				return rawDate;
			}
			rawDate.push_back(n); /// found
		/// is number
		} else
			rawDate.push_back(std::stoi(buf));
	}
	return rawDate;
}

unsigned hash(const std::string &str) {
	unsigned hashVal = 0;
	for (auto &c : str)
		hashVal = c + 31 * hashVal;
	return hashVal % HASH_TAB_SIZE;
}

/// return digital month. 0 if not found
unsigned findHash(const std::string &name) {
	Month *node = hashTab[hash(name)];
	for (; node; node = node->next)
		if (node->name == name)
			break;
	if (!node) /// not found
		return 0;
	return node->n;
}

/**
 * tell the date format
 *
 * Simply based on the position of biggest number - year
 */
int tell(const std::vector<unsigned> &rawDate) {
	unsigned maxIdx = 0;
	for (auto iter = rawDate.begin()+1; iter != rawDate.cend(); ++iter)
		if (*iter > rawDate[maxIdx])
			maxIdx = iter - rawDate.cbegin();
	if (maxIdx == 0 && rawDate[1] <= 12 &&
		validDay(rawDate[0], rawDate[1], rawDate[2]))
		return YMD;
	else if (maxIdx==2 && rawDate[0] <= 12 &&
			 validDay(rawDate[2], rawDate[0], rawDate[1]))
		return MDY;
	return -1; /// unrecognised
}

bool validDay(const unsigned &year, const unsigned &month, const unsigned &day){
	bool leap = !(year % 4) && year % 100 || !(year % 400);
	static constexpr char dayTab[][13] = {
			{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	return day <= dayTab[leap][month];
}

void initHashTab() {
	static const std::vector<std::string> months{"January", "February", "March",
	    "April", "May", "Jane", "July","August", "September", "October",
	    "November", "December", "Jan", "Feb", "Mar", "Apr", "Jan", "Jul",
	    "Aug", "Sep", "Oct", "Nov", "Dec"};                // 16
	for (auto iter = months.begin(); iter != months.cend(); ++iter) {
		unsigned hashVal = hash(*iter);
		Month **node = &hashTab[hashVal];
		for (; *node; node = &(*node)->next) ;
		*node = (Month *) malloc(sizeof(Month));
		(*node)->name = *iter;
		(*node)->n = iter-months.cbegin() >= 16 ?
			(iter-months.cbegin()+2) % 12 : (iter-months.cbegin()+1) % 12;
	}
}
