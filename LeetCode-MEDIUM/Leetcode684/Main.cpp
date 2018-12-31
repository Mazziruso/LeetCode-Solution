#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int N;
	vector<int> parent;
	vector<int> findRedundantConnection(vector<vector<int>> &edges) {
		N = edges.size();
		for (int i = 0; i <= N; i++) {
			parent.push_back(i);
		}
		for (auto e : edges) {
			if (!uni(e[0], e[1])) {
				return e;
			}
		}
	}
	int find(int x) {
		if (x == parent[x]) {
			return x;
		}
		parent[x] = find(parent[x]);
		return parent[x];
	}
	bool uni(int x, int y) {
		int xp = find(x);
		int yp = find(y);
		if (xp != yp) {
			parent[yp] = xp;
			return true;
		}
		else {
			return false;
		}
	}
};
