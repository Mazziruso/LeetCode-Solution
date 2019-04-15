#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> B;
    vector<int> bucket;
    void bucketSort(vector<int> &nums, int base) {
        int len = nums.size();
        fill(bucket.begin(), bucket.end(), 0);
        for(int i=0; i<len; i++) {
            bucket[(nums[i]/base)%10]++;
        }
        for(int i=1; i<10; i++) {
            bucket[i] += bucket[i-1];
        }
        int tmp;
        for(int i=len-1; i>=0; i--) {
            tmp = (nums[i]/base)%10;
            B[bucket[tmp]-1] = nums[i];
            bucket[tmp]--;
        }
        for(int i=0; i<len; i++) {
            nums[i] = B[i];
        }
    }
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        int maxNum = -1;
        B.resize(len);
        bucket.resize(10);
        for(int i=0; i<len; i++) {
            maxNum = (maxNum<nums[i]) ? nums[i] : maxNum;
        }
        for(int base=1; maxNum/base!=0; base*=10) {
            bucketSort(nums, base);
        }
        maxNum = 0;
        for(int i=1; i<len; i++) {
            maxNum = (nums[i]-nums[i-1])>maxNum ? (nums[i]-nums[i-1]) : maxNum; 
        }
        return maxNum;
    }
};

int main() {

    vector<int> nums({3,6,9,1});

    cout << Solution().maximumGap(nums);

    return 0;
}