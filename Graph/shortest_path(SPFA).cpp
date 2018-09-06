#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;

int d[500];         // shortest distance from start node(0)
int cnt[500];       // number of changes to node i
bool check[500];    // true if node is in queue
const int inf = 1e9;
vector<pair<int, int>> graph[500];

// average O(E), worst O(VE)
void spfa(int n) {
    for (int i=1; i<n; ++i) {
        d[i] = inf;
    }
    
    queue<int> q;
    q.push(0); check[0] = true;
    while (!q.empty()) {
        int s = q.front();
        q.pop(); check[s] = false;
        for (auto& edge : graph[s]) {
            int e, c; tie(e, c) = edge;
            if (d[e] > d[s] + c) {
                d[e] = d[s] + c;
                if (!check[e]) {
                    q.push(e); check[e] = true;
                    cnt[e] += 1;
                    if (cnt[e]>=n) {    // loop exists; shortest path not defined
                        printf("-1\n");
                        exit(0);
                    }
                }
            }
        }
    }
}

int main()
{
    int n, m; scanf("%d %d", &n, &m);
    for (int i=0; i<m; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        graph[a-1].emplace_back(b-1, c);
    }
    
    spfa(n);
    
    for (int i=1; i<n; ++i) {
        if (d[i]>=inf) {
            printf("-1\n");
        } else {
            printf("%d\n", d[i]);
        }
    }
    
    return 0;
}