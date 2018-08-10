#include <cstdio>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int dist[20001];    // minimum distance from start node
bool check[20001];
const int inf = 1e9;
vector<pair<int, int>> graph[20001];    // adjacency list

void dijkstra(int n, int start) {
    for (int i=1; i<=n; ++i) {
        dist[i] = inf;
    }
    
    dist[start] = 0;
    priority_queue<pair<int, int>> q;
    q.emplace(0, start);
    
    // O(logE)
    while (!q.empty()) {
        int x = q.top().second; q.pop();    // q.top() = node with the smallest distance
        if (check[x]) continue;
        
        for (auto next : graph[x]) {
            int y = next.first;
            if (dist[y] > dist[x] + next.second) {
                dist[y] = dist[x] + next.second;
                q.emplace(-dist[y], y);
            }
        }
    }
}

int main()
{
    // n vertexes and m edges
    // nodes indexed from 1 to n
    int n, m, start; scanf("%d %d %d", &n, &m, &start);
    for (int i=0; i<m; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        graph[u].emplace_back(v, w);
    }
    
    dijkstra(n, start);
    
    return 0;
}