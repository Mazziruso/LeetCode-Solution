#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3) {
			return 0;
		}
		int dp = 0;
		int diff = A[1] - A[0];
		int len = 2;
		for (int i = 2; i < A.size(); i++) {
			if (diff == A[i] - A[i - 1]) {
				dp += len - 1;
				len++;
			}
			else {
				diff = A[i] - A[i - 1];
				len = 2;
			}
		}
		return dp;
	}
};