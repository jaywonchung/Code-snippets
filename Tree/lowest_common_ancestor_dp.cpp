#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100001;
int depth[MAX];
int p[MAX][18];
vector<int> graph[MAX];

int lca(int u, int v) {
	//u is located deeper than v
	if (depth[u]<depth[v]) swap(u, v);
	
	//rise u until u and v are of the same depth
	int log = 1;
	while ((1<<log)<=depth[u]) log++;
	log -= 1;
	
	for (int i=log; i>=0; --i) {
		if (depth[u] - (1<<i) >= depth[v]) {
			u = p[u][i];
		}
	}
	
	if (u==v) {
		return u;
	} else {
		//rise u and v together until they are right below their lca
		for (int i=log; i>=0; --i) {
			if (p[u][i]!=0 && p[u][i]!=p[v][i]) {
				u = p[u][i];
				v = p[v][i];
			}
		}
		return p[u][0];
	}
}

int main()
{
	//input graph
	
	//bfs to fill p[][0] and depth[]
	for (int i=1; i<=n; ++i) depth[i] = -1;
	queue<int> q; q.push(1);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : graph[now]) {
			if (depth[next] == -1) {
				depth[next] = depth[now] + 1;
				p[next][0] = now;
				q.push(next);
			}
		}
	}
	
	//p[i][j] = node i's (1<<j)th ancestor
	for (int j=1; (1<<j)<n; ++j) {
		for (int i=1; i<=n; ++i) {
			if (p[i][j-1] != 0) {
				p[i][j] = p[p[i][j-1]][j-1];
			}
		}
	}
	
	printf("%d\n", lca(u, v));
	
	return 0;
}