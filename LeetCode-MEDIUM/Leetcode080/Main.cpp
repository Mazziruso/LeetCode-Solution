#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int ptr=-1;
        int index=0;
        int cnt;
        while(index<n) {
            cnt=1;
            while(index<n-1 && nums[index]==nums[index+1]) {
                index++;
                cnt++;
            }
            if(cnt>=2) {
                nums[++ptr] = nums[index];
                nums[++ptr] = nums[index];
            } else {
                nums[++ptr] = nums[index];
            }
            index++;
        }
        return ptr+1;
    }
};

int main() {

    vector<int> nums({0,0,0,0,0,1,1,1,1});

    int len = Solution().removeDuplicates(nums);

    cout << len << endl;

    for(int i=0; i<len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}