#include <cstdio>

int a[10];

int main()
{
	int n = 10;
	
	// initialize list
	for (int i=0; i<n; ++i) {
		a[i] = i+1;
	}
	
	// print list
	for (int i=0; i<n; ++i) {
		printf("%c%d%c", " ["[i==0], a[i], ",]"[i==n-1]);
	}
	
	return 0;
}