#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int main()
{
	queue<tuple<int, int, int>> q;
	q.emplace(0, 0, 0);
	
	while (!q.empty()) {
		int one, two, three;
		tie(one, two, three) = q.front(); q.pop();
		
		//find next state
		
		q.emplace(new_one, new_two, new_three);
	}
	
	return 0;
}
