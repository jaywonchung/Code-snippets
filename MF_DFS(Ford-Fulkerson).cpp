#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct MaximumFlow {
    struct Edge {
        int to, capacity;
        Edge* rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {}
    };
    int n;
    int source, sink;
    vector<vector<Edge*>> graph;
    vector<bool> check;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
    }
    void add_edge(int u, int v, int cap) {
        Edge* ori = new Edge(v, cap);
        Edge* rev = new Edge(u, 0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    int dfs(int x, int c) {
        if (check[x]) return 0;
        check[x] = true;
        if (x==sink) return c;
        for (auto& next : graph[x]) {
            if (next->capacity > 0) {
                int nc = next->capacity;
                if (c!=0 && c<nc) {
                    nc = c;
                }
                int f = dfs(next->to, nc);
                if (f) {
                    next->capacity -= f;
                    next->rev->capacity += f;
                    return f;
                }
            }
        }
        return 0;
    }
    int flow() {
        int ans = 0;
        while (true) {
            fill(check.begin(), check.end(), false);
            int f = dfs(source, 0);
            if (f==0) break;
            ans += f;
        }
        return ans;
    }
};

int main()
{
    // n = number of edges
    int n; scanf("%d\n", &n);
    
    // declare and initialize MF instance
    MaximumFlow mf(max_number_of_nodes, source, sink);
    
    // get input and add graph edges
    while (n--) {
        int a, b, cap;
        scanf("%d %d %d\n", &a, &b, &cap);
        mf.add_edge(u, v, cap);
        mf.add_edge(v, u, cap);
    }
    
    // calculate maximum flow from source to sink
    // time complexity is O(fE), where f is the number of DFS's performed and E is the number of graph edges
    cout << mf.flow() << '\n';
    
    return 0;
}
