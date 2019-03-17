#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> &nums;

    int binarySearch(int l, int r, int key) {
        int mid;
        while(l<r) {
            mid = (r-l)/2+l;
            if(nums[mid]>=nums[l]) {
                if(key>nums[mid] || key<nums[l]) {
                    l = mid+1;
                } else {
                    r = mid;
                }
            } else {
                if(key>nums[mid] && key>=nums[l]) {
                    r = mid - 1;
                } else if(key>nums[mid] && key<nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
        }
        return l;
    }

    int search(vector<int>& nums, int target) {
        if(nums.size()==0) {
            return -1;
        }
        this->nums = nums;
        int index = binarySearch(0, nums.size()-1, target);
        return nums[index]==target ? index : -1;
    }
};