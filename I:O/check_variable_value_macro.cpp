#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>
using namespace std;

#define check(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); chk(_it, args); }

void chk(istream_iterator<string> it) {}

template<typename T, typename... Args>
void chk(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	chk(++it, args...);
}

int main() {
	int a = 4, b = 8, c = 9;
	float d = 4.5;
	check(a, b, c, d);
	
	return 0;
}