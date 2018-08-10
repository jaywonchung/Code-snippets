#include <cstdio>
#include <vector>
using namespace std;

vector<int> tree;

int sum(int i) {
	int ans = 0;
	while (i>0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(int i, int diff) {
	while (i<tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int main()
{
	int n; scanf("%d", &n);
	
	//allocate memory
	tree.assign(n+1, 0);	//tree[i] = sum(a[i-(i&-i)+1] ~ a[i]); (i & -i) = last bit
	vector<int> a(n+1);
	
	//get lsit of integers and initialize fenwick tree
	for (int i=1; i<=n; ++i) {
		scanf("%d", &a[i]);
		update(i, a[i]);
	}
	
	//add diff to a[i]
	update(i, diff);
	
	//get sum of all elements from a[0] to a[i];
	cout << sum(i) << '\n';
	
	return 0;
}
