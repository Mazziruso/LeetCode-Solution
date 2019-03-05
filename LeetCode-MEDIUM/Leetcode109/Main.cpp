#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        for(ListNode *node=head; node!=NULL; node=node->next) {
            this->nums.push_back(node->val);
        }
        return construct(0, nums.size()-1);
    }
};