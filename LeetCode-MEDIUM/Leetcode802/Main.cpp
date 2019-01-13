#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int N;
	/*
	safed = 0: unkown
	safed = 1: unsafe vertex
	safed = 2: safed vertex
	*/
	vector<int> safed;
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		N = graph.size();
		safed.resize(N, 0);

		vector<int> res;
		for (int i = 0; i < N; i++) {
			if (safed[i] == 0) {
				DFS(i, graph);
			}
			if (safed[i] == 2) {
				res.push_back(i);
			}
		}
		return res;
	}
	bool DFS(int s, vector<vector<int>> &graph) {
		safed[s] = 1;
		for(auto i : graph[s]) {
			if (safed[i] == 1) {
				safed[s] = 1;
				return false;
			}
			else if (safed[i] == 0 && DFS(i, graph) == false) {
				safed[s] = 1;
				return false;
			}
		}
		safed[s] = 2;
		return true;
	}
};
