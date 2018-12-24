#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
	vector<bool> visit;
	vector<double> tmpProd;
	unordered_map<string, int> stid;
	vector<vector<pair<int, double>>> graph;
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		graph = vector < vector<pair<int, double>>>(2 * values.size());
		unordered_map<string, int>::iterator iter;
		int id = 0;
		int sid, eid;
		for (int i = 0; i < equations.size(); i++) {
			iter = stid.find(equations[i].first);
			if (iter == stid.end()) {
				sid = id;
				stid[equations[i].first] = id++;
			}
			else {
				sid = iter->second;
			}
			iter = stid.find(equations[i].second);
			if (iter == stid.end()) {
				eid = id;
				stid[equations[i].second] = id++;
			}
			else {
				eid = iter->second;
			}
			graph[sid].push_back(pair<int, double>(eid, values[i]));
			if (values[i] > 0.0001 || values[i] < -0.0001) {
				graph[eid].push_back(pair<int, double>(sid, 1 / values[i])); //valuesi]=0.0
			}
		}

		vector<double> ret;
		visit = vector<bool>(id, false);
		tmpProd = vector<double>(id, 1.0);
		for (auto query : queries) {
			iter = stid.find(query.first);
			if (iter == stid.end()) {
				ret.push_back(-1.0);
				continue;
			}
			else {
				sid = iter->second;
			}
			iter = stid.find(query.second);
			if (iter == stid.end()) {
				ret.push_back(-1.0);
				continue;
			}
			else {
				eid = iter->second;
			}

			if (sid == eid) {
				ret.push_back(1.0);
			}
			else {
				ret.push_back(BFSEval(sid, eid, id));
			}
		}
		return ret;
	}

	double BFSEval(int s, int e, int N) {
		//init
		fill_n(visit.begin(), N, false);
		int node;

		queue<int> q;
		q.push(s);
		visit[s] = true;
		tmpProd[s] = 1.0;
		while (!q.empty()) {
			node = q.front();
			q.pop();
			if (node == e) {
				break;
			}
			for (auto i : graph[node]) {
				if (!visit[i.first]) {
					tmpProd[i.first] = tmpProd[node] * i.second;
					q.push(i.first);
					visit[i.first] = true;
				}
			}
		}
		return visit[e] ? tmpProd[e] : -1.0;
	}
};

int main() {

	vector<pair<string, string>> equations;
	vector<double> values;
	vector<pair<string, string>> queries;

	equations.push_back(make_pair("a", "b"));
	equations.push_back(make_pair("b", "c"));
	values.push_back(2.0);
	values.push_back(3.0);
	queries.push_back(make_pair("a", "c"));
	queries.push_back(make_pair("b", "a"));
	queries.push_back(make_pair("a", "e"));
	queries.push_back(make_pair("a", "a"));
	queries.push_back(make_pair("x", "x"));

	Solution s;

	vector<double> result = s.calcEquation(equations, values, queries);

	for (auto res : result) {
		cout << res << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}