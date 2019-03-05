#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        int maxVal = max(p->val, q->val);
        int minVal = min(p->val, q->val);
        if(root->val>maxVal) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val<minVal) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};