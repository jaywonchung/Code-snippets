#include <iostream>
#include <vector>
using namespace std;

struct MaximumFlow
{
    int n;
    vector<vector<int>> graph;
    vector<bool> check;
    vector<int> pred;
    MaximumFlow(int n) : n(n) {
        graph.resize(n);
        check.resize(n);
        pred.resize(n, -1); // if (pred[x]==-1) forward and never used. 
                            // else backwards and pointing pred[x]
    }
    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }
    bool dfs(int x) {
        if (x==-1) return true;
        for (int next : graph[x]) {
            if (check[next]) continue;
            check[next] = true;
            if (dfs(pred[next])) {
                pred[next] = x;
                return true;
            }
        }
        return false;
    }
    // all edge capacities are 1; just iterate through all source side vertexes once
    int flow() {
        int ans = 0;
        for (int i=0; i<n; ++i) {
            fill(check.begin(), check.end(), false);
            if (dfs(i)) ans += 1;
        }
        return ans;
    }
};

int main()
{
    // n = max number of nodes on each side, k = number of edges
    int n, k; scanf("%d %d", &n, &k);
    
    MaximumFlow mf(n);
    for (int i=0; i<k; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        mf.add_edge(a, b);
    }
    
    cout << mf.flow() << '\n';
    
    return 0;
}