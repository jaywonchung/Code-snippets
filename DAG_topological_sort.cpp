#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int indegree[32001];
vector<int> graph[32001];   // adjacency list

int main()
{
    // nodes numbered 1 to n
    // m = number of edges
    int n, m; scanf("%d %d", &n, &m);
    for (int i=0; i<m; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        indegree[b] += 1;
    }
    
    queue<int> q;
    for (int i=1; i<=n; ++i) {
        if (indegree[i]==0) {
            q.push(i);
        }
    }
    
    for (int k=0; k<n; ++k) {
        int x = q.front(); q.pop();
        printf("%d ", x);
        for (int y : graph[x]) {
            indegree[y] -= 1;
            if (indegree[y]==0) {
                q.push(y);
            }
        }
    }
    
    return 0;
}