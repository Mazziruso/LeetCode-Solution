#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> vec(4,0);
        vector<vector<int>> res;
        if(len < 4) {
            return res;
        }

        int i=0;
        int j=1;
        int l,r;
        int sum;

        sort(nums.begin(), nums.end());

        for(int i=0; i<len-3; i++) {
            for(int j=i+1; j<len-2; j++) {
                l = j+1;
                r = len-1;
                while(l<r) {
                    sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum==target) {
                        vec[0] = nums[i];
                        vec[1] = nums[j];
                        vec[2] = nums[l];
                        vec[3] = nums[r];
                        res.push_back(vec);
                    }
                    while(sum>=target && l<r && nums[r]==nums[r-1]) {
                        r--;
                    }
                    if(sum>=target) {
                        r--;
                    }
                    while(sum<=target && l<r && nums[l]==nums[l+1]) {
                        l++;
                    }
                    if(sum<=target) {
                        l++;
                    }
                }
                while(j<(len-1) && nums[j]==nums[j+1]) {
                    j++;
                }
            }
            while(i<(len-1) && nums[i]==nums[i+1]) {
                    i++;
            }
        }
        return res;
    }
};