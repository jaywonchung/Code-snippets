#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector<int> tree;

void update(int node, int start, int end, int num, int diff) {
    if (num < start || end < num) return;
    tree[node] += diff;
    if (start!=end) {
        update(2*node, start, (start+end)/2, num, diff);
        update(2*node+1, (start+end)/2+1, end, num, diff);
    }
}

// return kth element in tree between start and end, inclusive
int kth(int node, int start, int end, int k) {
    if (start==end) {
        return start;
    } else {
        if (k <= tree[2*node]) {
            return kth(2*node, start, (start+end)/2, k);
        } else {
            return kth(2*node+1, (start+end)/2+1, end, k-tree[2*node]);
        }
    }
}

int main()
{
	// MAX = largest input number
	int MAX; scanf("%d", &MAX);
	
	// assign memory
	// tree[node] = number of elements between start and end, inclusive
	int h = (int)ceil(log2(MAX+1));
	int tree_size = (1<<(h+1))-1;
	tree.assign(tree_size, 0);
	
	// add number to tree
	update(1, 0, MAX, number, 1);
	
	// get kth element in tree
	cout << kth(1, 0, MAX, k) << '\n';
	
	return 0;
}