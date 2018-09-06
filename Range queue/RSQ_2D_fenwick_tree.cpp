#include <cstdio>

int n, m;
int a[1001][1001];
int tree[1001][1001];	//tree[i] = sum(a[i-(i&-i)+1][j-(j&-j)+1] ~ a[i][j]); (i & -i) = last bit

int sum(int x, int y) {
	int ans = 0;
	for (int i=x; i>0; i-=(i&-i)) {
		for (int j=y; j>0; j-=(j&-j)) {
			ans += tree[i][j];
		}
	}
	return ans;
}

void update(int x, int y, int diff) {
	for (int i=x; i<=n; i+=(i&-i)) {
		for (int j=y; j<=n; j+=(j&-j)) {
			tree[i][j] += diff;
		}
	}
}

int main()
{
	int n; scanf("%d", &n);
	
	//get lsit of integers and initialize fenwick tree
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			scanf("%d", a[i]+j);
			update(i, j, a[i][j]);
		}
	}
	
	//add diff to a[i][j]
	update(i, j, diff);
	
	//get sum of all elements from a[0][0] to a[i][j];
	cout << sum(i, j) << '\n';
	
	//get sum of all elements from a[x1][y1] to a[x2][y2];
	cout << sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1) << '\n';
	
	return 0;
}