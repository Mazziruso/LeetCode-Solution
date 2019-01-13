#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

/*
判断是否拓扑排序
等价于判断是否存在环
利用DFS并加上DP性质：若某个结点，从其开始往下存在环，那么此后任何能够可达此结点的其它任意结点都存在环
*/
class Solution {
public:
	int N;
	/*
	isCycle=0: unknown
	isCycle=1: exist cycle
	isCycle=2: exist no cycle
	*/
	vector<int> isCycle;
	vector<vector<int>> graph;
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		N = numCourses;
		graph.resize(N, vector<int>());
		for (auto n : prerequisites) {
			graph[n.second].push_back(n.first);
		}
		isCycle.resize(N, 0);
		for (int i = 0; i < N; i++) {
			if (isCycle[i] == 1 || (isCycle[i] == 0 && !DFS(i))) {
				return false;
			}
		}
		return true;
	}
	bool DFS(int node) {
		isCycle[node] = 1;
		for (auto i : graph[node]) {
			if (isCycle[i] == 0 && !DFS(i)) {
				return false;
			}
			else if (isCycle[i] == 1) {
				return false;
			}
		}
		isCycle[node] = 2;
		return true;
	}
};