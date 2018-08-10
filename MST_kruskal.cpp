#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int parent[10001];

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
    // n vertexes, m edges
    // vertexes numbered from 1 to n
    int n, m; scanf("%d %d", &n, &m);
    
    vector<tuple<int, int, int>> edge;  // cost, from, to
    for (int i=0; i<m; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        edge.emplace_back(w, u, v);
    }
    
    sort(edge.begin(), edge.end());
    
    for (int i=1; i<=n; ++i) {
        parent[i] = i;
    }
    
    // O(ElogE)
    int ans = 0;
    for (int i=0; i<m; ++i) {
        int c, s, e;
        tie(c, s, e) = edge[i];
        int x = Find(s);
        int y = Find(e);
        if (x!=y) {
            Union(x, y);
            ans += c;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
