#include <cstdio>

int parent[100];

int Find(int x) {
    if (x==parent[x]) {
        return x;
    } else {
        return parent[x] = Find(parent[x]);
    }
}

int Union(int x, int y) {
    parent[Find(x)] = Find(y);
}

int main()
{
    // n = max number of elements
    int n; scanf("%d", &n);
    
    // initialize parent array
    for (int i=0; i<n; ++i) {
        parent[i] = i;
    }
    
    // union a and b
    Union(a, b);
    
    // find the parent of a
    cout << Find(a) << '\n';
    
    // chcek of a and b are in the same set
    if (Find(a)==Find(b))
    
    
    return 0;
}
