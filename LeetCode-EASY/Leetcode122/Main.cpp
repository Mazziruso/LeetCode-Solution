#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int N = prices.size();
		int max_n = 0;
		int max_profit = 0;
		for (int i = 1; i < N; i++) {
			max_n = max(max_profit, max_n) + prices[i] - prices[i - 1];
			max_profit = max(max_n, max_profit);
		}
		return max_profit;
	}
};
