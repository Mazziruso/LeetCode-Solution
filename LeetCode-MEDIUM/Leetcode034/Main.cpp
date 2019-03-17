#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nums;

    int binarySearch(int s, int e, int k) {
        int l = s;
        int r = e;
        int mid;
        while(l < r) {
            mid = (r-l)/2+l;
            if(nums[mid]<k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) {
            return vector<int>{-1,-1};
        }
        this->nums = nums;
        int l = binarySearch(0, nums.size()-1, target);
        int r = binarySearch(0, nums.size()-1, target+1);
        if(nums[r]!=target) {
            r--;
        }
        return (l<=r) ? vector<int>{l,r} : vector<int>{-1,-1};
    }
};