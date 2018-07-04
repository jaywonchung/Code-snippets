#include <cstdio>
#include <map>
using namespace std;

int n;
int a[1000];

int compress() {	//compresses coordinates from 1 and returns maximum value
	map<int, int> m;
	for (int i=0; i<n; ++i) {
		m[a[i]] = 0;
	}
	
	int index = 0;
	for (auto& p : m) {
		p.second = ++index;
	}
	
	for (int i=0; i<n; ++i) {
		a[i] = m[a[i]];
	}
	
	return index;
}

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", a+i);
	}
	
	int hi = compress();
	
	return 0;
}