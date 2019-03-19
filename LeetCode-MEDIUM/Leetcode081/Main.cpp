#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> &nums, int l, int r, int k) {
        int mid;

        while(l<r) {
            mid = l+(r-l)/2;
            if(nums[mid]>nums[l]) {
                if(k>=nums[l] && k<=nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else if(nums[mid]<nums[l]) {
                if(k<nums[l] && k>nums[mid]) {
                    l = mid + 1;
                } else if(k<nums[l] && k<=nums[mid]) {
                    r = mid;
                } else {
                    r = mid - 1;
                }
            } else {
                l++;
            }
        }
        return l;
    }
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return false;
        }
        return nums[binarySearch(nums, 0, nums.size()-1, target)]==target;
    }
};

int main() {

    vector<int> nums = {1,3,1,1,1};

    cout << Solution().search(nums, 3) << endl;

    return 0;
}