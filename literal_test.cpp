#include "iostream"
#include "vector"
#include "string"

#define LITERAL_TEST(type) \
std::cout << std::is_literal_type<type>::value << " " #type << std::endl

class A {
	char a[2];
	static int *p;
	constexpr A() : a("") { };
};

class B {
	int a;
	static int count;
};

struct C {
	/** 该构造函数是使C非constexpr class的原因
	 * 满足将所有的成员初始化、body为空的条件，但不能用constexpr修饰该构造函数，
	 * 因为id的初始化值非 const expression
	 */
	C() : id(++count), foo(1) { }
	static constexpr int &getCount() { return count; }
	const int &getId() const { return id; }
private:
	static int count;
	int id, foo;
};
int C::count = 0;

int gv;
struct D {
	constexpr D() : id(1), foo(1) { }
	static constexpr int &getCount() {
		return count; }
	const int &getId() const { return id; }
private:
	static int count;
	int id, foo;
};
int D::count = 0;

class E {
	int i, j;
public:
	constexpr E() : i(0), j(0) { }
};

int main() {
	LITERAL_TEST(int);
	LITERAL_TEST(std::string);
	LITERAL_TEST(std::vector<int>);
	LITERAL_TEST(int[]);
	LITERAL_TEST(char[]);
	LITERAL_TEST(int &);
	LITERAL_TEST(int *);
	LITERAL_TEST(A);
	LITERAL_TEST(B);
	LITERAL_TEST(C);
	LITERAL_TEST(D);
	C a, b, c;
	std::cout << std::endl;
	std::cout << C::getCount() << std::endl;
	std::cout << a.getId() << std::endl;
	std::cout << b.getId() << std::endl;
	std::cout << c.getId() << std::endl;
}
