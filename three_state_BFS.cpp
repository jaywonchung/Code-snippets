#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int main()
{
	queue<tuple<int, int, int>> q;
	q.emplace(0, 0, 0);
	
	while (!q.empty()) {
		int dist, node, prev;
		tie(dist, node, prev) = q.front(); q.pop();
		
		//find next state
		
		q.emplace(new_dist, new_node, node);
	}
	
	return 0;
}
