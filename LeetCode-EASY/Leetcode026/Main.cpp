#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int len = nums.size();
        for(int i=0; i<len; i++) {
            while(i<(len-1) && nums[i]==nums[i+1]) {
                i++;
            }
            swap(nums[i], nums[index]);
            index++;
        }
        return index;
    }
};