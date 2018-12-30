#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int> &nums) {
		int maxSum = INT_MIN;
		int DP = INT_MIN;
		int N = nums.size();
		for (int i = 0; i < N; i++) {
			DP = (DP < 0) ? nums[i] : (DP + nums[i]);
			maxSum = (DP > maxSum) ? DP : maxSum;
		}
		return maxSum;
	}
};

int main() {

	int myints[] = { -2,1,-3,4,-1,2,1,-5,4 };

	Solution s;
	vector<int> d(myints, myints + 9);
	printf("%d\n", s.maxSubArray(d));

	system("pause");
	return 0;
}