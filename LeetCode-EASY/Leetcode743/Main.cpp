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
	node(int i, int d) : id(i), dist(d) {};
};

class Solution {
public:
	vector<vector<node>> graph;
	vector<int> dist;
	vector<bool> visit;
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		graph.resize(N + 1);
		dist.resize(N + 1, 0);
		visit.resize(N + 1, false);
		for (auto edge : times) {
			graph[edge[0]].push_back(node(edge[1], edge[2]));
		}
	}

	void dijkstra() {

	}
};