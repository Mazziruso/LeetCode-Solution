#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	unordered_map<int, int> numSet;
	vector<vector<int>> dupNums;
	vector<int> nDupNums;
	unordered_map<int, int>::iterator iter;
	vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		vector<int> vec(3, 0);
		vector<vector<int>> res;
		vector<int> tmp(2, 0);
		//去重
		for (int i = 0; i < len; i++) {
			if ((iter = numSet.find(nums[i])) != numSet.end()) {
				numSet[nums[i]] = iter->second + 1;
			}
			else {
				numSet[nums[i]] = 1;
				nDupNums.push_back(nums[i]);
			}
		}
		for (iter = numSet.begin(); iter != numSet.end(); ++iter) {
			if (iter->second > 1) {
				tmp[0] = iter->first;
				tmp[1] = iter->second;
				dupNums.push_back(tmp);
			}
		}
		//construcr numSet
		len = nDupNums.size();
		numSet.clear();
		for (int i = 0; i < len; i++) {
			numSet[nDupNums[i]] = i;
		}
		//duplicate number
		int temp;
		for (int i = 0; i < dupNums.size(); i++) {
			if (dupNums[i][1] >= 3 && dupNums[i][0] == 0) {
				res.push_back(vector<int>(3, 0));
			}
			if (dupNums[i][1] >= 2 && dupNums[i][0] != 0) {
				temp = -2 * dupNums[i][0];
				if (numSet.find(temp) != numSet.end()) {
					vec[0] = dupNums[i][0];
					vec[1] = dupNums[i][0];
					vec[2] = temp;
					res.push_back(vec);
				}
			}
		}
		//non-duplicate number
		for (int i = 0; i < len - 2; i++) {
			for (int j = i + 1; j < len - 1; j++) {
				temp = -nDupNums[i] - nDupNums[j];
				if ((iter = numSet.find(temp)) != numSet.end() && iter->second > j) {
					vec[0] = nDupNums[i];
					vec[1] = nDupNums[j];
					vec[2] = temp;
					res.push_back(vec);
				}
			}
		}
		return res;
	}
};
