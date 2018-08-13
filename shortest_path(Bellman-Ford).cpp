#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;

int dist[501];  // distance from start node
const int inf = 1e9;
vector<tuple<int, int, int>> edges;

bool bf(int n) {
    for (int i=2; i<=n; ++i) {
        dist[i] = inf;
    }
    
    int s, e, c;
    bool is_loop = false;
    for (int k=1; k<=n; ++k) {
        for (auto edge : edges) {
            tie(s, e, c) = edge;
            if (dist[e] > dist[s] + c) {
                dist[e] = dist[s] + c;
                // if the nth result differs from the (n-1)th,
                // there is a loop and the shortest path is not defined
                if (k==n) {
                    is_loop = true;
                }
            }
        }
    }
    
    return is_loop;
}

int main()
{
    int n, m; scanf("%d %d", &n, &m);
    
    for (int i=0; i<m; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        edges.emplace_back(u, v, w);
    }
    
    bool is_loop = bf(n);
    
    if (is_loop) {
        printf("-1\n");
    } else {
        for (int i=2; i<=n; ++i) {
            if (dist[i]>=inf) printf("-1\n");
            else printf("%d\n", dist[i]);
        }
    }
    
        
    return 0;
}