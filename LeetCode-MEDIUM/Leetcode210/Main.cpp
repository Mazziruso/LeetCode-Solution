#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct vertex {
	int id;
	int time;
	vertex() : id(0), time(0) {};
	bool operator<(struct vertex &v) {
		return this->time > v.time;
	}
};

/*
�������򣬲����������
DFS���ÿ������finish time
����finish time������Ϊ���
*/
class Solution {
public:
	int N;
	int time;
	vector<vertex> finish;
	vector<vector<int>> graph;
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		N = numCourses;
		graph.resize(N, vector<int>());
		for (auto n : prerequisites) {
			graph[n.second].push_back(n.first);
		}
		finish.resize(N, vertex());
		time = 1;
		for (int i = 0; i < N; i++) {
			finish[i].id = i;
			if (finish[i].time == 0 && !DFS(i)) {
				return vector<int>();
			}
		}
		sort(finish.begin(), finish.end());
		vector<int> res;
		for (int i = 0; i < N; i++) {
			res.push_back(finish[i].id);
		}
		return res;
	}
	bool DFS(int node) {
		finish[node].time = -1; //����visiting
		for (auto i : graph[node]) {
			if (finish[i].time == 0 && !DFS(i)) {
				return false;
			}
			else if (finish[i].time == -1) {
				return false;
			}
		}
		finish[node].time = time++; //����visited
		return true;
	}
};
