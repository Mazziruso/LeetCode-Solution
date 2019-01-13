#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

/*
dp[i][j]代表i时刻买进->j时刻卖出的一个交易内联合i时刻之前的所有交易，所能获得的最大利润
max_n[i]代表在i时刻卖出股票的所有之前联合交易中，获得的最大利润
max_profit代表到当前i时刻为止，所有联合交易中获得的最大利润
递推式: dp[i][j] = dp[i][j-1]+prices[j]-prices[j-1], j>i
           dp[i][j] = max_profit - fee, j==i
		   max_n[j] = (dp[i][j]>max_n[j]) ? dp[i][j]
		   max_profit = (max_n[i]>max_profi) ? max_n[i]
*/

//space complexity: O(N^2)
//time complexity: O(N^2)
class Solution {
public:
	vector<vector<int>> dp;
	vector<int> max_n;
	int maxProfit(vector<int>& prices, int fee) {
		int N = prices.size();
		max_n.resize(N, 0);
		int max_profit = 0;
		dp.resize(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			dp[i][i] = (i == 0) ? -fee : max_profit - fee;
			for (int j = i + 1; j < N; j++) {
				dp[i][j] = dp[i][j - 1] + prices[j] - prices[j - 1];
				max_n[j] = (dp[i][j] > max_n[j]) ? dp[i][j] : max_n[j];
			}
			max_profit = (max_n[i] > max_profit) ? max_n[i] : max_profit;
		}
		return max_profit;
	}
};

//space complexity: O(N)
//time complexity: O(N^2)
class Solution1 {
public:
	vector<int> dp;
	vector<int> max_n;
	int maxProfit(vector<int>& prices, int fee) {
		int N = prices.size();
		max_n.resize(N, 0);
		int max_profit = 0;
		dp.resize(N, 0);
		for (int i = 0; i < N; i++) {
			dp[i] = (i == 0) ? -fee : max_profit - fee;
			for (int j = i + 1; j < N; j++) {
				dp[j] = dp[j - 1] + prices[j] - prices[j - 1];
				max_n[j] = (dp[j] > max_n[j]) ? dp[j] : max_n[j];
			}
			max_profit = (max_n[i] > max_profit) ? max_n[i] : max_profit;
		}
		return max_profit;
	}
};


/*
max_n[i]代表在i时刻卖出股票的所有之前联合交易中，获得的最大利润
max_profit代表到当前i时刻为止，所有联合交易中获得的最大利润，（并且要求之后还要有交易，因为在交易开始前已经减去交易费）
递推式: max_n[i]=max(max_n[i-1], max_profit) + prices[j] - price[j-1] //若选择max_profit代表重新开始一笔交易，选择max_n[i]代表原来交易不是最优的
		   max_profit = max(max_n[i]-fee, max_profit)
*/

// space complexity: O(N)
// time complexity: O(N)
class Solution2 {
public:
	vector<int> max_n;
	int maxProfit(vector<int>& prices, int fee) {
		int N = prices.size();
		max_n.resize(N, 0);
		max_n[0] = -fee;
		int max_profit = -fee;
		for (int i = 1; i < N; i++) {
			max_n[i] = max(max_profit, max_n[i - 1]) +prices[i] - prices[i - 1];
			max_profit = max(max_n[i] - fee, max_profit);
		}
		max_n[0] = 0;
		return max_profit + fee;
	}
};

// space complexity: O(1)
// time complexity: O(N)
class Solution3 {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int N = prices.size();
		int max_n = -fee;
		int max_profit = -fee;
		for (int i = 1; i < N; i++) {
			max_n = max(max_profit, max_n) + prices[i] - prices[i - 1];
			max_profit = max(max_n - fee, max_profit);
		}
		return max_profit + fee;
	}
};

int main() {

	int myints[] = { 1,3,2,8,4};
	int fee = 2;
	vector<int> myV(myints, myints+sizeof(myints)/sizeof(int));

	Solution3 s;

	cout << s.maxProfit(myV, fee) << endl;

	system("pause");
	return 0;
}