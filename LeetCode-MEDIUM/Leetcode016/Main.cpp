#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();

        if(len<3) {
            return 0;
        }

        sort(nums.begin(), nums.end(), less<int>());

        int closet;
        int sum = nums[0] + nums[1] + nums[2];
        int l,r;

        for(int i=0; i<len-2; i++) {
            l = i + 1;
            r = len - 1;
            while(l<r){
                closet = nums[i] + nums[l] + nums[r];
                if(closet>target) {
                    r--;
                } else {
                    l++;
                }
                sum = abs(closet-target)>abs(sum-target) ? sum : closet;
            }
        }
        return sum;
    }
};
