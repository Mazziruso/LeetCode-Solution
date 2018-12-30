#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

//先手必赢
class Solution {
public:
	bool stoneGame(vector<int> &piles) {
		return true;
	}
};

//DP
/*
DP[i][j] = max{piles[i] - DP[i+1][j], piles[j]-DP[i][j-1]}
DP[i][j]表示在piles[i...j]中，Alex获得的超过Lee的最大石头数
*/
class Solution1 {
public:
	bool stoneGame(vector<int> &piles) {
		int len = piles.size();
		vector<vector<int>> DP;
		for (int i = 0; i < len; i++) {
			DP.push_back(vector<int>(len, 0));
			DP[i][i] = piles[i];
		}
		for (int dist = 1; dist < len; dist++) {
			for (int i = 0; i < len - dist; i++) {
				DP[i][i + dist] = max(piles[i] - DP[i + 1][i + dist], piles[i + dist] - DP[i][i + dist - 1]);
			}
		}
		return DP[0][len - 1] > 0;
	}
};

int main() {
	int myints[] = { 1,3,1,3,4,1 };
	vector<int> piles(myints, myints + 6);
	Solution1 s;
	printf("%s\n", s.stoneGame(piles) ? "true" : "false");
	system("pause");
	return 0;
}