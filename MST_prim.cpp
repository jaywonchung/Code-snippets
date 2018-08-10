#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

bool check[1001];   // true if vertex i is in MST
vector<pair<int, int>> graph[1001];

// O(ElogE)
int prim(int n) {
    priority_queue<tuple<int, int, int>> q; // -cost, from, to
    
    check[1] = true;
    for (auto p : graph[1]) {
        q.emplace(-p.second, 1, p.first);
    }
    
    long long ans = 0LL;
    for (int i=0; i<n-1; ++i) {
        int c, s, e;
        while (!q.empty()) {    // find vertex with minimum cost amongst those not in the MST yet
            tie(c, s, e) = q.top(); q.pop();
            if (!check[e]) break;
        }
        check[e] = true;
        ans -= c;
        for (auto y : graph[e]) {
            q.emplace(-y.second, e, y.first);
        }
    }
    
    return ans;
}

int prim_tree(int n) {
    priority_queue<tuple<int, int, int>> q; // -cost, from, to
    
    check[1] = true;
    for (auto p : graph[1]) {
        q.emplace(-p.second, 1, p.first);
    }
    
    long long ans = 0LL;
    for (int i=0; i<n-1; ++i) {
        int c, s, e;
        while (!q.empty()) {    // find vertex with minimum cost amongst those not in the MST yet
            tie(c, s, e) = q.top(); q.pop();
            if (!check[e]) break;
        }
        check[e] = true;
        printf("%d - %d\n", s, e);
        ans -= c;
        for (auto y : graph[e]) {
            q.emplace(-y.second, e, y.first);
        }
    }
    
    return ans;
}

int main()
{
    // n vertexes, m undirected edges
    // vertexes numbered from 1 to n
    int n, m; scanf("%d %d", &n, &m);
    for (int i=0; i<m; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    
    // calculate the minimum cost sum of creating an MST
    cout << prim(n) << '\n';
    
    // calculate the minimum cost sum of creating an MST and print the MST
    cout << prim_tree(n) << '\n';
    
    return 0;
}
