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
    void Inorder(TreeNode *root) {
        if(root!=NULL) {
            Inorder(root->left);
            res.push_back(root->val);
            Inorder(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        Inorder(root);
        return res;
    }
};