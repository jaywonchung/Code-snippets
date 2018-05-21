#include <cstdio>

int sum() { return 0; }

template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }

int main() 
{ 
	printf("%.2f\n", sum(5, 7, 2, 2) + sum(3.14, 4.89));
	
	return 0;
}