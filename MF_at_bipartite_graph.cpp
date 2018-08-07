#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct MaximumFlow {
    int n;
    vector<vector<int>> graph;
    vector<bool> check;
    vector<int> pred;
    MaximumFlow(int n) : n(n) {
        graph.resize(n);
        check.resize(n);
        pred.resize(n, -1);
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
    int flow() {
        int ans = 0;
        for (int i=0; i<n; ++i) {   // assume "source to left vertex edge" capacity is 1
            fill(check.begin(), check.end(), false);
            if (dfs(i)) ans++;
        }
        return ans;
    }
};

int main()
{
    // n = number of vertexes on left side
    // m = number of vertexes on right side
    int n, m; scanf("%d %d", &n, &m);
    
    MaximumFlow mf(max(n, m));
    
    for (int from=0; from<n; ++from) {
        int num; scanf("%d", &num);
        while (num--) {
            int to; scanf("%d", &to);   // assume 0 <= to < m
            mf.add_edge(from, to);
        }
    }
    
    // calculate maximum number of matches
    cout << mf.flow() << '\n';
    
    return 0;
}
