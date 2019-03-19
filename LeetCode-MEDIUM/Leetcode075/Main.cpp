#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
       vector<int> counts(3,0);
       for(int i : nums) {
           counts[i]++;
       }
       int index=nums.size()-1;
       for(int i=2; i>=0; i--) {
           while(counts[i]--) {
               nums[index--] = i;
           }
       } 
    }
};

class Solution_1 {
public:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        int lt=-1;
        int et=-1;
        for(int i=0; i<n; i++) {
            if(nums[i]<1) {
                et++;
                swap(nums[et], nums[i]);
                lt++;
                swap(nums[lt], nums[et]);
            } else if(nums[i]==1) {
                et++;
                swap(nums[et], nums[i]);
            }
        }
    }
};

int main() {

    vector<int> nums({2,0,2,1,1,0});

    Solution_1().sortColors(nums);

    for(int i : nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}