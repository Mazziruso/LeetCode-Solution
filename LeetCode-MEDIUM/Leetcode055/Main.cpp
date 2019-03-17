#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int arrivePos = nums.size()-1;
        for(int i=arrivePos-1; i>=0; i--) {
            if(i+nums[i]>=arrivePos) {
                arrivePos = i;
            }
        }
        return arrivePos==0;
    }
};

int main() {

    vector<int> nums({2,2,1,0,4});

    Solution s;
    cout << s.canJump(nums) << endl;

    return 0;
}