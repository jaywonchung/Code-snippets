#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> a, tree;

void init(int node, int start, int end) {
    if (start==end) {
        tree[node] = a[start];
    } else {
        init(2*node, start, (start+end)/2);
        init(2*node+1, (start+end)/2+1, end);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

int query(int node, int start, int end, int i, int j) {
    if (i>end || j<start) return -1;
    if (i<=start && end<=j) return tree[node];
    int m1 = query(2*node, start, (start+end)/2, i, j);
    int m2 = query(2*node+1, (start+end)/2+1, end, i, j);
    if (m1==-1) return m2;
    else if (m2==-1) return m1;
    else return min(m1, m2);
}

void update(int node, int start, int end, int index, int value) {
    if (index<start || end<index) return;
    if (start==end) {
        tree[node] = value;
    } else {
        update(2*node, start, (start+end)/2, index, value);
        update(2*node+1, (start+end)/2+1, end, index, value);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

int main()
{
    int n; scanf("%d", &n);
    int h = (int)ceil(log2(n));
    int tree_size = (1<<(h+1))-1;
    
    // allocate memory
    a.assign(n, 0);
    tree.assign(tree_size, 0);
    
    // get list of integers
    for (int i=0; i<n; ++i) {
        scanf("%d", &a[i]);
    }
    
    //create segment tree
    init(1, 0, n-1);
    
    //update
    update(1, 0, n-1, from, to);
    
    //get minimum from a[i] to a[j]
    cout << query(1, 0, n-1, i, j) <<'\n';
    
    return 0;
}
