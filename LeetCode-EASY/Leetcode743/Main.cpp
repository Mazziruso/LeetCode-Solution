#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct node {
	int id;
	int dist;
	node() : id(0), dist(0) {};
	node(int i, int d) : id(i), dist(d) {};
	bool operator<(const node n) const {
		return this->dist > n.dist;
	}
};

class Solution {
public:
	vector<vector<node>> graph;
	vector<int> dist;
	vector<bool> visit;
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		graph.resize(N + 1);
		dist.resize(N + 1, INT_MAX);
		visit.resize(N + 1, false);
		for (auto edge : times) {
			graph[edge[0]].push_back(node(edge[1], edge[2]));
		}
		return dijkstra(K);
	}

	int dijkstra(int s) {
		priority_queue<node> q;
		node nod;
		dist[s] = 0;
		q.push(node(s, 0));

		int maxDist;
		while (!q.empty()) {
			nod = q.top();
			q.pop();
			if (visit[nod.id]) {
				continue;
			}
			maxDist = dist[nod.id];
			visit[nod.id] = true;
			for (auto n : graph[nod.id]) {
				if (!visit[n.id] && (dist[n.id] > dist[nod.id] + n.dist)) {
					dist[n.id] = dist[nod.id] + n.dist;
					q.push(node(n.id, dist[n.id]));
				}
			}
		}
		return maxDist;
	}
};

int main() {
	vector<vector<int>> times;
	vector<int> e;
	e.push_back(2);
	e.push_back(1);
	e.push_back(1);
	times.push_back(e);
	e[0] = 2;
	e[1] = 3;
	e[2] = 1;
	times.push_back(e);
	e[0] = 3;
	e[1] = 4;
	e[2] = 1;
	times.push_back(e);
	Solution s;
	printf("%d\n", s.networkDelayTime(times, 4, 2));
	system("pause");
	return 0;
}