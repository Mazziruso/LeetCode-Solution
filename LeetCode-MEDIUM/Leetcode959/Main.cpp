#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
	int N;
	vector<vector<bool>> graph;

	void DFS(pair<int, int> s) {
		graph[s.first][s.second] = false;
		//left
		if (s.first > 0 && graph[s.first - 1][s.second]) {
			DFS(pair<int, int>(s.first - 1, s.second));
		}
		//right
		if (s.first < N - 1 && graph[s.first + 1][s.second]) {
			DFS(pair<int, int>(s.first + 1, s.second));
		}
		//up
		if (s.second > 0 && graph[s.first][s.second - 1]) {
			DFS(pair<int, int>(s.first, s.second - 1));
		}
		//down
		if (s.second < N - 1 && graph[s.first][s.second + 1]) {
			DFS(pair<int, int>(s.first, s.second + 1));
		}
	}

	void BFS(pair<int, int> s) {
		queue<pair<int, int>> q;
		pair<int, int> node;
		q.push(s);
		graph[s.first][s.second] = false;
		while (!q.empty()) {
			node = q.front();
			q.pop();
			// left
			if (node.first > 0 && graph[node.first - 1][node.second]) {
				q.push(pair<int, int>(node.first - 1, node.second));
				graph[node.first - 1][node.second] = false;
			}
			//right
			if (node.first < N - 1 && graph[node.first + 1][node.second]) {
				q.push(pair<int, int>(node.first + 1, node.second));
				graph[node.first + 1][node.second] = false;
			}
			//up
			if (node.second > 0 && graph[node.first][node.second - 1]) {
				q.push(pair<int, int>(node.first, node.second - 1));
				graph[node.first][node.second - 1] = false;
			}
			//down
			if (node.second < N - 1 && graph[node.first][node.second + 1]) {
				q.push(pair<int, int>(node.first, node.second + 1));
				graph[node.first][node.second + 1] = false;
			}
		}
	}

	int regionsBySlashes(vector<string> &grid) {
		int len = grid.size();
		N = 3 * len;
		graph.resize(N, vector<bool>(N, true));
		int tmp1, tmp2;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				tmp1 = 3 * i;
				tmp2 = 3 * j;
				if (grid[i][j] == '/') {
					graph[tmp1][tmp2 + 2] = false;
					graph[tmp1 + 1][tmp2 + 1] = false;
					graph[tmp1 + 2][tmp2] = false;
				}
				else if (grid[i][j] == '\\') {
					graph[tmp1][tmp2] = false;
					graph[tmp1 + 1][tmp2 + 1] = false;
					graph[tmp1 + 2][tmp2 + 2] = false;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j]) {
					cnt++;
					DFS(pair<int, int>(i, j));
				}
			}
		}
		return cnt;
	}
};

//以边为索引，利用并查集来合并可以互通的边
class Solution1 {
public:
	int count;
	int N;
	vector<int> parent;
	int regionsBySlashes(vector<string> &grid) {
		N = grid.size();
		count = N * N * 4; // the number of edges
		for (int i = 0; i < count; i++) {
			parent.push_back(i);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i > 0) {
					unionSet(g(i - 1, j, 2), g(i, j, 0));
				}
				if (j > 0) {
					unionSet(g(i, j - 1, 1), g(i, j, 3));
				}
				if (grid[i][j] != '/') {
					unionSet(g(i, j, 0), g(i, j, 1));
					unionSet(g(i, j, 2), g(i, j, 3));
				}
				if (grid[i][j] != '\\') {
					unionSet(g(i, j, 0), g(i, j, 3));
					unionSet(g(i, j, 1), g(i, j, 2));
				}
			}
		}
		return count;
	}
	int find(int x) {
		if (x == parent[x]) {
			return x;
		}
		parent[x] = find(parent[x]);
		return parent[x];
	}
	void unionSet(int s, int e) {
		int a = find(s);
		int b = find(e);
		if (a != b) {
			parent[a] = b;
			count--;
		}
	}
	//将当前点(i, j)前进的方向转换为边id, k=0代表向上, k=1代表向右, k=2代表向下, k=3代表向左
	int g(int i, int j, int k) {
		return (i*N +j) * 4 + k;
	}
};

int main() {

	Solution1 s;
	
	vector<string> grid;

	grid.push_back(" /");
	grid.push_back("  ");

	printf("%d\n", s.regionsBySlashes(grid));

	system("pause");
	return 0;
}