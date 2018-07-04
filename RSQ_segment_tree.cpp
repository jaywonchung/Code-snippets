#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector<long long> a, tree, lazy;

void init(int node, int start, int end) {
    if (start==end) {
        tree[node] = a[start];
    } else {
        init(2*node, start, (start+end)/2);
        init(2*node+1, (start+end)/2+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update_lazy(int node, int start, int end) {
    if (lazy[node]!=0) {
        tree[node] += (end-start+1)*lazy[node];
        if (start!=end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int start, int end, int i, int j, long long dif) {
    update_lazy(node, start, end);  // first apply changes postponed by lazy propagation. the node is now up to date.
    if (i>end || j<start) {
        return;
    }
    if (i<=start && end<=j) {
        tree[node] += (end-start+1)*dif;
        if (start != end) {
            lazy[2*node] += dif;
            lazy[2*node+1] += dif;
        }
        return;
    }
    update_range(2*node, start, (start+end)/2, i, j, dif);
    update_range(2*node+1, (start+end)/2+1, end, i, j, dif);
    tree[node] = tree[2*node] + tree[2*node+1];
}

long long query(int node, int start, int end, int i, int j) {
    update_lazy(node, start, end);  // first apply changes postponed by lazy propagation. the node is now up to date.
    if (i>end || j<start) return 0;
    if (i<=start && end<=j) return tree[node];
    return query(2*node, start, (start+end)/2, i, j) + query(2*node+1, (start+end)/2+1, end, i, j);
}

int main()
{
    int n; scanf("%d", &n);
    int h = (int)ceil(log2(n));
    int tree_size = (1<<(h+1))-1;
    
    // allocate memory
    a.assign(n, 0);
    lazy.assign(tree_size, 0);  // this version uses lazy propagation
    tree.assign(tree_size, 0);
    
    // get list of integers
    for (int i=0; i<n; ++i) {
        scanf("%d", &a[i]);
    }
    
    // create segment tree
    init(1, 0, n-1);
    
    // add dif to all elements from a[i] to a[j]
    update_range(1, 0, n-1, i, j, dif);
    
    // get sum of all elements from a[i] to a[j]
    cout << query(1, 0, n-1, i, j) << '\n';
    
    return 0;
}
