#include <iostream>
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
    bool firstVis = false;
    int maxNum;
    bool isValidBST(TreeNode* root) {
        if(root!=NULL) {
            bool flag = isValidBST(root->left);
            if(!flag) {
                return false;
            }
            if(firstVis && maxNum>=root->val) {
                return false;
            }
            maxNum = root->val;
            firstVis = true;
            flag = isValidBST(root->right);
            if(!flag) {
                return false;
            }
        }
        return true;
    }
};