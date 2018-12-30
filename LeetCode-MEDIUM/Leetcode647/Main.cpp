#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int N = s.length();

		if (N == 0) {
			return 0;
		}

		vector<vector<int>> DP(N, vector<int>(N, 1));
		int cnt = DP[0][0];
		for (int j = 1; j < N; j++) {
			cnt += DP[j][j];
			for (int i = j - 1; i >= 0; i--) {
				DP[i][j] = (s[i] == s[j]) ? DP[i + 1][j - 1] : 0;
				cnt += DP[i][j];
			}
		}
		return cnt;
	}
};

//Manacher Algorithm
class Solution1 {
public:
	int countSubstrings(string s) {
		string str = "|";
		for (int i = 0; i < s.size(); i++) {
			str += s[i];
			str += "|";
		}
		int N = str.size();
		int mx = 0;
		int ct = 0;
		int cnt = s.size();
		vector<int> LPS(N, 0);
		for (int i = 0; i < N; i++) {
			LPS[i] = (mx > i) ? min(mx - i, LPS[2 * ct - i]) : 1;
			while (i - LPS[i] >= 0 && i + LPS[i] < N && str[i - LPS[i]] == str[i + LPS[i]]) {
				LPS[i]++;
			}
			if (mx > i + LPS[i]) {
				mx = i + LPS[i];
				ct = i;
			}
			cnt += (LPS[i] - 1) / 2; //palindrome radius
		}
		return cnt;
	}
};

int main() {

	Solution1 s;
	printf("%d\n", s.countSubstrings(""));

	system("pause");
	return 0;
}