#include <iostream>
using namespace std;

int a[100][100];

int main()
{
	int n=10, m=12;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			a[i][j] = i+j;
		}
	}
	
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cout<<a[i][j]<<" \n"[j==m-1];
		}
	}
	
	return 0;
}