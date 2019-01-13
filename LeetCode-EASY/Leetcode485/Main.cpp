#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int N;
	vector<int> colors;
	bool isBipartite(vector<vector<int>> &graph) {
		N = graph.size();
		colors.resize(N, 0);
		for (int i = 0; i < N; i++) {
			if (colors[i] == 0 && DFS(i,1,graph) == false) {
				return false;
			}
		}
		return true;
	}
	bool DFS(int node, int color, vector<vector<int>> &graph) {
		colors[node] = color;
		for (auto i : graph[node]) {
			if (colors[i] == 0 && DFS(i, 3 - color, graph) == false) {
				return false;
			}
			else if (colors[i] == color) {
				return false;
			}
		}
		return true;
	}
	bool BFS(int s, int color, vector<vector<int>> &graph) {
		queue<int> q;
		int node;
		colors[s] = color;
		q.push(s);
		while (!q.empty()) {
			node = q.front();
			q.pop();
			for (auto i : graph[node]) {
				if (colors[i] == 0) {
					colors[i] = 3 - colors[node];
					q.push(i);
				}
				else if (colors[i] == colors[node]) {
					return false;
				}
			}
		}
		return true;
	}
};
