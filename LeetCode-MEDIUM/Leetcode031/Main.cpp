#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bsearch(vector<int> &nums,int s, int e, int k) {
        int l = s; 
        int r = e;
        int mid;
        while(l<r) {
            mid = r-(r-l)/2;
            if(nums[mid]<=k) {
                r = mid-1;
            } else {
                l = mid;
            }
        }
        return r;
    }
    void nextPermutation(vector<int>& nums) {
        int index = nums.size()-2;
        while(index>=0 && nums[index]>=nums[index+1]) {
            index--;
        } 
        int l = index+1;
        int r = nums.size()-1;
        if(index>=0) {
            swap(nums[index], nums[bsearch(nums, l, r, nums[index])]);
        }
        while(l<r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};