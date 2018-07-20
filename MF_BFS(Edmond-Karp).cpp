#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct MaximumFlow
{
    struct Edge
    {
        int to, capacity;
        Edge* rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {}
    };
    int n;
    int source, sink;
    vector<vector<Edge*>> graph;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
    }
    void add_edge(int u, int v, int cap) {
        Edge* ori = new Edge(v, cap);
        Edge* rev = new Edge(u, 0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    int bfs() {
        vector<bool> check(n, false);
        vector<pair<int, int>> from(n, {-1, -1});
        queue<int> q; q.push(source);
        check[source] = true;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i=0; i<graph[x].size(); ++i) {
                if (graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {
                    q.push(graph[x][i]->to);
                    check[graph[x][i]->to] = true;
                    from[graph[x][i]->to] = {x, i};
                }
            }
        }
        if (!check[sink]) return 0;
        int x = sink;
        int c = graph[from[x].first][from[x].second]->capacity;
        while (from[x].first!=-1) {
            if (c > graph[from[x].first][from[x].second]->capacity) {
                c = graph[from[x].first][from[x].second]->capacity;
            }
            x = from[x].first;
        }
        x = sink;
        while (from[x].first!=-1) {
            Edge* e = graph[from[x].first][from[x].second];
            e->capacity -= c;
            e->rev->capacity += c;
            x = from[x].first;
        }
        return c;
    }
    int flow() {
        int ans = 0;
        while (true) {
            int f = bfs();
            if (f==0) break;
            ans += f;
        }
        return ans;
    }
};

int node(char c) {
    if (c>='A' && c<='Z') {
        return c-'A';
    } else {
        return c-'a'+26;
    }
}

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
    // time complexity is O(E)*VE = O(VE^2), where V is the number of vertexes and E is the number of edges
    cout << mf.flow() << '\n';
    
    return 0;
}