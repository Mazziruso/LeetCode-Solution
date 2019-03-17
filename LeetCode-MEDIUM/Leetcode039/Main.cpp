#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nums;
    vector<int> path;
    vector<vector<int>> res;
    int target;
    int len;

    void DFS(int index, int sum) {
        if(index>=len || sum > target) {
            return;
        }
        if(sum == target) {
            path.push_back(nums[index]);
            res.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(nums[index]);
        for(int i=index; i<len; i++) {
            if(sum+nums[i]>target) {
                break;
            }
            DFS(i, sum+nums[i]);
        }
        path.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->nums = candidates;
        this->target = target;
        this->len = candidates.size();
        
        if(this->len==0) {
            return res;
        }

        sort(nums.begin(), nums.end(), less<int>());

        for(int i=0; i<this->len; i++) {
            DFS(i, nums[i]);
        }

        return res;
    }
};