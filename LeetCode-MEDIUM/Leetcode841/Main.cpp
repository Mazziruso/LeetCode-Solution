#include <iostream>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

//���鼯�޽⣬���������л�ͼ
class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>> &rooms) {
		queue<int> q;
		int N = rooms.size();
		vector<bool> visit(N, false);
		int node = 0;
		q.push(node);
		visit[node] = true;
		while (!q.empty()) {
			node = q.front();
			q.pop();
			for (auto r : rooms[node]) {
				if (!visit[r]) {
					q.push(r);
					visit[r] = true;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (!visit[i]) {
				return false;
			}
		}
		return true;
	}
};
