#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int k;
    int findK(TreeNode *root) {
        if(root!=NULL) {
            int val = findK(root->left);
            if(k==0) {
                return val;
            }
            k--;
            if(k==0) {
                return root->val;
            }
            val = findK(root->right);
            if(k==0) {
                return val;
            }
        }
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        return findK(root);
    }
};