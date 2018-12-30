#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

//DP[i] = max{DP[i-1], DP[i-2]+nums[i]}
//DP[i]��ʾnums[0...i]���ܵõ�������߿���
//ʵ����DP[0]����û������ʱ���߿���
class Solution {
public:
	int rob(vector<int> &nums) {
		int N = nums.size();
		if (N == 0) {
			return 0;
		}
		if (N == 1) {
			return nums[0];
		}
		vector<int> DP(N + 1, 0);
		//intial
		DP[0] = 0;
		DP[1] = nums[0];
		for (int i = 1; i < N; i++) {
			DP[i + 1] = (DP[i - 1] + nums[i] > DP[i]) ? (DP[i - 1] + nums[i]) : DP[i];
		}
		return DP[N];
	}
};

int main() {


	system("pause");
	return 0;
}