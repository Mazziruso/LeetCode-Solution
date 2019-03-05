#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> nums;
    TreeNode* construct(int l, int r){
        if(l > r) {
            return NULL;
        }
        if(l == r) {
            return new struct TreeNode(nums[l]);
        }
        int mid = (r-l)/2 + l;
        TreeNode *node = new struct TreeNode(nums[mid]);
        node->left = construct(l, mid-1);
        node->right = construct(mid+1, r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        return construct(0, nums.size()-1);
    }
};