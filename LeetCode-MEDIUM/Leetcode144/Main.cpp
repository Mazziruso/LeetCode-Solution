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
    vector<int> res;
    void Preorder(TreeNode *root) {
        if(root!=NULL) {
            res.push_back(root->val);
            Preorder(root->left);
            Preorder(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        Preorder(root);
        return res;
    }
};