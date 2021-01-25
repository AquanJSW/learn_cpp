#include <fstream>
#include <forward_list>
#include "iostream"
#include "vector"
#include "cstdio"
#include "deque"
#include "algorithm"
#include "list"
#include "iterator"
#include "set"
#include "map"
#include "memory"

using namespace std;

#define PNE(cmd) std::cout << #cmd ": " << cmd << std::endl
float Q_rsqrt(float);

int main() {
	vector<int> vi{1, 2, 3, 4};
	vi.emplace(vi.cbegin()+2, (5, 5));
	vi.insert(vi.cbegin()+2, (4, 3));
	vector<int> vii = 10;
	for (auto i : vi)
		cout << i << ' ';
}

float Q_rsqrt( float number )
{
	int i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( int * ) &y;                       // evil floating point bit level hacking（对浮点数的邪恶位元hack）
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?（这他妈的是怎么回事？）
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration （第一次迭代）
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed（第二次迭代，可以删除）

	return y;
}
