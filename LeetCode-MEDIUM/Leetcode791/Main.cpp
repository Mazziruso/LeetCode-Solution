#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<char, int>::iterator iter;
unordered_map<char, int> ordered;

bool cmp(char &c1, char &c2) {
	iter = ordered.find(c1);
	int ind1 = (iter == ordered.end()) ? 0 : iter->second;
	iter = ordered.find(c2);
	int ind2 = (iter == ordered.end()) ? 0 : iter->second;
	return ind1 < ind2;
}

class Solution {
public:
	string customSortString(string S, string T) {
		for (int i = 0; i < S.length(); i++) {
			ordered[S[i]] = i + 1;
		}
		sort(T.begin(), T.end(), cmp);
		return T;
	}
};

//利用计数排序思想，统计出T中各个字符的个数存于counts，在S中遍历输出每个字符并查询counts
class Solution1 {
public:
	vector<int> counts;
	string customSortString(string S, string T) {
		counts.resize(26, 0);
		for (auto c : T) {
			counts[c - 'a']++;
		}
		string res;
		for (auto c : S) {
			res.append(counts[c - 'a'], c);
			counts[c - 'a'] = 0;
		}
		for (int i = 0; i < 26; i++) {
			res.append(counts[i], char(i + 'a'));
		}
		return res;
	}
};

int main() {

	Solution1 s;
	cout << s.customSortString("cba", "abcd") << endl;

	system("pause");
	return 0;
}
